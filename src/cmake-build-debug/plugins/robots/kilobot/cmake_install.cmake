# Install script for directory: /home/fred/argos3-kilobot/src/plugins/robots/kilobot

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/argos3/plugins/robots/kilobot/control_interface" TYPE FILE FILES
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/ci_kilobot_communication_actuator.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/ci_kilobot_communication_sensor.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/ci_kilobot_controller.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/ci_kilobot_led_actuator.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/ci_kilobot_light_sensor.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/kilolib.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/debug.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/message.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/control_interface/message_crc.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/argos3/plugins/robots/kilobot/simulator" TYPE FILE FILES
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/dynamics2d_kilobot_model.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/pointmass3d_kilobot_model.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_entity.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_measures.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_led_default_actuator.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_light_rotzonly_sensor.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_communication_default_actuator.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_communication_default_sensor.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_communication_entity.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/kilobot_communication_medium.h"
    "/home/fred/argos3-kilobot/src/plugins/robots/kilobot/simulator/qtopengl_kilobot.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/argos3" TYPE SHARED_LIBRARY FILES "/home/fred/argos3-kilobot/src/cmake-build-debug/plugins/robots/kilobot/libargos3plugin_simulator_kilobot.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so"
         OLD_RPATH "/usr/lib/argos3:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_simulator_kilobot.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/argos3" TYPE STATIC_LIBRARY FILES "/home/fred/argos3-kilobot/src/cmake-build-debug/plugins/robots/kilobot/libargos3plugin_simulator_kilolib.a")
endif()

