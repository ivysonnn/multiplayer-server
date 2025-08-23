cmake_minimum_required(VERSION 3.16)

project(net-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(source_dir "${PROJECT_SOURCE_DIR}") 

set(RAYLIB_PATH "$ENV{HOME}/dev/raylib")
set(ASIO_PATH "$ENV{HOME}/dev/asio")

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

add_library(common ${COMMON_SOURCES})

target_include_directories(common PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/common/include>
)


add_executable(server ${SERVER_SOURCES})
target_include_directories(server PRIVATE common "${ASIO_PATH}/include")

target_compile_definitions(server PRIVATE IS_SERVER)

add_executable(client ${COMMON_SOURCES} ${CLIENT_SOURCES})
target_include_directories(client PRIVATE "${ASIO_PATH}/include" "${RAYLIB_PATH}/src")
target_link_libraries(client 
  PRIVATE
    common 
    "${RAYLIB_PATH}/src/libraylib.a" 
    GL m pthread dl rt X11 # Bibliotecas que a Raylib precisa no Linux
)

target_compile_definitions(client PRIVATE IS_CLIENT)