cmake_minimum_required(VERSION 2.8.3)
project(msg_task)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg geometry_msgs message_generation)

add_message_files(
  FILES 
  Robotmsg.msg)

#add_service_files(
#  FILES 
#  AddTwoInts.srv)

generate_messages(
  DEPENDENCIES 
  std_msgs)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener msg_task_generate_message_cpp)

add_executable(timer src/timer.cpp)
target_link_libraries(timer ${catkin_LIBRARIES})
add_dependencies(timer msg_task_gencpp)

add_executable(controller src/controller.cpp)
target_link_libraries(controller ${catkin_LIBRARIES})
add_dependencies(controller msg_task_gencpp)


