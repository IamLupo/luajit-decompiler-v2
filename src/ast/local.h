#ifndef AST_LOCAL_H
#define AST_LOCAL_H

#include <ast/ast.h>

struct Local
{
	std::vector<std::string> names;
	uint8_t baseSlot = 0;
	uint32_t scopeBegin = Ast::INVALID_ID;
	uint32_t scopeEnd = Ast::INVALID_ID;
	bool excludeBlock = false;
};

#endif // AST_LOCAL_H
