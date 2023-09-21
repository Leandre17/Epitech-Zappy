/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** angles
*/

#include "server.h"

double calculate_angle(point_t a, point_t b, point_t c)
{
    double abx = b.x - a.x;
    double aby = b.y - a.y;
    double bcx = c.x - b.x;
    double bcy = c.y - b.y;
    double dot_product = (abx * bcx) + (aby * bcy);
    double magnitude_ab = sqrt(abx * abx + aby * aby);
    double magnitude_bc = sqrt(bcx * bcx + bcy * bcy);
    double angle_in_radians = acos(
        dot_product / (magnitude_ab * magnitude_bc));
    double angle_in_degrees = angle_in_radians * (180.0 / PI);
    return angle_in_degrees;
}
