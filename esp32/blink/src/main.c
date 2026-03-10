#include <zyrthi/hal.h>
#include <zyrthi/core.h>

int main(void) {
    // 初始化 HAL
    zyrthi_hal_init();
    
    // 配置 LED GPIO
    zyrthi_gpio_t led = {
        .pin = 8,  // ESP32-C3 内置 LED
        .mode = ZYRTHI_GPIO_OUTPUT,
    };
    zyrthi_gpio_init(&led);
    
    // 主循环
    while (1) {
        zyrthi_gpio_write(&led, true);
        zyrthi_delay_ms(500);
        zyrthi_gpio_write(&led, false);
        zyrthi_delay_ms(500);
    }
    
    return 0;
}
