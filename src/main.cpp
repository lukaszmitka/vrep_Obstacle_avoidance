#include "main.h"

ros::Publisher ultrasonic_publisher;
float leftDistance = 0;
float rightDistance = 0;
char left_update = 10;
char right_update = 10;

float left_target_vel = 0;
float right_target_vel = 0;

void leftSensorCallback(const sensor_msgs::Range::ConstPtr &msg) {
   leftDistance = msg->range;
   left_update = 3;
}

void rightSensorCallback(const sensor_msgs::Range::ConstPtr &msg) {
   rightDistance = msg->range;
   right_update = 3;
}

int main(int argc, char **argv) {

   ros::init(argc, argv, "vrep_obstacle_avoidance_node");
   ros::NodeHandle n;

   ros::Subscriber leftSub = n.subscribe("/front_left/ultrasonic", 1, leftSensorCallback);
   ros::Subscriber rightSub = n.subscribe("/front_right/ultrasonic", 1, rightSensorCallback);

   left_motor_pub = n.advertise<std_msgs::Float64>("/vrep/left_joint", 1);
   right_motor_pub = n.advertise<std_msgs::Float64>("/vrep/right_joint", 1);

   ros::Rate loop_rate(10);

   while (ros::ok()) {
      left_update--;
      right_update--;
      ros::spinOnce();

      if (left_update == 0) {
         leftDistance = 0;
      }
      if (right_update == 0) {
         rightDistance = 0;
      }

      loop_rate.sleep();


      if (leftDistance > 0) {
         right_target_vel = 2.5 * (leftDistance - 0.25);
      } else {
         right_target_vel = 5.625;
      }


      if (rightDistance > 0) {
         left_target_vel = 2.5 * (rightDistance - 0.25);
      } else {
         left_target_vel = 5.625;
      }

      left_motor.data = left_target_vel;
      right_motor.data = right_target_vel;
      left_motor_pub.publish(left_motor);
      right_motor_pub.publish(right_motor);
   }
   return 0;
}