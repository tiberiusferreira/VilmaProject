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
#include "VilmaControler_QtSide.h"
//////////////////////////////////// INIT AND RECEIVE STATE FUNCTION //////////////////////////////////////
void VilmaControler_ROS::init()
{
    this->thread_count=0;
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
void VilmaControler_ROS::callback1()
{
    float acceleration, speed_t1,speed_t2, target_speed, diff_vel, time_diff=0.01;


    target_speed=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
    for(;1;){
                try
                {
                    boost::this_thread::interruption_point();
                }
                catch(boost::thread_interrupted&)
                {
                    return;
                }
        speed_t1=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
        speed_t2=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
        while(speed_t1==speed_t2){
            boost::this_thread::sleep(boost::posix_time::milliseconds(10));
            speed_t2=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
            time_diff=time_diff+0.01;
        }
        acceleration=(speed_t2-speed_t1)/time_diff;
        time_diff=0.01;
        printf("BACK Wheel Aceleration %f\n",acceleration);
        printf("Target speed: %f\n",target_speed);
        printf("Actual speed: %f\n",speed_t2);
        diff_vel=target_speed-speed_t2;
        printf("DIFF = %f\n",diff_vel);

        if(diff_vel>0){ //target_speed >speed_t2, need to speed up!
            if(acceleration>0){
                if(acceleration<=(diff_vel/2)){
                    //do nothing
                   // printf("\n1\n");
                }
                if(acceleration>(diff_vel/2)){
                    this->deaccelerate(0.03);
                    //printf("\n2\n");

                }
            }else if(acceleration<0)
            {
                //printf("\n3\n");

                this->accelerate(0.01);
            }
        }else if(diff_vel<0){ //speed_t2>target_speed need to slow down!
            printf("Acceleration= %f \n",acceleration);
            if(acceleration<0){
                if(acceleration>=(diff_vel/2))
                {
                    //printf("\n4\n");

                    //do nothing
                }
                if(acceleration<(diff_vel/2)){
                    this->accelerate(0.01);
                   // printf("Acceleration = %f. Diff_vel = %f.\n",acceleration,diff_vel);

                }
            }else
            {
                this->deaccelerate(0.03);
                //printf("\n6\n");

            }
        }
    }
}

void VilmaControler_ROS::receive_model_physical_state(gazebo_msgs::GetModelState getmodelstate)
{
    ros::ServiceClient gmscl = rosNode.serviceClient<gazebo_msgs::GetModelState>("/gazebo/get_model_state");
    ros::spinOnce();
    ((getmodelstate).request).model_name ="vilma_vehicle";
    gmscl.call((getmodelstate));
    modelstate.pose.position.x=getmodelstate.response.pose.position.x;
    modelstate.pose.position.y=getmodelstate.response.pose.position.y;
    modelstate.pose.position.z=getmodelstate.response.pose.position.z;
    modelstate.twist.angular.x=getmodelstate.response.twist.angular.x;
    modelstate.twist.angular.y=getmodelstate.response.twist.angular.y;
    modelstate.twist.angular.z=getmodelstate.response.twist.angular.z;
    modelstate.pose.orientation.x=getmodelstate.response.pose.orientation.x;
    modelstate.pose.orientation.y=getmodelstate.response.pose.orientation.y;
    modelstate.pose.orientation.z=getmodelstate.response.pose.orientation.z;
    modelstate.pose.orientation.w=getmodelstate.response.pose.orientation.w;

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
//////////////////////////////////// FUNCTION FOR CONTROLLING THE CAR //////////////////////////////////////
void VilmaControler_ROS::accelerate(float amount_to_increase){
    std_msgs::Float64 accelerate;
    if(this->brake_pedal_state.data>0.01){
        accelerate.data=0;
        this->brake_pedalpub.publish(accelerate);
        return;
    }
    accelerate.data=this->gas_pedal_state.data+amount_to_increase;
    this->gas_pedalpub.publish(accelerate);
}
void VilmaControler_ROS::deaccelerate(float amount_to_decrease){
    std_msgs::Float64 deaccelerate;
    if(this->gas_pedal_state.data>0.005){
        deaccelerate.data=this->gas_pedal_state.data-amount_to_decrease;
        this->gas_pedalpub.publish(deaccelerate);
        return;
    }
    deaccelerate.data=this->brake_pedal_state.data+amount_to_decrease;
    this->brake_pedalpub.publish(deaccelerate);
}
void VilmaControler_ROS::maintain_speed(){
    if(this->thread_count>0){
        this->tgroup.interrupt_all();
        this->tgroup.join_all();
        this->thread_count=0;
        return;
    }
    this->tgroup.create_thread( boost::bind(&VilmaControler_ROS::callback1,this) );
    this->thread_count=thread_count+1;

}

//![0]




















