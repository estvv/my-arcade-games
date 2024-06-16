# BINARY NAME
BINARY		=	my_snake
BINARY_TEST	=	unit_tests

# COMPILER
CXX	=	g++

# DIRECTORIES
INCLUDE_DIR	=	include
SRC_DIR		=	src
OBJ_DIR		=	objects
TEST_DIR	=	tests

# HEADERS
INCLUDE_FILES	=	$(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS	=	$(addprefix -I, $(INCLUDE_FILES))

# FILES
MAIN_FILE	=	$(SRC_DIR)/main.cpp
SRC_FILES	=	$(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES	=	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# CRITERION
TEST_FILES	=	$(shell find $(TEST_DIR) -name "*.cpp" -not -path $(SRC_DIR)/main.cpp)

# SUBDIRECTORIES
OBJ_SUBDIRS	=	$(sort $(dir $(OBJ_FILES)))

# FLAGS
CXXFLAGS	=	$(INCLUDE_FLAGS) -Wall -Werror -Wextra -std=c++17 -g3
LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lm
TESTSFLAGS	=	--coverage -lcriterion

all: $(BINARY)

run: all
	./$(BINARY)

$(BINARY): $(OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_SUBDIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_SUBDIRS):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(BINARY)
	$(RM) $(BINARY_TEST)

re: fclean all

tests_run: $(BINARY_TEST)
	./$(BINARY_TEST)
	gcovr --exclude tests

$(BINARY_TEST): $(TEST_FILES) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(TESTSFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: all clean fclean re
