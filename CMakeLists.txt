cmake_minimum_required(VERSION 3.10)
project(FinalProjectCIS164InventoryJobManagementDatabase)

set(CMAKE_CXX_STANDARD 20)
add_executable(FinalProjectCIS164InventoryJobManagementDatabase
        main.cpp
        objects/Item.cpp
        objects/Item.h
)

target_include_directories(
        FinalProjectCIS164InventoryJobManagementDatabase
        PRIVATE "C:/Program Files/MySQL/MySQL Connector C++ 9.6/include/jdbc"
)

target_link_libraries(
        FinalProjectCIS164InventoryJobManagementDatabase
        PRIVATE
        "C:/Program Files/MySQL/MySQL Connector C++ 9.6/lib64/vs14/mysqlcppconn.lib"
)

