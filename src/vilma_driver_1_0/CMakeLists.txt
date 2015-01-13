cmake_minimum_required(VERSION 2.8.3)
project(vilma_driverqt_1_0)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  gazebo_ros
)
find_package(gazebo REQUIRED)
find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui QtDeclarative)


SET(vilma_driverqt_1_0_SOURCES src/main.cpp src/mainwindow.cpp src/vilma_ros_talker.cpp src/vilma_self_driver.cpp src/points.cpp )
SET(vilma_driverqt_1_0_HEADERS src/mainwindow.h src/vilma_ros_talker.h src/vilma_self_driver.h src/points.h)
SET(vilma_driverqt_1_0_FORMS src/mainwindow.ui)
#SET(vilma_driverqt_1_0_RESOURCES /src/mainwindow.ui)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES vilma_driverqt_1_0
CATKIN_DEPENDS roscpp std_msgs vilma_plugin
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
  ${GAZEBO_INCLUDE_DIRS}
)
ADD_DEFINITIONS(${QT_DEFINITIONS})
include(${QT_USE_FILE})

QT4_WRAP_CPP(vilma_driverqt_1_0_HEADERS_MOC ${vilma_driverqt_1_0_HEADERS})
QT4_WRAP_UI( vilma_driverqt_1_0_FORMS_HEADERS ${vilma_driverqt_1_0_FORMS})

## Declare a cpp library
# add_library(vilma_driverqt_1_0
#   src/${PROJECT_NAME}/vilma_driverqt_1_0.cpp
# )
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
## Declare a cpp executable
# add_executable(vilma_driverqt_1_0_node src/vilma_driverqt_1_0_node.cpp)
add_executable(vilma_driverqt_1_0 ${vilma_driverqt_1_0_SOURCES} ${vilma_driverqt_1_0_HEADERS} ${vilma_driverqt_1_0_HEADERS_MOC} ${vilma_driverqt_1_0_FORMS_HEADERS} ${vilma_driverqt_1_0_RESOURCES_RCC})
## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(vilma_driverqt_1_0_node vilma_driverqt_1_0_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(vilma_driverqt_1_0_node
#   ${catkin_LIBRARIES}
# )

target_link_libraries(vilma_driverqt_1_0 ${QT_LIBRARIES} ${ROS_LIBRARIES} ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
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

## Mark executables and/or libraries for installation
install(TARGETS vilma_driverqt_1_0 
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#      src/app.qml
#   # myfile2
#      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
    #DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#  )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_vilma_driverqt_1_0.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
