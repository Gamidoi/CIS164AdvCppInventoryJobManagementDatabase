cmake_minimum_required(VERSION 3.10)
project(FinalProjectCIS164InventoryJobManagementDatabase)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)


add_executable(FinalProjectCIS164InventoryJobManagementDatabase
        main.cpp
        objects/Item.cpp
        objects/Item.h
        serverlogonpage.cpp
        serverlogonpage.h
        serverlogonpage.ui
        util/sqlConnection.cpp
        util/sqlConnection.h
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        objects/Customer.cpp
        objects/Customer.h
)

target_link_libraries(
        FinalProjectCIS164InventoryJobManagementDatabase
        PRIVATE
        Qt6::Sql
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

if(WIN32)
    qt_standard_project_setup()
    qt_finalize_executable(FinalProjectCIS164InventoryJobManagementDatabase)
endif()

