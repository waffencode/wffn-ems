cmake_minimum_required(VERSION 3.0.0)
project(wffn-ems VERSION 0.0.1)

include(CTest)
enable_testing()
set(SRC_LIST 
    src/main.cpp 
    src/client/menu_contoller.cpp
    src/client/menu_pool.cpp
    src/client/dialog/add_employee_dialog.cpp
    src/client/dialog/show_employee_dialog.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-newline-eof")

add_executable(${PROJECT_NAME} ${SRC_LIST})

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)