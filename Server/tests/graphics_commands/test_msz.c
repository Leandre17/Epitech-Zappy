/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** test_msz
*/

#include "tests.h"

Test(server, test_command_msz_not_graphic, .init = setup, .fini = teardown)
{
    send_command_and_check_response("msz\n", API_NOT_FOUND);
}

Test(server, test_command_msz_bad_args, .init = setup, .fini = teardown)
{
    send_command_and_check_response("GRAPHIC\n", API_SUCCESS);
    send_command_and_check_response("msz -1 -1\n", "ko\n");
}

Test(server, test_command_msz, .init = setup, .fini = teardown)
{
    send_command_and_check_response("GRAPHIC\n", API_SUCCESS);
    send_command_and_check_response("msz\n", "msz 10 10\n");
}
