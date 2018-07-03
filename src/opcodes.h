/* Some Opcodes für x86_x64 */

enum MOD {
	ABS_ADDR = 0,
	REL_ADDR = 1,
	VALUE = 2,
	REG = 3
};

enum REGISTER {
	EAX = 0,
	ECX,
	EDX,
	EBX,
	ESP,
	EBP,
	EIP,
	EDI
};

typedef unsigned char uchar8;

class Opcodes {
	private:
		Code* code;
	public:
		Opcodes(Code* c) {
			code = c;
		}

		uchar8 reg(uchar8 mod, uchar8 reg1, uchar8 reg2) {
			return (mod << 6) | (reg1 << 3) | (reg2);
		}

		void ADD_REG(uchar8 reg1, uchar8 reg2) {
			code->push(0x48, 0x01);
			code->push(reg(REG, reg2, reg1));
		}

		void ADD_REG_VALUE(uchar8 reg1, int value) {
			code->push(0x48, 0x81);
			code->push(reg(REG, reg1, reg1));
			code->pushInt(value);
		}

		void SUB_REG(uchar8 reg1, uchar8 reg2) {
			code->push(0x48, 0x29);
			code->push(reg(REG, reg2, reg1));
		}

		void SUB_REG_VALUE(uchar8 reg1, int value) {
			code->push(0x48, 0x83);
			code->push(0xe8 | reg1);
			code->push(value);
		}

		void MUL_REG(uchar8 reg1) {
			code->push(0x48, 0xF7);
			code->push(0xE0 | reg1);
		}

		void DIV_REG(uchar8 reg1) {
			code->push(0x48, 0xF7);
			code->push(0xF0 | reg1);
		}

		void MOV_REG(uchar8 reg1, uchar8 reg2) {
			code->push(0x48, 0x8B);
			code->push(reg(REG, reg1, reg2));
		}

		void MOV_VALUE_TO_REG(uchar8 reg1, int value) {
			code->push(0xB8 | reg1);
			code->pushInt(value);
		}

		void MOV_ADDR_TO_REG(uchar8 reg, void* ptr) {
			code->push(0x48, 0xB8 | reg);
			code->pushPointer(ptr);
		}

		void MOV_ADDR_VALUE_TO_REG(uchar8 reg1, uchar8 reg2, void* ptr) {
			MOV_ADDR_TO_REG(reg2, ptr);
			code->push(0x8B);
			code->push(reg(ABS_ADDR, reg1, reg2));
		}

		void MOV_REG_TO_ADDR_VALUE(uchar8 reg1, uchar8 reg2, void* ptr) {
			MOV_ADDR_TO_REG(reg2, ptr);
			code->push(0x89);
			code->push(reg(ABS_ADDR, reg1, reg2));
		}

		void PUSH_REG(uchar8 reg) {
			code->push(0x50 | reg);
		}

		void POP_REG(uchar8 reg) {
			code->push(0x58 | reg);
		}

		void RET() {
			code->push(0xc3);
		}
};
