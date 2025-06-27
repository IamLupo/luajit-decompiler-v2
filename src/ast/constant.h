#ifndef AST_CONSTANT_H
#define AST_CONSTANT_H

#include <ast/ast.h>

enum AST_CONSTANT
{
	AST_CONSTANT_NIL,
	AST_CONSTANT_FALSE,
	AST_CONSTANT_TRUE,
	AST_CONSTANT_NUMBER,
	AST_CONSTANT_CDATA_SIGNED,
	AST_CONSTANT_CDATA_UNSIGNED,
	AST_CONSTANT_CDATA_IMAGINARY,
	AST_CONSTANT_STRING
};

struct Constant
{
	AST_CONSTANT type;

	union {
		double number;
		int64_t signed_integer;
		uint64_t unsigned_integer = 0;
	};

	std::string string;
	bool isName = false;
};

#endif // AST_CONSTANT_H
