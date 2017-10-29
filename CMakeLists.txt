cmake_minimum_required(VERSION 3.9)

if (UNIX AND NOT APPLE)
    execute_process(COMMAND ${CMAKE_C_COMPILER} -fuse-ld=gold -Wl,--version ERROR_QUIET OUTPUT_VARIABLE ld_version)
    if ("${ld_version}" MATCHES "GNU gold")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold -Wl,--disable-new-dtags")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=gold -Wl,--disable-new-dtags")
    endif ()
endif ()

project(ProjNameHere)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

find_package(FLTK REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Simple_window.h GUI.cpp GUI.h Window.cpp Window.h fltk.h std_lib_facilities.h Point.h Graph.cpp Graph.h)
add_executable(ExeNameHere ${SOURCE_FILES})
target_include_directories(ExeNameHere PRIVATE ${FLTK_INCLUDE_DIR})
#target_link_libraries(ExeNameHere Threads::Threads)
target_link_libraries(ExeNameHere ${FLTK_LIBRARY} m X11 Xext Xfixes Xrender dl jpeg)
