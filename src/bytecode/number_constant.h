#ifndef BYTECODE_NUMBER_CONSTANT_H
#define BYTECODE_NUMBER_CONSTANT_H

#include <bytecode/bytecode.h>

enum BC_KNUM : uint8_t
{
	BC_KNUM_INT, // integer constant
	BC_KNUM_NUM // number constant
};

struct NumberConstant {
	BC_KNUM type;

	union {
		uint32_t integer;
		uint64_t number = 0;
	};
};

#endif // BYTECODE_NUMBER_CONSTANT_H
