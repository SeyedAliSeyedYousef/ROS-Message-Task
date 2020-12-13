#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include <sstream>
/*
void timer1 (const ros::TimerEvent&){
	
	ros::NodeHandle con;
	ros::Publisher sender = con.advertise<std_msgs::Int16>("timenode", 10);	
	ros::Rate loop_rate (10);
	
	int counter = 0;

	while (ros::ok()){
		
		std_msgs::Int16 msg;
		msg.data = counter;
		

		ROS_INFO ("Timer --> [%i]", msg.data);

		sender.publish(msg);

		ros::spinOnce();
		
		loop_rate.sleep();

		++counter;
		}}

void timer2 (const ros::TimerEvent&){
	
	ros::NodeHandle con;
	ros::Publisher sender = con.advertise<std_msgs::Int16>("lis1", 10);	
	ros::Rate loop_rate (10);
	
	int counter = 0;

	while (ros::ok()){
		
		std_msgs::Int16 msg;
		msg.data = counter;
		

		ROS_INFO ("Timer --> [%i]", msg.data);

		sender.publish(msg);

		ros::spinOnce();
		
		loop_rate.sleep();

		++counter;
		}}

int main (int argc, char **argv){
	
	ros::init (argc, argv, "timer");
	ros::NodeHandle con;
	
	//ros::Timer timer_publisher = con.createTimer(ros::Duration(1.0), timer1);
	//ros::Timer timer_message = con.createTimer(ros::Duration(1.0), timer2);
	
	ros::spin();	
			
	return 0;
	}
*/
int main(int argc,char **argv)
{
ros::init(argc,argv,"timer");
ros::NodeHandle n;
ros::Publisher chatter_pub1 = n.advertise<std_msgs::Int16>("lis1",10);
ros::Publisher chatter_pub2 = n.advertise<std_msgs::Int16>("timenode",10);

ros::Rate loop_rate(10) ;

int count = 0;

while(ros::ok())
{
std_msgs::Int16 msg1;
std_msgs::Int16 msg2;


msg1.data = count;
msg2.data = count;

ROS_INFO("%i",msg1.data);
ROS_INFO("%i",msg2.data);

chatter_pub1.publish(msg1);
chatter_pub2.publish(msg2);
ros::spinOnce();
loop_rate.sleep();
++count;
}
return 0;
}
