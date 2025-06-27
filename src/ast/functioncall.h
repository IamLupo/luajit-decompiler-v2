#ifndef AST_FUNCTIONCALL_H
#define AST_FUNCTIONCALL_H

#include <ast/ast.h>

struct FunctionCall
{
	Ast::Expression* function = nullptr;
	std::vector<Ast::Expression*> arguments;
	Ast::Expression* multresArgument = nullptr;
	bool isMethod = false;
	uint8_t returnCount = 0;
};

#endif // AST_FUNCTIONCALL_H
