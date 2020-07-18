project(main_prog)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Gui 3DCore 3DRender 3DInput 3DExtras REQUIRED)

# All sources that also need to be tested in unit tests go into a static library
add_library(main_lib "")
target_sources(main_lib
    PRIVATE
    dungeon.cpp
    dungeon.hpp
    dungeon_modifier.cpp
    dungeon_modifier.hpp
    editor_window.cpp
    editor_window.hpp
    orbit_transform_controller.cpp
    orbit_transform_controller.hpp
    )
target_include_directories(main_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(main_lib PUBLIC cxx_std_17)
target_link_libraries(main_lib PUBLIC Qt5::Core)

# The main program
add_executable(main_prog main.cpp application.qrc)
target_link_libraries(main_prog PUBLIC main_lib
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    Qt5::3DCore
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DExtras
    )
