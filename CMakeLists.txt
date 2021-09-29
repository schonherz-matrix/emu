cmake_minimum_required(VERSION 3.16)

project(
        emu
        DESCRIPTION "Emulator for Schönherz Mátrix network traffic"
        HOMEPAGE_URL "kszk.bme.hu"
        LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
        Qt6
        COMPONENTS Core Quick
        REQUIRED)

add_executable(
        ${PROJECT_NAME} WIN32
        app/main.cpp app/schcoords.h app/resources.qrc app/qml/qml.qrc
        app/schonherzitem.cpp app/schonherzitem.hpp)

target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick
        muebreceiver)