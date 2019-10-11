add_executable(c )
target_sources(c PRIVATE c.m.cpp)
target_include_directories(c PRIVATE ..)

add_executable(calculator00)
target_sources(calculator00 PRIVATE calculator00.cpp)
target_include_directories(calculator00 PRIVATE ..)