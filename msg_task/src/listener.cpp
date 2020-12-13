#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "msg_task/Robotmsg.h"

void show_data_one (const std_msgs::Int16::ConstPtr& msg){

	ROS_INFO ("Timer to listener ==> [%i]", msg->data);
}

void show_data_two (const msg_task::Robotmsg::ConstPtr& msg){

	ROS_INFO ("controller to Listener VX : %i ", msg->vx);
	ROS_INFO ("controller to Listener VY : %i ", msg->vy);
	ROS_INFO ("controller to Listener Vz : %i ", msg->vz);
}

int main (int argc, char **argv){

	ros::init (argc, argv, "listener");
	ros::NodeHandle con;

	ros::Subscriber recv_o = con.subscribe("lis1", 10, show_data_one);
	ros::Subscriber recv_t = con.subscribe("lis2", 10, show_data_two);
	
	ros::spin();

	return 0;}
	


