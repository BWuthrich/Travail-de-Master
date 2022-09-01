# CMake generated Testfile for 
# Source directory: /app/dev_ws/vision_opencv/image_geometry
# Build directory: /app/dev_ws/build/image_geometry
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(image_geometry-utest "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/app/dev_ws/build/image_geometry/test_results/image_geometry/image_geometry-utest.gtest.xml" "--package-name" "image_geometry" "--output-file" "/app/dev_ws/build/image_geometry/ament_cmake_gtest/image_geometry-utest.txt" "--command" "/app/dev_ws/build/image_geometry/image_geometry-utest" "--gtest_output=xml:/app/dev_ws/build/image_geometry/test_results/image_geometry/image_geometry-utest.gtest.xml")
set_tests_properties(image_geometry-utest PROPERTIES  LABELS "gtest" REQUIRED_FILES "/app/dev_ws/build/image_geometry/image_geometry-utest" TIMEOUT "60" WORKING_DIRECTORY "/app/dev_ws/build/image_geometry" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/foxy/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/app/dev_ws/vision_opencv/image_geometry/CMakeLists.txt;49;ament_add_gtest;/app/dev_ws/vision_opencv/image_geometry/CMakeLists.txt;0;")
subdirs("gtest")
