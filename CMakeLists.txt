cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME alife)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE header_files *.h)
file(GLOB_RECURSE source_files *.cpp)
file(GLOB_RECURSE fonts res/Fonts/*)
file(GLOB_RECURSE langs res/Languages/*)

set(SOURCES ${source_files})
set(HEADERS ${header_files})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)

FILE(COPY ${fonts} DESTINATION "${CMAKE_BINARY_DIR}/res/Fonts")
FILE(COPY ${langs} DESTINATION "${CMAKE_BINARY_DIR}/res/Languages")
