cmake_minimum_required(VERSION 3.1)
project(cryptoApp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#include_directories(include)

set(SOURCES
    src/main.cpp
)

#set(HEADER_FILES
#    include/Database.hpp
#    include/Employee.hpp
#    include/Person.hpp
#    include/PersonalID.hpp
#    include/Student.hpp
#)

add_compile_options(-Wall -Wextra -Werror -Wpedantic)

#add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER_FILES})

add_executable(${PROJECT_NAME} ${SOURCES})

