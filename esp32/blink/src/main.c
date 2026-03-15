#include <zyrthi_hal.h>
#include <zyrthi/hal/gpio.h>
#include <zyrthi/hal/time.h>

int main(void) {
    // 初始化系统
    system_init();
    
    // 配置 LED GPIO (ESP32-C3 内置 LED 为 GPIO 8)
    gpio_mode(8, OUTPUT);
    
    // 主循环
    while (1) {
        gpio_write(8, HIGH);
        delay_ms(500);
        gpio_write(8, LOW);
        delay_ms(500);
    }
    
    return 0;
}
