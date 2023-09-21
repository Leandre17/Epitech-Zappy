/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** test_tna
*/

#include "tests.h"

Test(server, test_command_tna_not_graphic, .init = setup, .fini = teardown)
{
    send_command_and_check_response("tna\n", API_NOT_FOUND);
}

Test(server, test_command_tna, .init = setup, .fini = teardown)
{
    send_command_and_check_response("GRAPHIC\n", API_SUCCESS);
    send_command_and_check_response("tna\n", "tna BLUE\ntna RED\n");
}
