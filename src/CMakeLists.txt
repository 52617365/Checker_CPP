cmake_minimum_required(VERSION 3.16.3)
#-lssl -lcrypto
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++2a -lssl -lcrypto")
set(cmake_cxx_standard 23)
#set(CMAKE_CXX_COMPILER:FILEPATH
#    C:/Users/xdlol/winlibs-x86et(CMAKE_CXX_COMPILER "/usr/bin/g++-9.3.0")
#)
project(
  Checker
  VERSION 2.0
  DESCRIPTION "Checker"
  LANGUAGES CXX)

add_executable(
  checker
  main.cpp
  authenticated_request.cpp
  authenticated_request.h
  authentication.cpp
  authentication.h
  combos.h
  filestreams.cpp
  filestreams.h
  in_streams.cpp
  in_streams.h
  invalid.cpp
  invalid.h
  out_streams.cpp
  out_streams.h
  payload_container.cpp
  payload_container.h
  proxies.h
  response.h
  threading.cpp
  threading.h
  unauthenticated_request.cpp
  unauthenticated_request.h
  user_agents.h
  valid.cpp
  valid.h
  payload_container.h
  payload_container.cpp
  httplib.h
  taskflow/taskflow/taskflow.hpp)
