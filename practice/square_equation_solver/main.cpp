#include <stdio.h>
#include <math.h>
#include <string.h>

#include "square_equation_structures.hpp"

#include "user_interface.hpp"
#include "cli.hpp"

#include "tests/all_tests.hpp"

int main(int argc, char** argv)
{
    int file_flag_index = 0;
    if (argc == 1)
    {
        return run_user_loop();
    } 
    else
    {
        if (is_flag_set(argc, argv, "-h") || is_flag_set(argc, argv, "--help"))
        {
            print_help();
            return 0;
        }
        else if ((file_flag_index = is_flag_set(argc, argv, "-f")) || (file_flag_index = is_flag_set(argc, argv, "--file")))
        {
            return run_cli_from_file(argc > file_flag_index - 1 ? argv[file_flag_index + 1] : NULL);
        }
        else if (is_flag_set(argc, argv, "-t") || is_flag_set(argc, argv, "--test"))
        {
            return run_all_tests();
        }
        else
        {
            if (argc == 4)
            {
                return run_cli_from_args(argc, argv); 
            }
            else
            {
                // Неверный формат вызова
                print_help(); 
                return 1;
            }
        }
    }
}

