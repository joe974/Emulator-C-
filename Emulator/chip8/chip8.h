#ifndef CHIP8_H
#define CHIP8_H

#include<cstdint>

class Chip8 {
public:
    void initialize();
    void loadROM(const char* filename);
    void emulateCycle();

private:
    uint16_t opcode;
    uint8_t memory[4096];
    uint8_t V[16];
    uint16_t I;
    uint16_t pc;
};
#endif
