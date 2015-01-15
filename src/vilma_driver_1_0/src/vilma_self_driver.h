#ifndef VILMA_SELF_DRIVER_H
#define VILMA_SELF_DRIVER_H
#include "morse_receiver.h"
#include "morse_transmiter.h"
#include <deque>
#include "points.h"
#include <qdebug.h>
#include <control_toolbox/pid.h>
class vilma_self_driver
{
public:
    vilma_self_driver(morse_receiver *morse_receiver_obj, morse_transmiter *morse_transmiter_obj);
    morse_receiver *morse_receiver_obj;
    morse_transmiter *morse_transmiter_obj;
    control_toolbox::Pid gasControler;
    ros::NodeHandle rosNode;
    ros::Time previous_interation_time;
    int reorientate_to_pose(float x, float y);
    int maintainSpeed(int desiredSpeed);
    std::deque<one_point> generate_smooth_path(std::deque<one_point> given_points);
};

#endif // VILMA_SELF_DRIVER_H
