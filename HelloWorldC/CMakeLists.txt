cmake_minimum_required(VERSION 3.19)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)
#if(MSVC)
#    set(CMAKE_C_FLAGS "/utf8")
#endif()

include_directories("include")
include_directories("tinycthread/include")

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} src/factorial.c tinycthread/tinycthread.c)
    target_compile_definitions(${name} PUBLIC DEBUG)

    if (UNIX OR Linux)
        target_link_libraries(${name} pthread)
    endif()
endforeach()