#include "uart.h"
// Safe function - should be executed under normal conditions
void safe_function() {
    printf("[INFO] Executing safe function: Secure Execution\n\r");
}

// Malicious function - should never be executed if CFI is working
void malicious_function() {
    printf("[ALERT] Security Breach: Malicious function executed!\n\r");
    printf("[WARNING] Possible Control Flow Integrity (CFI) violation detected.\n\r");
}

void setup()
{
    setup_uart(115200);
    __asm__ volatile (
        "csrrsi zero, 0x30a, 12 \n"
        "addi t0, zero, 1024 \n"
        "csrrw zero, 0x747, t0 \n"
    );
}