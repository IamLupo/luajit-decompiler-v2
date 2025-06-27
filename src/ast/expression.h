#ifndef AST_EXPRESSION_H
#define AST_EXPRESSION_H

#include <ast/ast.h>

enum AST_EXPRESSION : uint8_t
{
	AST_EXPRESSION_CONSTANT,
	AST_EXPRESSION_VARARG,
	AST_EXPRESSION_FUNCTION,
	AST_EXPRESSION_VARIABLE,
	AST_EXPRESSION_FUNCTION_CALL,
	AST_EXPRESSION_TABLE,
	AST_EXPRESSION_BINARY_OPERATION,
	AST_EXPRESSION_UNARY_OPERATION
};

struct Expression
{
	Expression(const AST_EXPRESSION& type);
	~Expression();

	void set_type(const AST_EXPRESSION& type);
	void delete_type();

	AST_EXPRESSION type;

	union {
		Ast::Constant* constant = nullptr;
		Ast::Function* function;
		Ast::Variable* variable;
		Ast::FunctionCall* functionCall;
		Ast::Table* table;
		Ast::BinaryOperation* binaryOperation;
		Ast::UnaryOperation* unaryOperation;
		uint8_t returnCount;
	};
};

#endif // AST_EXPRESSION_H
