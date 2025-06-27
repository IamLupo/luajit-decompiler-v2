#ifndef AST_STATEMENT_H
#define AST_STATEMENT_H

#include <ast/ast.h>

enum AST_STATEMENT : uint8_t
{
	AST_STATEMENT_EMPTY,
	AST_STATEMENT_INSTRUCTION,
	AST_STATEMENT_RETURN,
	AST_STATEMENT_CONDITION,
	AST_STATEMENT_GOTO,
	AST_STATEMENT_NUMERIC_FOR,
	AST_STATEMENT_GENERIC_FOR,
	AST_STATEMENT_LOOP,
	AST_STATEMENT_BREAK,
	AST_STATEMENT_DECLARATION,
	AST_STATEMENT_ASSIGNMENT,
	AST_STATEMENT_FUNCTION_CALL,
	AST_STATEMENT_IF,
	AST_STATEMENT_ELSE,
	AST_STATEMENT_WHILE,
	AST_STATEMENT_REPEAT,
	AST_STATEMENT_DO,
	AST_STATEMENT_LABEL
};

struct Statement
{
	Statement(const AST_STATEMENT& type) : type(type) {}

	AST_STATEMENT type;

	struct {
		Bytecode::BC_OP type = Bytecode::BC_OP_INVALID;
		uint8_t a = 0;
		uint8_t b = 0;
		uint8_t c = 0;
		uint16_t d = 0;
		uint32_t id = Ast::INVALID_ID;
		uint32_t target = Ast::INVALID_ID;
		uint32_t label = Ast::INVALID_ID;
	} instruction;

	Ast::Function* function = nullptr;
	std::vector<Statement*> block;
	Ast::Local* locals = nullptr;

	struct {
		bool allowSlotSwap = false;
		bool swapped = false;
	} condition;

	struct
	{
		void register_slots(Expression*& expression)
		{
			openSlots.emplace_back(&expression);
		}

		template <typename... Expressions>
		void register_slots(Expression*& expression, Expressions*&... expressions)
		{
			openSlots.emplace_back(&expression);
			return register_slots(expressions...);
		}

		bool isPotentialMethod = false;
		bool isTableConstructor = false;
		bool forwardDeclaration = false;
		Ast::CONSTANT_TYPE allowedConstantType = Ast::CONSTANT_TYPE::NUMBER_CONSTANT;
		std::vector<Ast::Variable> variables;
		std::vector<Ast::Expression*> expressions;
		std::vector<Ast::Expression**> openSlots;
		Ast::Expression* multresReturn = nullptr;
	} assignment;
};

#endif // AST_STATEMENT_H
