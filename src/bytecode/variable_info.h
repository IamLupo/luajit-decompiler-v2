#ifndef BYTECODE_VARIABLE_INFO_H
#define BYTECODE_VARIABLE_INFO_H

#include <bytecode/bytecode.h>

enum BC_VAR : uint8_t
{
	BC_VAR_END, // end of variable info
	BC_VAR_FOR_IDX, // for numeric loop index
	BC_VAR_FOR_STOP, // for numeric loop limit
	BC_VAR_FOR_STEP, // for numeric loop step
	BC_VAR_FOR_GEN, // for generic loop generator
	BC_VAR_FOR_STATE, // for generic loop state
	BC_VAR_FOR_CTL, // for generic loop control
	BC_VAR_STR // local variable name
};

struct VariableInfo
{
	BC_VAR type;
	std::string name;
	bool isParameter = false;
	uint32_t scopeBegin = 0;
	uint32_t scopeEnd = 0;
};

#endif // BYTECODE_NUMBER_CONSTANT_H
