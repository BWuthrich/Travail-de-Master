# Install script for directory: /app/dev_ws/tiscamera/src/gstreamer-1.0

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/libtcamgstbase.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libtcamgstbase.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:/app/dev_ws/tiscamera/build/src/v4l2:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/libtcamgstbase.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/aarch64-linux-gnu/gstreamer-1.0" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libgsttcammainsrc.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src/gstreamer-1.0:/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/v4l2:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcammainsrc.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/aarch64-linux-gnu/gstreamer-1.0" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libgsttcamsrc.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src/gstreamer-1.0:/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/v4l2:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamsrc.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/aarch64-linux-gnu/gstreamer-1.0" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libgsttcamwhitebalance.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src/gstreamer-1.0:/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/v4l2:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamwhitebalance.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/aarch64-linux-gnu/gstreamer-1.0" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libgsttcamautoexposure.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src/gstreamer-1.0:/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/v4l2:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautoexposure.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/aarch64-linux-gnu/gstreamer-1.0" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libgsttcamautofocus.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src/gstreamer-1.0:/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/v4l2:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcamautofocus.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/aarch64-linux-gnu/gstreamer-1.0" TYPE SHARED_LIBRARY FILES "/app/dev_ws/tiscamera/build/src/gstreamer-1.0/libgsttcambin.so")
  if(EXISTS "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so"
         OLD_RPATH "/app/dev_ws/tiscamera/build/src/gstreamer-1.0:/app/dev_ws/tiscamera/build/src:/app/dev_ws/tiscamera/build/src/v4l2:/app/dev_ws/tiscamera/build/src/gobject:/app/dev_ws/tiscamera/build/src/algorithms:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/aarch64-linux-gnu/gstreamer-1.0/libgsttcambin.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtcam-gstreamer-1x" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/gstreamer-1.0/gstmetatcamstatistics.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/gstreamer-1.0" TYPE FILE FILES "/app/dev_ws/tiscamera/src/gstreamer-1.0/gstmetatcamstatistics.h")
endif()

