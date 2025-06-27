#include <ast/ast.h>

Ast::Expression::Expression(const AST_EXPRESSION& type)
{
	set_type(type);
}

Ast::Expression::~Expression()
{
	delete_type();
}

void Ast::Expression::set_type(const AST_EXPRESSION& type)
{
	delete_type();
	this->type = type;

	switch (type) {
	case AST_EXPRESSION_CONSTANT:
		constant = new Constant;
		break;
	case AST_EXPRESSION_VARARG:
		returnCount = 0;
		break;
	case AST_EXPRESSION_VARIABLE:
		variable = new Variable;
		break;
	case AST_EXPRESSION_FUNCTION_CALL:
		functionCall = new FunctionCall;
		break;
	case AST_EXPRESSION_TABLE:
		table = new Table;
		break;
	case AST_EXPRESSION_BINARY_OPERATION:
		binaryOperation = new BinaryOperation;
		break;
	case AST_EXPRESSION_UNARY_OPERATION:
		unaryOperation = new UnaryOperation;
		break;
	}
}

void Ast::Expression::delete_type()
{
	switch (type) {
	case AST_EXPRESSION_CONSTANT:
		delete constant;
		constant = nullptr;
		break;
	case AST_EXPRESSION_FUNCTION:
		function = nullptr;
		break;
	case AST_EXPRESSION_VARIABLE:
		delete variable;
		variable = nullptr;
		break;
	case AST_EXPRESSION_FUNCTION_CALL:
		delete functionCall;
		functionCall = nullptr;
		break;
	case AST_EXPRESSION_TABLE:
		delete table;
		table = nullptr;
		break;
	case AST_EXPRESSION_BINARY_OPERATION:
		delete binaryOperation;
		binaryOperation = nullptr;
		break;
	case AST_EXPRESSION_UNARY_OPERATION:
		delete unaryOperation;
		unaryOperation = nullptr;
		break;
	}
}
