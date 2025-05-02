#include "include/uart.h"
// Main function to run tests
void safe_function();
void malicious_function();
void setup();

// Test 3: Return Address Overwrite Attack (Zicfiss)
int main() {
    setup(); 
    printf("\n===== [TEST] Return Address Overwrite Attack (Zicfiss) =====\n\r");

    void (*ret_ptr)() = safe_function;

    // Simulate stack corruption to overwrite return address
    __asm__ volatile (
        "addi sp, sp, -8\n"  // Move stack pointer (simulating overflow)
        "sw %0, 0(sp)\n"     // Overwrite return address
        :
        : "r"(malicious_function)
    );

    printf("[INFO] Returning from function:\n\r");
    return 1;
}