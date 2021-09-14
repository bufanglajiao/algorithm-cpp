cmake_minimum_required(VERSION 3.19)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)
#if(MSVC)
#    set(CMAKE_C_FLAGS "/utf8")
#endif()

# gtk
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
PKG_CHECK_MODULES(GMODULE REQUIRED gmodule-export-2.0 )

INCLUDE_DIRECTORIES(${GMODULE_INCLUDE_DIRS})
LINK_DIRECTORIES(${GMODULE_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

include_directories("include")
include_directories("tinycthread/include")

set(CMAKE_C_FLAGS_RELEASE -mwindows)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} src/factorial.c tinycthread/tinycthread.c)
    target_compile_definitions(${name} PUBLIC DEBUG)

    target_link_libraries(${name} ${GTK3_LIBRARIES})
    target_link_libraries(${name} ${GMODULE_LIBRARIES})

    if (UNIX OR Linux)
        target_link_libraries(${name} pthread)
    endif()
endforeach()