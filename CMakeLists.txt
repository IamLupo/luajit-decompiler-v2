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
	src/util.h
	src/util.cpp

	src/ast/ast.h
	src/ast/ast.cpp
	src/ast/binary_operation.h
	src/ast/constant.h
	src/ast/condition_builder.h
	src/ast/condition_builder.cpp
	src/ast/expression.h
	src/ast/expression.cpp
	src/ast/function.h
	src/ast/function.cpp
	src/ast/functioncall.h
	src/ast/local.h
	src/ast/slotscope.h
	src/ast/statement.h
	src/ast/table.h
	src/ast/unary_operation.h
	src/ast/variable.h

	src/bytecode/bytecode.h
	src/bytecode/bytecode.cpp
	src/bytecode/constants.h
	src/bytecode/instructions.h
	src/bytecode/number_constant.h
	src/bytecode/prototype.h
	src/bytecode/prototype.cpp
	src/bytecode/table.h
	src/bytecode/variable_info.h

	src/lua/lua.cpp
	src/lua/lua.h
)

if(MSVC)
	# Setup Visual Studio filters
	source_group("ast" FILES
		src/ast/ast.h
		src/ast/ast.cpp
		src/ast/binary_operation.h
		src/ast/constant.h
		src/ast/condition_builder.h
		src/ast/condition_builder.cpp
		src/ast/expression.h
		src/ast/expression.cpp
		src/ast/function.h
		src/ast/function.cpp
		src/ast/functioncall.h
		src/ast/local.h
		src/ast/slotscope.h
		src/ast/statement.h
		src/ast/table.h
		src/ast/unary_operation.h
		src/ast/variable.h
	)

	source_group("bytecode" FILES
		src/bytecode/bytecode.h
		src/bytecode/bytecode.cpp
		src/bytecode/constants.h
		src/bytecode/instructions.h
		src/bytecode/number_constant.h
		src/bytecode/prototype.h
		src/bytecode/prototype.cpp
		src/bytecode/table.h
		src/bytecode/variable_info.h
	)

	source_group("lua" FILES
		src/lua/lua.cpp
		src/lua/lua.h
	)

	source_group("" FILES
		src/main.cpp
		src/main.h
		src/util.cpp
		src/util.h
	)	

	## Todo: Should be removed over time.
	## All std::string and char cases needs to be patched to unsigned char or cast to correct type.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /J")
	message("Add /J in Visual studio")
endif()

include_directories(luajit-decompiler-v2 src)
#target_link_libraries(luajit mysqlclient ssl crypto jsoncpp_static atomizes)