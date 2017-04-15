cmake_minimum_required(VERSION 2.8.3)
project(vrep_obstacle_avoidance)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(vrep_obstacle_avoidance_node src/main.cpp)

target_link_libraries(vrep_obstacle_avoidance_node
   ${catkin_LIBRARIES}
 )
