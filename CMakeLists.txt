cmake_minimum_required(VERSION 3.16)

project(multiplayer-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# --- Defina o caminho para sua instalação local do Raylib ---
# Usamos $ENV{HOME} porque o CMake não entende o atalho '~'.
set(RAYLIB_PATH "$ENV{HOME}/dev/raylib")


set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")

add_executable(multiplayer-server ${source_files})

# --- Configure as dependências do Raylib ---

# 1. Adicione o diretório dos arquivos de cabeçalho (.h)
#    Isso permite que você use #include "raylib.h" no seu código.
target_include_directories(multiplayer-server PRIVATE "${RAYLIB_PATH}/src")

# 2. Link a biblioteca estática (.a) que você compilou.
#    Este é o passo que conecta o código do Raylib ao seu programa.
target_link_libraries(multiplayer-server PRIVATE "${RAYLIB_PATH}/src/libraylib.a")


# --- NÃO ESQUEÇA: Raylib precisa de outras bibliotecas do sistema ---
# No Linux, estas são geralmente necessárias.
target_link_libraries(multiplayer-server PRIVATE -lGL -lm -lpthread -ldl -lrt -lX11)