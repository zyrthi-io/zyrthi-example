#include <zyrthi/hal.h>
#include <zyrthi/core.h>

int main(void) {
    zyrthi_hal_init();
    
    // LED 输出
    zyrthi_gpio_t led = {
        .pin = 2,
        .mode = ZYRTHI_GPIO_OUTPUT,
    };
    zyrthi_gpio_init(&led);
    
    // 按钮输入
    zyrthi_gpio_t button = {
        .pin = 0,
        .mode = ZYRTHI_GPIO_INPUT,
        .pull = ZYRTHI_GPIO_PULL_UP,
    };
    zyrthi_gpio_init(&button);
    
    bool led_state = false;
    
    while (1) {
        // 检测按钮按下（低电平）
        if (!zyrthi_gpio_read(&button)) {
            led_state = !led_state;
            zyrthi_gpio_write(&led, led_state);
            zyrthi_delay_ms(200);  // 防抖
        }
        zyrthi_delay_ms(10);
    }
    
    return 0;
}
