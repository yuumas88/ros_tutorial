#include <ros/ros.h>
#include <vector>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_first_node");
  ros::NodeHandle nh;

  std::string name = ros::this_node::getName();


  std::string nameSpace = ros::this_node::getNamespace();


  ros::V_string pub, sub;
  ros::this_node::getAdvertisedTopics(pub);


  ros::this_node::getSubscribedTopics(sub);
  ROS_INFO_STREAM("nameapace: " << nameSpace);
  ROS_INFO_STREAM("Node [" << name << "]");


  if(pub.size() == 0)
      ROS_INFO_STREAM("Publications: None:");
  else {
      ROS_INFO_STREAM("Publications:");
      for(int i=0;i<pub.size();i++)
          ROS_INFO_STREAM(" * "  << pub[i]);
  }    
  ROS_INFO("\n");


  if(sub.size() == 0)
      ROS_INFO_STREAM("Subscriptions: None");
  else {
    ROS_INFO_STREAM("Subscriptions:");
    for(int i=0;i<sub.size();i++)
        ROS_INFO_STREAM(" * " << sub[i]);
  }
  ROS_INFO("\n---\n");
  return 0;
  }
