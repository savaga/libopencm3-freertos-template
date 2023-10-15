#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>

#include "target.h"

static void clock_setup(void)
{
    //rcc_clock_setup_in_hse_8mhz_out_72mhz();
    rcc_clock_setup_pll(&rcc_hse8mhz_configs[RCC_CLOCK_HSE8_72MHZ]);

    /* Enable GPIOA,B,C clock (for LED,BUTTON, etc GPIOs). */
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_GPIOC);

    /* Enable clocks for GPIO port A (for GPIO_USART1_TX) and USART1. */
    //rcc_periph_clock_enable(RCC_USART1);

    /* Enable clocks for GPIO port A (for GPIO_USART2_TX) and USART2. */
    //rcc_periph_clock_enable(RCC_USART2);

    /* Enable clocks for USB OTG*/
    rcc_periph_clock_enable(RCC_USB);
}

static void gpio_setup(void)
{
    /* Setup GPIO13 (in GPIO port C) for LED use. */
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT,
              GPIO_PUPD_NONE, GPIO13);

    /* Setup GPIOB11 for button*/
    //gpio_mode_setup(GPIOB, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, GPIO12);

    /* Setup GPIO pins for USB D+/D-. */
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11 | GPIO12);
    gpio_set_af(GPIOA, GPIO_AF14, GPIO11| GPIO12);

}

void target_init(void) {
    clock_setup();
    gpio_setup();
}

