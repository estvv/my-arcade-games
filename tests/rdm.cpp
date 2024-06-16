#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "all.hpp"

static void UN redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
