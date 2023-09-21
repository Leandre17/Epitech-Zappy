/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** test_left
*/

#include "tests.h"

Test(server, test_command_left_bad_args, .init = setup, .fini = teardown)
{
    send_command_and_check_response("Left bad args\n", API_NOT_FOUND);
}

Test(server, test_command_left_no_team, .init = setup, .fini = teardown)
{
    send_command_and_check_response("Left\n", API_NOT_FOUND);
}

Test(server, test_command_left, .init = setup, .fini = teardown)
{
    identify_user_as_team(TEST_TEAM);
    send_command_and_check_response("Left\n", API_SUCCESS);
}
