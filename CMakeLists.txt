cmake_minimum_required(VERSION 3.5)

project(ATM_SYSTEM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ATM_SYSTEM main.cpp)

install(TARGETS ATM_SYSTEM
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
