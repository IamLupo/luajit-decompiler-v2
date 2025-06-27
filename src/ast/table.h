#ifndef AST_TABLE_H
#define AST_TABLE_H

#include <ast/ast.h>

struct Table
{
	struct Field
	{
		Ast::Expression* key = nullptr;
		Ast::Expression* value = nullptr;
	};

	struct
	{
		std::vector<Ast::Expression*> list;
		std::vector<Field> fields;
	} constants;

	std::vector<Field> fields;
	uint32_t multresIndex = 0;
	Ast::Expression* multresField = nullptr;
};

#endif // AST_TABLE_H
