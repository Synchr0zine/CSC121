cmake_minimum_required(VERSION 3.29)
project(CSC121)

set(CMAKE_CXX_STANDARD 20)
# Week 2
add_executable(bowling_program week2/bowling.cpp)

# Code from Lecture
add_executable(bowlingBall_program week3/codeFromLecture/bowlingBall.cpp)
add_executable(bowlingBall2_program week3/codeFromLecture/bowlingBall2.cpp)
add_executable(bowlingBall3_program week3/codeFromLecture/bowlingBall3.cpp)
add_executable(bowlingBall3a_program week3/codeFromLecture/bowlingBall3a.cpp)
add_executable(bowlingBalla_program week3/codeFromLecture/bowlingBalla.cpp)
add_executable(sphere3_program week3/codeFromLecture/sphere3.cpp)
add_executable(sphere4_program week3/codeFromLecture/sphere4.cpp)
add_executable(sphere5_program week3/codeFromLecture/sphere5.cpp)
add_executable(sphere5a_program week3/codeFromLecture/sphere5a.cpp)

# Week 3
add_executable(launch_program week3/launch.cpp)
