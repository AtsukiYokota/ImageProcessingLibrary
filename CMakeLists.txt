cmake_minimum_required(VERSION 2.8)
project(ImageProcessingLibrary)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")

find_package(OpenCV REQUIRED)

# Copy image DIR
file(COPY ${CMAKE_SOURCE_DIR}/image/ DESTINATION ${PROJECT_BINARY_DIR}/image/)
add_definitions(-DRESOURCE_DIR="${PROJECT_BINARY_DIR}/image/")

###########
## Build ##
###########
include_directories(include)

add_executable(gray_level_transform src/gray_level_transform/main.cpp)
target_include_directories(gray_level_transform PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(gray_level_transform ${OpenCV_LIBS})

