add_executable(calculate6.3.1)
target_sources(calculate6.3.1 PRIVATE calculator6.3.1.m.cpp)
target_include_directories(calculate6.3.1 PRIVATE ..)

add_executable(calculate6.3.3)
target_sources(calculate6.3.3 PRIVATE calculator6.3.3.m.cpp Token.h)
target_include_directories(calculate6.3.3 PRIVATE ..)
