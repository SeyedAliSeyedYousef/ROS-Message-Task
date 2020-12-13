#include "ros/ros.h"
#include "msg_task/Robotmsg.h"
#include "std_msgs/Int16.h"

int value = 0;

void show_data (const std_msgs::Int16::ConstPtr& msg){

	ROS_INFO ("Timer to controller ==> [%i]", msg->data);
	value = msg->data;
}

int main (int argc, char **argv){

	ros::init (argc, argv, "controller");
	
	ros::NodeHandle con;
	ros::Publisher robot = con.advertise<msg_task::Robotmsg>("lis2", 10);
	ros::Subscriber recv_t = con.subscribe("timenode", 10, show_data);	
	ros::Rate loop_rate (10);

	while (ros::ok()){
	
		msg_task::Robotmsg metis;
		
		metis.vx = value;
		metis.vy = 0;
		metis.vz = 0;

		robot.publish(metis);

		ros::spinOnce();
		
		loop_rate.sleep();
	}}

