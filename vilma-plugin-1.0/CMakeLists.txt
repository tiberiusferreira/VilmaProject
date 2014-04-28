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

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

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
set(GAZEBO_MODEL_PATH "$ENV{GAZEBO_MODEL_PATH}")
IF (GAZEBO_MODEL_PATH)
MESSAGE("GAZEBO_MODEL_PATH already set")
ELSE()
MESSAGE("GAZEBO_MODEL_PATH not set, trying to solve it")
file(APPEND $ENV{HOME}/.bashrc "\nexport GAZEBO_MODEL_PATH=${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}:$GAZEBO_MODEL_PATH")
set (GAZEBO_MODEL_PATH "${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}")
ENDIF()

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
