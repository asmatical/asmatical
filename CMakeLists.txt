cmake_minimum_required(VERSION 3.28)
project(asmatical C)

set(CMAKE_C_STANDARD 90)

#if(MSVC)
#    target_compile_options(${TARGET_NAME} /W4 /WX)
#else()
#    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
#endif()

add_executable(asmatical main.c
        token.c
        token.h
        parse.c
        parse.h)
