#ifndef VILMA_SELF_DRIVER_H
#define VILMA_SELF_DRIVER_H
#include "morse_receiver.h"
#include "morse_transmiter.h"
#include <deque>
#include "points.h"
#include <qdebug.h>
#include <control_toolbox/pid.h>
#include <thread>
#include <boost/thread.hpp>

class vilma_self_driver
{
public:
    struct my_struct{
        vilma_self_driver *obj_pointer;
        int desiredSpeed_arg;
    };
    vilma_self_driver(morse_receiver *morse_receiver_obj, morse_transmiter *morse_transmiter_obj);
    morse_receiver *morse_receiver_obj;
    morse_transmiter *morse_transmiter_obj;
    control_toolbox::Pid gasControler;
    ros::NodeHandle rosNode;
    int reorientate_to_pose(float x, float y);
    void maintainSpeed(int desiredSpeed);
    std::deque<one_point> generate_smooth_path(std::deque<one_point> given_points);
    pthread_t t1, t2; // declare 2 threads.
    int maintainSpeedON;
    std::thread* thread = NULL;
    void maintainSpeedWorker(int desiredSpeed);

    void SetMaintainSpeedOFF();
};
struct my_struct{
    vilma_self_driver *obj_pointer;
    int desiredSpeed_arg;
};
    void* maintainSpeedWorker(void *args);
#endif // VILMA_SELF_DRIVER_H
