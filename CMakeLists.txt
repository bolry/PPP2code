cmake_minimum_required(VERSION 3.12)

project(ProjNameHere)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

#if (UNIX AND NOT APPLE)
#    execute_process(COMMAND ${CMAKE_C_COMPILER} -fuse-ld=gold -Wl,--version ERROR_QUIET OUTPUT_VARIABLE ld_version)
#    if ("${ld_version}" MATCHES "GNU gold")
#        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold -Wl,--disable-new-dtags")
#        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=gold -Wl,--disable-new-dtags")
#    endif ()
#endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

find_package(FLTK REQUIRED)

add_subdirectory(../../contrib/googletest.git googletest.build)
add_subdirectory(calculator)
add_subdirectory(chap6.3)


set(SOURCE_FILES main.cpp Simple_window.h GUI.cpp GUI.h Window.cpp Window.h fltk.h std_lib_facilities.h Point.h Graph.cpp Graph.h)
add_executable(ExeNameHere ${SOURCE_FILES})
target_include_directories(ExeNameHere PRIVATE ${FLTK_INCLUDE_DIR})
#target_link_libraries(ExeNameHere Threads::Threads)
target_link_libraries(ExeNameHere ${FLTK_LIBRARY})# X11 Xext Xfixes Xrender dl jpeg)
