#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

#include <ast/ast.h>

enum AST_VARIABLE : uint8_t
{
	AST_VARIABLE_SLOT,
	AST_VARIABLE_UPVALUE,
	AST_VARIABLE_GLOBAL,
	AST_VARIABLE_TABLE_INDEX
};

struct Variable
{
	AST_VARIABLE type;
	uint8_t slot = 0;
	Ast::SlotScope** slotScope = nullptr;
	std::string name;
	Ast::Expression* table = nullptr;
	Ast::Expression* tableIndex = nullptr;
	bool isMultres = false;
	uint32_t multresIndex = 0;
};

#endif // AST_VARIABLE_H
