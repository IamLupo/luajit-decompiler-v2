#ifndef BYTECODE_TABLE_H
#define BYTECODE_TABLE_H

enum BC_KTAB : uint8_t
{
	BC_KTAB_NIL, // primitive nil
	BC_KTAB_FALSE, // primitive false
	BC_KTAB_TRUE, // primitive true
	BC_KTAB_INT, // integer constant
	BC_KTAB_NUM, // number constant
	BC_KTAB_STR  // string constant
};

struct TableConstant
{
	BC_KTAB type;

	union
	{
		uint32_t integer;
		uint64_t number = 0;
	};

	std::string string;
};

struct TableNode
{
	Bytecode::TableConstant key;
	Bytecode::TableConstant value;
};

#endif // BYTECODE_TABLE_H
