cmake_minimum_required(VERSION 3.16)
project(SFMLGame)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "/opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

include_directories("/opt/homebrew/Cellar/sfml@2/2.6.2_1/include")

add_executable(SFMLGame main.cpp
        src/Ball.cpp
        src/Ball.h
        src/Paddle.cpp
        src/Paddle.h)

target_link_libraries(SFMLGame
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)
