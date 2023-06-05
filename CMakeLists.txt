cmake_minimum_required(VERSION 3.0.0)
project(wffn-ems VERSION 0.0.1)

set(SRC_LIST 
    src/main.cpp 
    src/client/menu_contoller.cpp
    src/client/menu_pool.cpp
    src/client/dialog/add_employee_dialog.cpp
    src/client/dialog/show_employee_dialog.cpp
    src/client/dialog/employee_profile_dialog.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
