#include "chip8.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

// Initialize CPU, memory, registers
void Chip8::initialize() {
    pc = 0x200;      // Program counter starts at 0x200
    opcode = 0;
    I = 0;
    memset(memory, 0, sizeof(memory));
    memset(V, 0, sizeof(V));
}

// Load a ROM file into memory starting at 0x200
void Chip8::loadROM(const char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open ROM: " << filename << std::endl;
        return;
    }

    std::streamsize size = file.tellg();
    if (size <= 0) {
        std::cerr << "ROM is empty or invalid: " << filename << std::endl;
        return;
    }

    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);

    if (!file.read(buffer.data(), size)) {
        std::cerr << "Failed to read ROM: " << filename << std::endl;
        return;
    }

    for (std::streamsize i = 0; i < size; ++i) {
        memory[0x200 + i] = static_cast<unsigned char>(buffer[i]);
    }

    std::cout << "ROM loaded successfully: " << filename << " (" << size << " bytes)\n";
}

// Fetch, decode, and execute one opcode
void Chip8::emulateCycle() {
    opcode = memory[pc] << 8 | memory[pc + 1];
    std::cout << "Opcode: " << std::hex << opcode << std::endl;

    switch (opcode & 0xF000) {
        case 0x0000:
            if (opcode == 0x00E0) {  // Clear screen
                std::cout << "Clear screen\n";
                pc += 2;
            }
            break;

        case 0x1000:  // Jump to address NNN
            pc = opcode & 0x0FFF;
            break;

        default:
            std::cout << "Unknown opcode\n";
            pc += 2;
            break;
    }
}


    