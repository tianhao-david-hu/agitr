#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iomanip>

void poseMessageReceived(const geometry_msgs::Twist& msg)
{
  ROS_INFO_STREAM(std::setprecision(2)<<std::fixed<<"velocity=("<<msg.linear.x<<","<<msg.linear.y<<")"<<" rotation="<<msg.angular.z);
}
//Test Modified
int main(int argc, char** argv)
{
  ros::init(argc,argv,"subscribe_to_pose");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("/mobile_base/commands/velocity", 1000, &poseMessageReceived);
  ros::spin();
  return 0;
}
