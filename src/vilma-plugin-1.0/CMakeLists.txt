cmake_minimum_required(VERSION 2.8.3)
project(vilma_plugin)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
  std_msgs
)
find_package(Boost REQUIRED COMPONENTS thread)
find_package(gazebo REQUIRED)
## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost REQUIRED COMPONENTS thread)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES vilma_plugin
  CATKIN_DEPENDS gazebo_ros roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${gazebo_ros_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(Vilma2Plugin
   src/Vilma2/DRCVehiclePlugin.cc
 )
add_library(vilma_ros_plugin
   src/DRCVehicleROSPlugin.cpp
 )

## Declare a cpp executable
# add_executable(vilma_plugin_node src/vilma_plugin_node.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(vilma_plugin_node vilma_plugin_generate_messages_cpp)
add_dependencies(vilma_ros_plugin Vilma2Plugin)
## Specify libraries to link a library or executable target against
target_link_libraries(vilma_ros_plugin
  ${catkin_LIBRARIES}
  Vilma2Plugin
 )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
message(BIN = ${CATKIN_PACKAGE_BIN_DESTINATION})
## Mark executables and/or libraries for installation
 install(TARGETS Vilma2Plugin vilma_ros_plugin 

#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION  ${CATKIN_PACKAGE_LIB_DESTINATION}  #${CATKIN_PACKAGE_LIB_DESTINATION} # Use /usr/lib/gazebo-1.9/plugins with sudo? #use GAZEBO_PLUGIN_PATH variable? 
   PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE
    GROUP_WRITE GROUP_READ GROUP_EXECUTE
    WORLD_WRITE WORLD_READ WORLD_EXECUTE
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}

)

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )
# Removed it because the .deb package can't do it directly. Uses post 
#installation scripts
   install(DIRECTORY Files_to_be_copied/environments/
   #DESTINATION $(HOME)/.gazebo/models
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  FILE_PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE
    GROUP_WRITE GROUP_READ GROUP_EXECUTE
    WORLD_WRITE WORLD_READ WORLD_EXECUTE
  DIRECTORY_PERMISSIONS     OWNER_WRITE OWNER_READ OWNER_EXECUTE
   GROUP_WRITE GROUP_READ GROUP_EXECUTE
   WORLD_WRITE WORLD_READ WORLD_EXECUTE
   
 )

# Setting catkin install folder setup.bash to be sourced by bashrc and also gazebo model path to find models in catkin folder. 
execute_process (COMMAND ${CMAKE_INSTALL_PREFIX}/../src/vilma-plugin-1.0/setbashrc.bash)
#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_vilma_plugin.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
