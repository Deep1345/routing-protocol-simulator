cmake_minimum_required(VERSION 3.16)

project(RoutingProtocolSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simulator
    main.cpp
    src/Router.cpp
    src/Link.cpp
    src/Network.cpp
)

target_include_directories(simulator PRIVATE include)