#ifndef VILMA_SELF_DRIVER_H
#define VILMA_SELF_DRIVER_H
#include "vilma_ros_talker.h"
class vilma_self_driver
{
public:
    vilma_self_driver(vilma_ros_talker *Vilmaobj);
    vilma_ros_talker *ros_talker;
    int reorientate_to_pose(float x, float y);
};

#endif // VILMA_SELF_DRIVER_H
