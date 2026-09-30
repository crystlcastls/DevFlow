cmake_minimum_required(VERSION 3.16)

project(DevFlow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(devflow
    main.cpp
    Issue.cpp
    IssueManager.cpp
)