cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(cmake_cxx_standard 23)
set(CMAKE_CXX_COMPILER:FILEPATH
    C:/Users/xdlol/winlibs-x86_64-posix-seh-gcc-11.2.0-llvm-13.0.0-mingw-w64ucrt-9.0.0-r2/mingw64/bin/clang++.exe
)
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
  request.cpp
  request.h
  response.h
  threading.cpp
  threading.h
  unauthenticated_request.cpp
  unauthenticated_request.h
  user_agents.h
  valid.cpp
  valid.h
  httplib.h)
