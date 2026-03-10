#include <zyrthi/hal.h>
#include <zyrthi/core.h>

int main(void) {
    zyrthi_hal_init();
    
    // 初始化 UART0
    zyrthi_uart_t uart = {
        .instance = 0,
        .baud = 115200,
        .tx_pin = 1,
        .rx_pin = 3,
    };
    zyrthi_uart_init(&uart);
    
    uint8_t buf[64];
    
    while (1) {
        // 读取数据
        int len = zyrthi_uart_read(&uart, buf, sizeof(buf));
        if (len > 0) {
            // 回显
            zyrthi_uart_write(&uart, buf, len);
        }
    }
    
    return 0;
}
