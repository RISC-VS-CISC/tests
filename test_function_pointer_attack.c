#include "include/uart.h"
// Main function to run tests
void safe_function();
void malicious_function();
void setup();

// Test 1: Function Pointer Overwrite Attack (Zicfilp)
int main() {
    setup();
    printf("===== [TEST] Function Pointer Overwrite Attack (Zicfilp) =====\n\r");

    void (*function_ptr)() = safe_function;
    printf("[INFO] Function pointer initially set to safe_function\n\r");

    // Simulate attack: Overwriting function pointer
    printf("[ATTACK] Overwriting function pointer...\n\r");
    function_ptr = malicious_function;

    // Attempt to execute overwritten function pointer
    printf("[INFO] Calling function pointer:\n\r");
    function_ptr();  // Should trap if Zicfilp is active
    return 1;
}