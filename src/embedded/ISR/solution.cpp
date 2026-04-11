// 在 driver.cpp 中
static int rx_buffer[256]; // 只有此驅動能存取，且不會佔用 Stack
static int head = 0;
static int tail = 0;

void UART_ISR() {
    // 快速存入資料到 rx_buffer...
}
