cmake_minimum_required(VERSION 3.16.3)
#-lssl -lcrypto
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++2a -lssl -lcrypto")
set(cmake_cxx_standard 23)
#cmake -DOPENSSL_ROOT_DIR=/usr/local/lib/ -DOPENSSL_CRYPTO_LIBRARY=/usr/local/lib/

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
  filestreams.h
  filestreams.cpp
  in_streams.cpp
  in_streams.h
  invalid.h
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
  valid.h
  payload_container.h
  payload_container.cpp
  httplib.h
  taskflow/taskflow/taskflow.hpp)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)
target_link_libraries(checker OpenSSL::Crypto)


