#ifndef AST_CONDITION_BUILDER_H
#define AST_CONDITION_BUILDER_H

#include <ast/ast.h>

struct ConditionBuilder
{
	enum TYPE : uint8_t
	{
		ASSIGNMENT,
		STATEMENT
	} const type;

	struct Node
	{
		enum TYPE : uint8_t
		{
			LESS_THAN,
			LESS_EQUAL,
			GREATER_THEN,
			GREATER_EQUAL,
			NOT_LESS_THAN,
			NOT_LESS_EQUAL,
			NOT_GREATER_THEN,
			NOT_GREATER_EQUAL,
			EQUAL,
			NOT_EQUAL,
			TRUTHY_TEST,
			FALSY_TEST,
			BOOL_TRUTHY_TEST,
			BOOL_FALSY_TEST,
			UNCONDITIONAL,
			AND,
			OR,
			NOT_AND,
			NOT_OR,
			END_TARGET,
			TRUE_TARGET,
			FALSE_TARGET,
		} type;

		static constexpr uint8_t TYPE_PREFERENCE[TYPE::END_TARGET][2] = {
			{ 3, 1 },
			{ 3, 1 },
			{ 3, 1 },
			{ 3, 1 },
			{ 1, 3 },
			{ 1, 3 },
			{ 1, 3 },
			{ 1, 3 },
			{ 3, 3 },
			{ 3, 3 },
			{ 3, 2 },
			{ 2, 3 },
			{ 0, 0 },
			{ 0, 0 },
			{ 3, 3 },
			{ 3, 0 },
			{ 3, 0 },
			{ 0, 3 },
			{ 0, 3 }
		};

		Node(const TYPE& type) : type(type) {}

		uint32_t nodeLabel = Ast::INVALID_ID;
		uint32_t targetLabel = Ast::INVALID_ID;
		Node* targetNode = nullptr;
		uint32_t incomingNodes = 0;
		bool inverted = false;
		std::vector<Ast::Expression*>* expressions = nullptr;
		Node* leftNode = nullptr;
		Node* rightNode = nullptr;
	};

	ConditionBuilder(const TYPE& type, Ast& ast, const uint32_t& endTargetLabel, const uint32_t& trueTargetLabel, const uint32_t& falseTargetLabel);
	~ConditionBuilder();

	Node*& new_node(const Node::TYPE& type);
	static Node::TYPE get_node_type(const Bytecode::BC_OP& instruction, const bool& swapped);
	void add_node(const Node::TYPE& type, const uint32_t& nodeLabel, const uint32_t& targetLabel, std::vector<Ast::Expression*>* const& expressions);

	bool link_nodes();
	void fix_return_nodes();
	bool build_boolean_logic();
	static bool invert_any_node(Node* const& leftNode, Node* const& rightNode);
	static void invert_node(Node* const& node);
	Node* copy_node(Node* const& node);
	void merge_nodes(Node* const& node, Node* const& targetNode);
	Ast::Expression* build_expression(Node* const& node);
	Ast::Expression* build_not(Ast::Expression* const& operand);
	Ast::Expression* build_binary(const Node::TYPE& type, Ast::Expression* const& leftOperand, Ast::Expression* const& rightOperand);
	Ast::Expression* build_condition();

	Ast& ast;
	std::vector<Node*> nodes;
	std::vector<Node*> conditionNodes;
	Node* endTarget = nullptr;
	Node* trueTarget = nullptr;
	Node* falseTarget = nullptr;
};

#endif // AST_CONDITION_BUILDER_H
