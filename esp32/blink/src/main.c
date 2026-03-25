#include <zyrthi_hal.h>
#include <zyrthi/hal/gpio.h>
#include <zyrthi/hal/time.h>

int main(void) {
    // 初始化系统
    system_init();
    
    // 配置 LED GPIO (ESP32-S3 LED 为 GPIO 12)
    gpio_mode(12, OUTPUT);
    
    // 主循环
    while (1) {
        gpio_write(12, HIGH);
        delay_ms(500);
        gpio_write(12, LOW);
        delay_ms(500);
    }
    
    return 0;
}
