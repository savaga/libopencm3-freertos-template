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

#define LED_TASK_PRIORITY           ( tskIDLE_PRIORITY + 1 )
#define LED_TASK_STACK_SIZE         ( configMINIMAL_STACK_SIZE * 2 )


StaticTask_t xLedTCBBuffer;
static StackType_t uxLedStackBuffer[LED_TASK_STACK_SIZE];


static void prvLEDTask( void *pvParameters ) {
    (void) pvParameters;

    for(;;) {
        vTaskDelay( ( TickType_t ) 500 );
        gpio_toggle(GPIOC, GPIO13); 
    }
}

int main(void)
{
    target_init();

	xTaskCreateStatic( prvLEDTask, "LED", LED_TASK_STACK_SIZE, NULL,
                        LED_TASK_PRIORITY, &uxLedStackBuffer[0], &xLedTCBBuffer);

    vTaskStartScheduler();
    
    /* Will only get here if there was not enough heap space to create the idle task. */
    return 0;
}

