cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GAZEBO gazebo)
endif()
include(cmake/rospack.cmake)

get_rospack_flags(roscpp)
include_directories(${roscpp_INCLUDE_DIRS})
link_directories(${roscpp_LIBRARY_DIRS})
set(CMAKE_INSTALL_RPATH "${roscpp_LIBRARY_DIRS}")

include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

add_library(VilmaPlugin SHARED VilmaPlugin.cc)
target_link_libraries(VilmaPLugin ${GAZEBO_libraries})
target_link_libraries(VilmaPLugin ${roscpp_LIBRARIES})

