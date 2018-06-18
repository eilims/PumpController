cmake_minimum_required(VERSION 3.10)
project(LinkedList)

set(CMAKE_CXX_STANDARD 11)

#set(arduino_INCLUDE_DIRECTORIES
#         "C:/Program Files (x86)/Arduino/hardware/arduino/avr/cores/arduino"
#         "C:/Program Files (x86)/Arduino/hardware/tools/avr/avr/include/"
#)

include_directories(${arduino_INCLUDE_DIRECTORIES})

#add_executable(LinkedList UnitTests.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp Sensor.cpp Sensor.h)
add_executable(LinkedList UnitTests.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp)