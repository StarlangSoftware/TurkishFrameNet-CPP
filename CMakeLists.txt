cmake_minimum_required(VERSION 3.17)
project(FrameNet)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(FrameNet src/Frame.cpp src/Frame.h src/FrameNet.cpp src/FrameNet.h src/FrameElement.cpp src/FrameElement.h)
target_link_libraries(FrameNet ${CONAN_LIBS})
add_executable(Test src/Frame.cpp src/Frame.h src/FrameNet.cpp src/FrameNet.h src/FrameElement.cpp src/FrameElement.h Test/catch.hpp Test/FrameElementTest.cpp Test/FrameNetTest.cpp)
target_link_libraries(Test ${CONAN_LIBS})
