#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"

void chatterCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->buttons[2]);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("joy", 1000, chatterCallback);
  ros::spin();
  return 0;
}