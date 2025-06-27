cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)

## Release
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -s -O2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s -O2")

## Add Project
project(luajit-decompiler-v2 VERSION 1.0.0)

## Executable
add_executable(luajit-decompiler-v2
	src/main.h
    src/main.cpp
	src/ast/ast.h
	src/ast/ast.cpp
	src/ast/building_blocks.h
	src/ast/conditionBuilder.h
	src/ast/function.h
	src/bytecode/bytecode.h
	src/bytecode/bytecode.cpp
	src/bytecode/constants.h
	src/bytecode/instructions.h
	src/bytecode/prototype.h
	src/bytecode/prototype.cpp
    src/lua/lua.cpp
	src/lua/lua.h
)

## Todo: Should be removed over time.
## All std::string and char cases needs to be patched to unsigned char or cast to correct type.
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /J")
	message("Add /J in Visual studio")
endif()

include_directories(luajit-decompiler-v2 src)
#target_link_libraries(luajit mysqlclient ssl crypto jsoncpp_static atomizes)