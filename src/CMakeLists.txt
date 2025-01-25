cmake_minimum_required(VERSION 3.17)
project(FrameNet)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(util REQUIRED)
find_package(xml_parser REQUIRED)

add_library(FrameNet Frame.cpp Frame.h FrameNet.cpp FrameNet.h FrameElement.cpp FrameElement.h FrameElementList.h FrameElementList.cpp)
target_link_libraries(FrameNet xml_parser::xml_parser util::util)
