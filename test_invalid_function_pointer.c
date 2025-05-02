#include "include/uart.h"
// Main function to run tests
void safe_function();
void malicious_function();
void setup();

// Test 2: Invalid Indirect Function Call (Zicfilp)
void main() {
    setup();
    printf("===== [TEST] Invalid Function Pointer Call (Zicfilp) =====\n\r");

    void (*invalid_ptr)() = (void (*)()) malicious_function + 4;  // Invalid function address
    printf("[INFO] Calling invalid function pointer:\n\r");

    // Attempting to execute an invalid address
    invalid_ptr();  // Should trap if Zicfilp blocks invalid jumps
    return 1;
}