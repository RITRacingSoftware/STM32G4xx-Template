#include "main.h"

#include <stdbool.h>

#include "can.h"
#include "clock.h"
#include "gpio.h"
#include "i2c.h"
#include "interrupts.h"

#include "FreeRTOS.h"
#include "task.h"


void heartbeat_task(void *pvParameters) {
	(void) pvParameters;
	while(true)
	{
		// CAN_send(0, 8, 0x0123456789abcdef);
		GPIO_toggle_heartbeat();
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}

int main(void)
{
	// Drivers
	if (!Clock_init()) {
		Error_Handler();
	}
	GPIO_init();
	if (!I2C_init()) {
		Error_Handler();
	}
	if (!CAN_init()) {
		Error_Handler();
	}
	Interrupts_init();

	int err = xTaskCreate(heartbeat_task, 
        "heartbeat", 
        1000,
        NULL,
        4,
        NULL);
    if (err != pdPASS) {
        Error_Handler();
    }

    // hand control over to FreeRTOS
    vTaskStartScheduler();

    // we should not get here ever
    Error_Handler();
}

// Called when stack overflows from rtos
// Not needed in header, since included in FreeRTOS-Kernel/include/task.h
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName)
{
	(void) xTask;
	(void) pcTaskName;

    Error_Handler();
}

void Error_Handler(void)
{
	Interrupts_disable();
	while (true) {}
}
