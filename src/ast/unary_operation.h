#ifndef AST_UNARY_OPERATION_H
#define AST_UNARY_OPERATION_H

#include <ast/ast.h>

enum AST_UNARY_OPERATION : uint8_t
{
	AST_UNARY_MINUS,
	AST_UNARY_NOT,
	AST_UNARY_LENGTH
};

struct UnaryOperation
{
	AST_UNARY_OPERATION type;
	Ast::Expression* operand = nullptr;
};

#endif // AST_UNARY_OPERATION_H
