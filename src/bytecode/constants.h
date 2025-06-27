#ifndef BYTECODE_CONSTANT_H
#define BYTECODE_CONSTANT_H

#include <bytecode/bytecode.h>

static constexpr uint8_t BC_HEADER[] = { '\x1B', 'L', 'J' };
static constexpr uint8_t BC_HEADER_FS[] = { '\x1B', 'F', 'S' };
static constexpr uint8_t BC_VERSION_1 = 1;
static constexpr uint8_t BC_VERSION_2 = 2;
static constexpr uint8_t BC_VERSION_3 = 130;
static constexpr uint8_t BC_F_BE = 0x01;
static constexpr uint8_t BC_F_STRIP = 0x02;
static constexpr uint8_t BC_F_FFI = 0x04;
static constexpr uint8_t BC_F_FR2 = 0x08;
static constexpr uint8_t BC_PROTO_CHILD = 0x01;
static constexpr uint8_t BC_PROTO_VARARG = 0x02;
static constexpr uint8_t BC_PROTO_FFI = 0x04;
static constexpr uint16_t BC_UV_IMMUTABLE = 0x4000;
static constexpr uint16_t BC_UV_LOCAL = 0x8000;

enum BC_KGC : uint8_t
{
	BC_KGC_CHILD, // child prototype
	BC_KGC_TAB, // table constant
	BC_KGC_I64, // signed integer cdata constant
	BC_KGC_U64, // unsigned integer cdata constant
	BC_KGC_COMPLEX, // imaginary number cdata constant
	BC_KGC_STR // string constant
};

struct Constant
{
	BC_KGC type;
	const Bytecode::Prototype* prototype = nullptr;
	std::vector<Bytecode::TableConstant> array;
	std::vector<Bytecode::TableNode> table;
	uint64_t cdata = 0;
	std::string string;
};

#endif // BYTECODE_CONSTANT_H
