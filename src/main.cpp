#include <iostream>

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>

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

    const struct device* display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if(!device_is_ready(display_dev)) {
        std::cout << "Display not ready...\n";
        return 0;
    }
    display_set_pixel_format(display_dev, PIXEL_FORMAT_MONO01);

    display_buffer_descriptor desc;
    desc.buf_size = 1;
    desc.height = 1;
    desc.width = 1;
    desc.pitch = 1;
    uint8_t buf[1] = {1};

    int i =0;
    int j =0;
    while (1) {
        buf[0] = 0;
        int ret = display_write(display_dev,i,j,&desc, buf);
        if (ret < 0) {
            std::cout << "Error writing to display\n";
        }
        i++;
        if (i >= 8 ) {
            i = 0;
            j++;
            if (j >= 8)
                j = 0;
        }
        buf[0] = 1;
        ret = display_write(display_dev,i,j,&desc, buf);
        if (ret < 0) {
            std::cout << "Error writing to display\n";
        }
        
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return ret;
        }
        k_msleep(1000U);
    }
    return 0;
}
