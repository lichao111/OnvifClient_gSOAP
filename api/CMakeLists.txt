CMAKE_MINIMUM_REQUIRED(VERSION 3.4.1)
project(deviceinformation)
message("Make ${PROJECT_NAME}")

add_library(${PROJECT_NAME} SHARED ${sourcecode} deviceInformation.cpp)
target_link_libraries(${PROJECT_NAME} ssl crypto)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../samples/common)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}")
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})