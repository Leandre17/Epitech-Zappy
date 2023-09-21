/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** logs
*/

#ifndef LOGS_H_
    #define LOGS_H_

    #include "server.h"

    // Functions
        // bct.c
        void send_bct_to_all_graphics(
            server_t *server,
            int x,
            int y
        );

        // ebo.c
        void send_ebo_to_all_graphics(
            server_t *server,
            int id
        );

        // edi.c
        void send_edi_to_all_graphics(
            server_t *server,
            int id
        );

        // enw.c
        void send_enw_to_all_graphics(
            server_t *server,
            egg_t *egg
        );

        // pbc.c
        void send_pbc_to_all_graphics(
            server_t *server,
            player_t *player,
            char *message
        );

        // pdi.c
        void send_pdi_to_all_graphics(
            server_t *server,
            player_t *player
        );

        // pdr.c
        void send_pdr_to_all_graphics(
            server_t *server,
            player_t *player,
            int resource_id
        );

        // pex.c
        void send_pex_to_all_graphics(
            server_t *server,
            int player_id
        );

        // pfk.c
        void send_pfk_to_all_graphics(
            server_t *server,
            player_t *player
        );

        // pgt.c
        void send_pgt_to_all_graphics(
            server_t *server,
            player_t *player,
            int resource_id
        );

        // pic.c
        char *get_players_id_str(incantation_t *incantation);
        void send_pic_to_all_graphics(
            server_t *server,
            incantation_t *incantation
        );

        // pie.c
        void send_pie_to_all_graphics(
            server_t *server,
            incantation_t *incantation,
            bool result
        );

        // pin.c
        void send_pin_to_all_graphics(
            server_t *server,
            player_t *player
        );

        // pnw.c
        char *pnw_str(player_t *player);
        char *all_pnw_str(client_t *clients, int nb_clients);
        void send_pnw_to_all_graphics(
            server_t *server,
            player_t *player
        );

        // ppo.c
        void send_ppo_to_all_graphics(
            server_t *server,
            player_t *player
        );

#endif /* !LOGS_H_ */
