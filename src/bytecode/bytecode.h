#ifndef BYTECODE_H
#define BYTECODE_H

#include <windows.h>
#include <vector>
#include <string>

class Bytecode
{
	/* Forward declare */
	public:
		struct Constant;
		struct Instruction;
		struct NumberConstant;
		class Prototype;
		struct TableConstant;
		struct TableNode;
		struct VariableInfo;

	/* Consts, enum and struct */
	public:
		struct {
			uint8_t version = 0;
			uint8_t flags = 0;
			std::string chunkname;
		} header;

	private:
		static constexpr uint8_t MIN_PROTO_SIZE = 11;
		static constexpr uint8_t MIN_FILE_SIZE = MIN_PROTO_SIZE + 7;

	/* Includes */
	public:	
#include <bytecode/constants.h>
#include <bytecode/instructions.h>
#include <bytecode/number_constant.h>
#include <bytecode/prototype.h>
#include <bytecode/table.h>
#include <bytecode/variable_info.h>

	/* Variables */
	public:
		const std::string filePath;
		const Prototype* main = nullptr;
		uint64_t prototypesTotalSize = 0;
		HANDLE file = INVALID_HANDLE_VALUE;
		uint64_t fileSize = 0;
		uint64_t bytesUnread = 0;
		std::vector<uint8_t> fileBuffer;
		std::vector<Prototype*> prototypes;

	/* Functions */
	public:
		Bytecode(const std::string& filePath);
		~Bytecode();

		void operator()();

	private:
		void read_header();
		void read_prototypes();
		void open_file();
		void close_file();
		void read_file(const uint32_t& byteCount);
		uint32_t read_uleb128();
		bool buffer_next_block();
};

#endif // BYTECODE_H
