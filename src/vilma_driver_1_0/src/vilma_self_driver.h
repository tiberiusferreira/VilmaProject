#ifndef VILMA_SELF_DRIVER_H
#define VILMA_SELF_DRIVER_H
#include "morse_receiver.h"
#include "morse_transmiter.h"
#include <deque>
#include "points.h"
#include <qdebug.h>
class vilma_self_driver
{
public:
    vilma_self_driver(morse_receiver *morse_receiver_obj, morse_transmiter *morse_transmiter_obj);
    morse_receiver *morse_receiver_obj;
    morse_transmiter *morse_transmiter_obj;
    int reorientate_to_pose(float x, float y);
    std::deque<one_point> generate_smooth_path(std::deque<one_point> given_points);
};

#endif // VILMA_SELF_DRIVER_H
