#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros_tutorial/my_msgType.h>

void messageCallback(const ros_tutorial::my_msgType::ConstPtr& msg)
{
      ROS_INFO_STREAM("I heard: "
            << msg->local_date << " "
            << msg->local_time << " "
            << msg->topic_msgs);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_sub2");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("my_topic", 1000, messageCallback);
  ros::spin();
  return 0;
}