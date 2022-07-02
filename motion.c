#include "hardware/gpio.h"
#include "pico/stdlib.h"

void handler();

#define GPIO15 15

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#else
    gpio_init(GPIO15);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_irq_enabled_with_callback(GPIO15,GPIO_IRQ_EDGE_RISE, true, &handler);

    while (true) {

        sleep_ms(100000);
    }
#endif
}

void handler(uint gpio, uint32_t events) {
    gpio_put(PICO_DEFAULT_LED_PIN,!gpio_get(PICO_DEFAULT_LED_PIN));
}
