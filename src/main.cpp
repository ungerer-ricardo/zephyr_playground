#include <iostream>

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void) 
{ 
    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }

    if(gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) {
        return 0;
    }

    while (1) {
        int ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return ret;
        }
        k_msleep(1000U);
    }
    return 0;
}
