#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"
#include "../include/can_utils.hpp"
#include "can_plugins/Frame.h"

void chatterCallback(const sensor_msgs::Joy::ConstPtr& msg);

ros::Publisher* chatter; 

int main(int argc, char **argv){
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("joy", 1000, chatterCallback);
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  chatter = &chatter_pub;
  ros::spin();
  return 0;
}

void chatterCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->buttons[2]);
  chatter->publish(msg);
}