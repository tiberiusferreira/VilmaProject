/*
 * Copyright 2012 laboratorio de mobiladade autonoma
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/* Desc: plug-in for the VILMA car of the LMA UNICAMP
 *
 * the plug-in is a copy of the VehiclePlugin of gazebo with some modification to include the dynamics
 * of the steerign. Thanks to Nate koenig
 * Author: Olmer Garcia
 * http://www.fem.unicamp.br/~lma
 *
 */

#ifndef __VILMA_PLUGIN_HH__
#define __VILMA_PLUGIN_HH__



#include "ros/ros.h"
#include "std_msgs/Float64.h"




#include <string>
#include <vector>
#include "common/common.hh"
#include "physics/physics.hh"
#include "transport/transport.hh"
#include "gazebo.hh"

namespace gazebo
{
  class VilmaPlugin : public ModelPlugin
  {
    /// \brief Constructor
    public: VilmaPlugin();

    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
    public: virtual void Init();

    private: void OnUpdate();

    private: void OnVelMsg(ConstPosePtr &_msg);

    private: std::vector<event::ConnectionPtr> connections;

    private: physics::ModelPtr model;
    private: physics::LinkPtr chassis;
    private: std::vector<physics::JointPtr> joints;
    private: physics::JointPtr gasJoint, brakeJoint;
    private: physics::JointPtr steeringJoint;

    private: math::Vector3 velocity;

    private: transport::NodePtr node;
    private: transport::SubscriberPtr velSub;

    private: double frontPower, rearPower;
    private: double maxSpeed;
    private: double wheelRadius;

    private: double steeringRatio;
    private: double tireAngleRange;
    private: double maxGas, maxBrake;

    private: double aeroLoad;
    private: double swayForce;



    private: ros::NodeHandle* node1;

    void ROSCallback(const std_msgs::Float64::ConstPtr& msg)
    {
      ROS_INFO("subscriber got: [%f]", msg->data);
    }
    private: event::ConnectionPtr updateConnection;
    ros::Subscriber sub;






  };
}
#endif
