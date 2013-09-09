/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
//![0]
#include "piechart.h"

void VilmaControler_ROS::init()
{
    ////////////////////////////////////GAS PEDAL //////////////////////////////////////
    gas_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/gas_pedal/cmd", 1);

    gas_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/gas_pedal/state",1,&VilmaControler_ROS::receive_gas_pedal_data,this);

    ////////////////////////////////////Brake Pedal //////////////////////////////////////

    brake_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/brake_pedal/cmd", 1);

    brake_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/brake_pedal/state",1, &VilmaControler_ROS::receive_brake_pedal_data,this);
    ////////////////////////////////////Hand Brake //////////////////////////////////////


    hand_brakepub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_brake/cmd", 1);

    hand_brakesub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_brake/state",1,&VilmaControler_ROS::receive_hand_brake_data,this);

    ////////////////////////////////////Hand Wheel //////////////////////////////////////

    hand_wheelpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_wheel/cmd", 1);

    hand_wheelsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_wheel/state",1,&VilmaControler_ROS::receive_hand_wheel_data,this);

        ////////////////////////////////////Wheel Velocity //////////////////////////////////////

    bl_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/blWheel",1,&VilmaControler_ROS::receive_back_left_wheel_speed,this);
    br_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/brWheel",1,&VilmaControler_ROS::receive_back_right_wheel_speed,this);
    fl_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/flWheel",1,&VilmaControler_ROS::receive_front_left_wheel_speed,this);
    fr_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/frWheel",1,&VilmaControler_ROS::receive_front_right_wheel_speed,this);

        ////////////////////////////////////Gears State //////////////////////////////////////

    gears_pub = rosNode.advertise<std_msgs::Int8>("/vilma_vehicle/direction/cmd", 1);

    gears_sub = rosNode.subscribe<std_msgs::Int8>("/vilma_vehicle/direction/state",1,&VilmaControler_ROS::receive_gears_state,this);



}

void VilmaControler_ROS::receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    if(msg->data!=gas_pedal_state.data)
    {
        gas_pedal_state.data=msg->data;
    }

}

void VilmaControler_ROS::receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    brake_pedal_state.data=msg->data;
}

void VilmaControler_ROS::receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_brake_state.data=msg->data;
}

void VilmaControler_ROS::receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_wheel_state.data=msg->data;
}

void VilmaControler_ROS::receive_back_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    bl_wheel_speed.data=msg->data;
}

void VilmaControler_ROS::receive_back_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    br_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_front_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    fl_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_front_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    fr_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_gears_state(const std_msgs::Int8::ConstPtr& msg)
{
    gears.data=msg->data;
}


//![0]
