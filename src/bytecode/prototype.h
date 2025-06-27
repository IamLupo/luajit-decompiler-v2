#ifndef BYTECODE_PROTOTYPE_H
#define BYTECODE_PROTOTYPE_H

#include <bytecode/bytecode.h>

class Prototype
{
	public:
		Prototype(const Bytecode& bytecode);

		void operator()(std::vector<Prototype*>& unlinkedPrototypes);

		struct {
			uint8_t flags = 0;
			uint8_t parameters = 0;
			uint8_t framesize = 0;
			bool hasDebugInfo = false;
			uint32_t firstLine = 0;
			uint32_t lineCount = 0;
		} header;

		std::vector<Bytecode::Instruction> instructions;
		std::vector<uint16_t> upvalues;
		std::vector<Bytecode::Constant> constants;
		std::vector<Bytecode::NumberConstant> numberConstants;
		std::vector<uint32_t> lineMap;
		std::vector<std::string> upvalueNames;
		std::vector<Bytecode::VariableInfo> variableInfos;
		uint32_t prototypeSize = 0;

	private:

		void read_header();
		void read_instructions();
		void read_upvalues();
		void read_constants(std::vector<Prototype*>& unlinkedPrototypes);
		void read_number_constants();
		void read_debug_info();
		uint8_t get_next_byte();
		uint32_t get_uleb128();
		uint32_t get_uleb128_33();
		std::string get_string();
		Bytecode::TableConstant get_table_constant();

		const Bytecode& bytecode;
};

#endif // BYTECODE_H
