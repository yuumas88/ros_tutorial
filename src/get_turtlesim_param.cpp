#include <ros/ros.h>
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "get_background_color");
    ros::NodeHandle nh;
    int red_val, green_val, blue_val;

    if(nh.hasParam("/background_r")) nh.getParam("/background_r", red_val);
    if(nh.hasParam("/background_g")) nh.getParam("/background_g", green_val);
    if(nh.hasParam("/background_b")) nh.getParam("/background_b", blue_val);
    ROS_INFO_STREAM("background color: (" << red_val << "," << green_val << "," << blue_val << ")");
    return 0;
}