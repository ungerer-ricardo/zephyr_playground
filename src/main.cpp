#include <iostream>

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/display/cfb.h>

#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int heartbit_led() {
    return gpio_pin_toggle_dt(&led);
}

int heartbit_led_configure() {
    int ret = gpio_is_ready_dt(&led);
    if (!ret) {
        return -1;
    }
    if((ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE)) < 0) {
        return ret;
    }
    return 0;
}

int main(void) 
{ 
    if (heartbit_led_configure() < 0) {
        std::cout << "Heartbit led failed to configure... \n";
        return 0;
    }

    const struct device* display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display_dev)){
        std::cout << "Display not yet ready... \n";
        return 0;
    }
    if(cfb_framebuffer_init(display_dev)) {
        std::cout << "Failed to initialize display framebuffer... \n";
        return 0;
    }

    cfb_position start {
        .x = 0,
        .y = 0
    };
    cfb_position end {
        .x = 7,
        .y = 7
    };
    cfb_draw_line(display_dev, &start, &end);

    start.x=7;
    end.x=0;
    cfb_draw_line(display_dev, &start, &end);
    cfb_framebuffer_finalize(display_dev);

    int ret = 0;
    while (1) {
        cfb_framebuffer_invert(display_dev);
        cfb_framebuffer_finalize(display_dev);

        if ((ret = heartbit_led()) < 0) {
            std::cout << "Failed to toggle heartbit led... \n";
            return ret;
        }
        k_msleep(1000U);
    }
    return 0;
}
