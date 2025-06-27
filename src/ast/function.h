#ifndef AST_FUNCTION_H
#define AST_FUNCTION_H

#include <ast/ast.h>

struct Function
{
	struct Upvalue
	{
		uint8_t slot = 0;
		Ast::SlotScope** slotScope = nullptr;
		bool local = false;
	};

	struct Label
	{
		std::string name;
		uint32_t target = Ast::INVALID_ID;
		std::vector<uint32_t> jumpIds;
	};

	Function(const Bytecode::Prototype& prototype, const uint32_t& level, const bool& ignoreDebugInfo);
	~Function();

	const Bytecode::Constant& get_constant(const uint16_t& index) const;
	const Bytecode::NumberConstant& get_number_constant(const uint16_t& index) const;
	void add_jump(const uint32_t& id, const uint32_t& target);
	void remove_jump(const uint32_t& id, const uint32_t& target);
	uint32_t get_label_from_id(const uint32_t& id);
	bool is_valid_label(const uint32_t& label);
	uint32_t get_scope_begin_from_label(const uint32_t& label, const uint32_t& scopeEnd);
	uint32_t get_scope_end_from_label(const uint32_t& label);
	bool is_valid_block_range(const uint32_t& blockBegin, const uint32_t& blockEnd, const bool& ignoreFrontLabel);

	const Bytecode::Prototype& prototype;
	const bool isVariadic, hasDebugInfo;
	const uint32_t level;
	uint32_t id = 0;
	bool assignmentSlotIsUpvalue = false;
	std::vector<Ast::Local> locals;
	std::vector<Upvalue> upvalues;
	std::vector<Label> labels;
	std::vector<std::string> parameterNames;
	std::vector<Ast::Statement*> block;
	std::vector<Function*> childFunctions;
	std::vector<const std::string*> usedGlobals;

	struct SlotScopeCollector
	{
		struct UpvalueInfo
		{
			enum TYPE : uint8_t
			{
				JUMP,
				UPVALUES,
				UPVALUE_CLOSE
			} type;

			uint32_t id = Ast::INVALID_ID;
			uint32_t target = Ast::INVALID_ID;
			std::vector<uint8_t> upvalues;
			uint8_t baseSlot = 0;
		};

		struct UpvalueScope {
			uint8_t slot = 0;
			uint32_t minScopeBegin = Ast::INVALID_ID;
			uint32_t minScopeEnd = Ast::INVALID_ID;
		};

		struct SlotInfo {
			bool isParameter = false;
			Ast::SlotScope** activeSlotScope = nullptr;
			uint32_t minScopeBegin = Ast::INVALID_ID;
			std::vector<Ast::SlotScope**> slotScopes;
		};

		Ast::SlotScope** new_slot_scope();
		uint32_t add_upvalue_info(const uint32_t& id, const UpvalueInfo::TYPE& type);
		void add_upvalues(const uint32_t& id, std::vector<uint8_t>& upvalues);
		void add_jump(const uint32_t& id, const uint32_t& target);
		void add_upvalue_close(const uint32_t& id, const uint32_t& target, const uint8_t& baseSlot);
		void add_loop(const uint32_t& id, const uint32_t& target);
		void add_upvalue_scope(const uint8_t& slot, const uint32_t& minScopeBegin, const uint32_t& minScopeEnd);
		void build_upvalue_scopes();
		void begin_scope(const uint8_t& slot, const uint32_t& id);
		void begin_upvalue_scopes(const uint32_t& id);
		void add_to_scope(const uint8_t& slot, Ast::SlotScope**& slotScope, const uint32_t& id);
		void close_scope(const uint8_t& slot, Ast::SlotScope**& slotScope, const uint32_t& id);
		void extend_scope(const uint8_t& slot, const uint32_t& id);
		void extend_scopes(const uint32_t& id);
		void merge_scopes(const uint32_t& id);
		bool assert_scopes_closed();
		void remove_scope(const uint8_t& slot, Ast::SlotScope** const& slotScope);

		std::vector<UpvalueInfo> upvalueInfos;
		std::vector<UpvalueScope> upvalueScopes;
		std::vector<Ast::Function::SlotScopeCollector::SlotInfo> slotInfos;
		std::vector<Ast::SlotScope*> slotScopes;
		uint32_t previousId = Ast::INVALID_ID;
	} slotScopeCollector;
};

#endif // AST_FUNCTION_H