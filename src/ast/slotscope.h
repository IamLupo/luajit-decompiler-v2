#ifndef AST_SLOTSCOPE_H
#define AST_SLOTSCOPE_H

#include <ast/ast.h>

struct SlotScope
{
	Ast::SlotScope* slotScope = this;
	std::vector<Ast::SlotScope**> mergedScopes;
	std::string name;
	uint32_t scopeBegin = Ast::INVALID_ID;
	uint32_t scopeEnd = Ast::INVALID_ID;
	uint32_t usages = 0;
};

#endif // AST_SLOTSCOPE_H
