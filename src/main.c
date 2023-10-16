#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <stdio.h>

#include <target.h>

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <croutine.h>

#include "cdc.h"

#define LED_TASK_PRIORITY           ( tskIDLE_PRIORITY + 1 )
#define LED_TASK_STACK_SIZE         ( configMINIMAL_STACK_SIZE * 2 )

#if !defined(FREERTOS_DYNAMIC_MEMMANG)
StaticTask_t xLedTCBBuffer;
static StackType_t uxLedStackBuffer[LED_TASK_STACK_SIZE];
#endif

static void prvLEDTask( void *pvParameters ) {
    (void) pvParameters;

    for(;;) {
        vTaskDelay( ( TickType_t ) 500 );
        //gpio_toggle(LED_PORT, LED_PIN);
        if (cdcacm_is_connected()) {
            gpio_clear(LED_PORT, LED_PIN);
        } else {
            gpio_set(LED_PORT, LED_PIN);
        }
    }
}

int main(void)
{
    target_init();
    cdcacm_init();

#if defined(FREERTOS_DYNAMIC_MEMMANG)
    xTaskCreate( prvLEDTask, "LED", LED_TASK_STACK_SIZE, NULL,
                        LED_TASK_PRIORITY, NULL);
#else
	xTaskCreateStatic( prvLEDTask, "LED", LED_TASK_STACK_SIZE, NULL,
                        LED_TASK_PRIORITY, &uxLedStackBuffer[0], &xLedTCBBuffer);
#endif
    vTaskStartScheduler();
    
    /* Will only get here if there was not enough heap space to create the idle task. */
    return 0;
}

