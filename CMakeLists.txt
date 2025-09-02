cmake_minimum_required(VERSION 3.16)

project(net-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(source_dir "${PROJECT_SOURCE_DIR}") 

set(COMMON_SOURCES 
  ${source_dir}/src/common/Game.cpp
  ${source_dir}/src/common/Player.cpp
)
set(SERVER_SOURCES
  ${source_dir}/src/server/Main.cpp
)
set(CLIENT_SOURCES
  ${source_dir}/src/client/Main.cpp 
)

#asio
find_package(PkgConfig REQUIRED)
pkg_check_modules(ASIO REQUIRED asio)
#raylib
find_package(raylib REQUIRED)

add_library(common INTERFACE)

target_include_directories(common INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/common/include
)

add_executable(server ${COMMON_SOURCES} ${SERVER_SOURCES})
target_compile_definitions(server PRIVATE IS_SERVER)
target_link_libraries(server 
  PRIVATE 
    common
)

add_executable(client ${COMMON_SOURCES} ${CLIENT_SOURCES})
target_compile_definitions(client PRIVATE IS_CLIENT)
target_include_directories(client PRIVATE "${ASIO_PATH}/include" "${source_dir}/src/common/include")
target_link_libraries(client 
  PRIVATE 
    common
    raylib
)