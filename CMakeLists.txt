# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(TEDemo VERSION 0.1.0)

# C++ stuff
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# add main.cpp
add_executable(TEDemo src/main.cpp)

# add engine/CMakeLists.txt
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)

# add compiled lib
set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/engine/out")
file(GLOB ENGINE "${LIBRARY_PATH}/*TermEngine_*.*.*.*")

message(STATUS "Found following engine libraries in ${LIBRARY_PATH}: ${ENGINE}")

target_link_libraries(TEDemo ${ENGINE})
