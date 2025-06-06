CMAKE_MINIMUM_REQUIRED(VERSION 3.4.1)
project(demo)

set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME} demo.cpp)

target_link_libraries(${PROJECT_NAME} deviceinformation ssl crypto)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../api)
