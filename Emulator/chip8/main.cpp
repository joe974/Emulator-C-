#include <iostream>
#include "chip8.h"

int main() {
    Chip8 chip8;          // Create emulator instance
    chip8.initialize();    // Initialize CPU/memory
    
    chip8.loadROM("/c/Users/joann/OneDrive/Desktop/eimaste_developers/C++/Emulator/chip8/roms/test.ch8");


    std::cout << "CHIP-8 emulator started\n";

    for (int i = 0; i < 10; i++) {
        chip8.emulateCycle();   // Run 10 CPU cycles
    }

    return 0;
}