#include <ros/ros.h>
#include <std_msgs/String.h>

void messageCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber_node");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("my_topic", 1000, messageCallback);
  ros::spin();
  return 0;
}