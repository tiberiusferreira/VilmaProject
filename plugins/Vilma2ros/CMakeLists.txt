cmake_minimum_required(VERSION 2.8)

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GAZEBO gazebo REQUIRED)
else()
  message(FATAL_ERROR "pkg-config is required; please install it")
endif()


# depends on DRCVehiclePlugin
include_directories(
  ${GAZEBO_INCLUDE_DIRS}
  ../Vilma2
)


include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

include(cmake/rospack.cmake)

get_rospack_flags(roscpp)
include_directories(${roscpp_INCLUDE_DIRS})
link_directories(${roscpp_LIBRARY_DIRS})
set(CMAKE_INSTALL_RPATH "${roscpp_LIBRARY_DIRS}")
add_library(vilma_ros_plugin SHARED DRCVehicleROSPlugin.cpp)
target_link_libraries(vilma_ros_plugin Vilma2Plugin)



set_target_properties(vilma_ros_plugin PROPERTIES COMPILE_FLAGS "${roscpp_CFLAGS_OTHER}")
set_target_properties(vilma_ros_plugin PROPERTIES LINK_FLAGS "${roscpp_LDFLAGS_OTHER}")
target_link_libraries(vilma_ros_plugin ${roscpp_LIBRARIES})
install (TARGETS vilma_ros_plugin DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/gazebo_plugins/)
