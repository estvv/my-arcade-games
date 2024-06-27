# COMPILER
CXX	=	g++

# BINARY NAME
BINARY		=	my_games
BINARY_TEST	=	unit_tests

# DIRECTORIES
INCLUDE_DIR	=	include
SRC_DIR		=	src
OBJ_DIR		=	build
TEST_DIR	=	tests

# HEADERS
INCLUDE_FILES	=	$(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS	=	$(addprefix -I, $(INCLUDE_FILES))

# FILES
SRC_FILES	=	$(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES	=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# CRITERION
MAIN_FILE	=	$(SRC_DIR)/main.cpp
TEST_FILES	=	$(shell find $(TEST_DIR) -name "*.cpp" -not -path $(MAIN_FILE))

# SUBDIRECTORIES
OBJ_SUBDIRS	=	$(sort $(dir $(OBJ_FILES) $(TEST_OBJ_FILES)))

# FLAGS
CXXFLAGS	=	$(INCLUDE_FLAGS) -Wall -Werror -Wextra -W -std=c++17 -g3
LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TESTSFLAGS	=	--coverage -lcriterion

all: $(BINARY)

run: all
	./$(BINARY)

$(BINARY): $(OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(OBJ_SUBDIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_SUBDIRS):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) *.vgcore

fclean: clean
	$(RM) $(BINARY)
	$(RM) $(BINARY_TEST)

re: fclean all

tests_run: $(BINARY_TEST)
	./$(BINARY_TEST)

gcovr: tests_run
	gcovr --exclude $(TEST_DIR)

$(BINARY_TEST): $(TEST_FILES) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(TESTSFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: all clean fclean re tests_run gcovr
