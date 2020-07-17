cmake_minimum_required(VERSION 3.16)
project(main_project)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall)
endif()

add_subdirectory(thirdparty/catch)
add_subdirectory(src)
add_subdirectory(test)
