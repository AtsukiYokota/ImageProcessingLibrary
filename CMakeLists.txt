cmake_minimum_required(VERSION 2.8)
project(ImageProcessingLibrary)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")

# Copy image DIR
file(COPY ${CMAKE_SOURCE_DIR}/image/ DESTINATION ${PROJECT_BINARY_DIR}/image/)
add_definitions(-DRESOURCE_DIR="${PROJECT_BINARY_DIR}/image/")

# Create Main project
add_executable(Main
  src/main.cpp
  include/gray_level_transform.hpp
)

# For OpenCV
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
  target_include_directories(Main PUBLIC ${OpenCV_INCLUDE_DIRS})
  target_link_libraries(Main ${OpenCV_LIBS})
endif()