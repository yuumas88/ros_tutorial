#include "ros/ros.h"
#include "ros_tutorial/ItoB.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "itob_client");
    if (argc != 2) {
        ROS_INFO("usage: itob_client <number>");
        return 1;
    }
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<ros_tutorial::ItoB>("itob_service");
    ros_tutorial::ItoB srv;
    srv.request.decimal = atoi(argv[1]);
    if (client.call(srv)) {
      ROS_INFO_STREAM("A decimal number " << argv[1] << " was converted to a binary number : " << srv.response.binary);
    } 
    else {
      ROS_ERROR("Failed to call service itob");
      return 1;
    }
    return 0;
}