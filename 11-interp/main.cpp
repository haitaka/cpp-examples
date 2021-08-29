#include <iostream>
#include <vector>
#include <cassert>

enum Op {
    INC, DEC
};

class Instruction {
public:
    Instruction(Op const op, std::vector<int> const & args) : op(op), args(args) {}

    Op const op;
    std::vector<int> const args;
};

class Registers {
public:
    Registers(std::initializer_list<int> data) : data(data) {}

    int & operator[](int idx) {
        if (idx >= data.size()) {
            data.resize(idx + 1);
        }
        return data.at(idx);
    }
private:
    std::vector<int> data;
};

int interpret(std::vector<Instruction> const & program, Registers registers) {
    int pc = 0;
    while (0 <= pc && pc < program.size()) {
        Instruction instr = program[pc];
        switch (instr.op) {
            case INC: {
                int reg = instr.args[0];
//                std::clog << "INC(" << reg << ")" << std::endl;
                ++registers[reg];
                ++pc;
                break;
            }
            case DEC: {
                int reg = instr.args[0];
                int target = instr.args[1];
//                std::clog << "DEC(" << reg << ", " << target << ")" << std::endl;
                if (registers[reg] > 0) {
                    --registers[reg];
                    pc = target;
                } else {
                    assert(registers[reg] == 0);
                    ++pc;
                }
                break;
            }
        }
    }
    return registers[0];
}

int interpretAdd0(Registers registers) {
    std::vector<Instruction> const program = {
            Instruction(DEC, { 0, 0 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 4 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 1, 3 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 8 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 2, 7 }),
    };
    int pc = 0;
    while (0 <= pc && pc < program.size()) {
        Instruction instr = program[pc];
        switch (instr.op) {
            case INC: {
                int reg = instr.args[0];
                std::clog << "INC(" << reg << ")" << std::endl;
                ++registers[reg];
                ++pc;
                break;
            }
            case DEC: {
                int reg = instr.args[0];
                int target = instr.args[1];
                std::clog << "DEC(" << reg << ", " << target << ")" << std::endl;
                if (registers[reg] > 0) {
                    --registers[reg];
                    pc = target;
                } else {
                    assert(registers[reg] == 0);
                    ++pc;
                }
                break;
            }
        }
    }
    return registers[0];
}

int interpretAdd(Registers registers) {
    l0:
//    Instruction(DEC, { 0, 0 })
    if (registers[0] > 0) {
        --registers[0];
        goto l0;
    }

//    Instruction(INC, { 0 })
    ++registers[0];

//    Instruction(DEC, { 0, 4 })
    if (registers[0] > 0) {
        --registers[0];
        goto l4;
    }

    l3:
//    Instruction(INC, { 0 })
    ++registers[0];

    l4:
//    Instruction(DEC, { 1, 3 })
    if (registers[1] > 0) {
        --registers[1];
        goto l3;
    }

//    Instruction(INC, { 0 })
    ++registers[0];

//    Instruction(DEC, { 0, 8 })
    if (registers[0] > 0) {
        --registers[0];
        goto l8;
    }

    l7:
//    Instruction(INC, { 0 })
    ++registers[0];

    l8:
//    Instruction(DEC, { 2, 7 })
    if (registers[2] > 0) {
        --registers[2];
        goto l7;
    }

    return registers[0];
}

int interpretAddStruct(Registers registers) {

    while (registers[0] > 0) {
        --registers[0];
    }

    while (registers[1] > 0) {
        --registers[1];
        ++registers[0];
    }

    while (registers[2] > 0) {
        --registers[2];
        ++registers[0];
    }

    return registers[0];
}

int interpretAddOpt(Registers registers) {
    registers[0] = 0;
    registers[0] += registers[1];
    registers[0] += registers[2];

    return registers[0];
}

int main() {
    std::vector<Instruction> add = {
            Instruction(DEC, { 0, 0 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 4 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 1, 3 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 8 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 2, 7 }),
    };
    std::vector<Instruction> mul = {
            Instruction(DEC, { 0, 0 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 13 }),
            Instruction(DEC, { 3, 3 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 8 }),
            Instruction(INC, { 0 }),
            Instruction(INC, { 3 }),
            Instruction(DEC, { 1, 6 }),
            Instruction(INC, { 0 }),
            Instruction(DEC, { 0, 12 }),
            Instruction(INC, { 1 }),
            Instruction(DEC, { 3, 11 }),
            Instruction(DEC, { 2, 3 })
    };
    int res = interpret(mul, { 0, 2, 3 });
    std::cout << res << std::endl;
    return 0;
}
