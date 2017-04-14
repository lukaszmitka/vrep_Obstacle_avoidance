//
// Created by lukasz on 16.11.16.
//

#ifndef VREP_OBSTACLE_AVOIDANCE_MAIN_H
#define VREP_OBSTACLE_AVOIDANCE_MAIN_H

#include "ros/ros.h"
#include "vrep_common/ProximitySensorData.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/Float64.h"

ros::Publisher left_motor_pub;
ros::Publisher right_motor_pub;
std_msgs::Float64 left_motor;
std_msgs::Float64 right_motor;

#endif //VREP_OBSTACLE_AVOIDANCE_MAIN_H
