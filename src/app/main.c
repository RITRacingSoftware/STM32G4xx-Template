#include "main.h"

#include <stdbool.h>

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
		uint8_t buf[6];
		I2C_register_read(0, 0x53, 0x32, &buf, 6);

		int a = 0;

		//uint16_t x = ((uint16_t) buf1) << 16 | buf2;

		GPIO_set_heartbeat((buf[0]/128) == 0);
		// vTaskDelay(500); // Sleep 0.5s
	}
}

int main(void)
{
	if (!Clock_init()) {
		Error_Handler();
	}
	GPIO_init();
	if (!I2C_init()) {
		Error_Handler();
	}
	Interrupts_init();

	for (int i = 0; i < 1000000; i++) {}

	uint8_t buf = 0b00001000;
	I2C_register_write(0, 0x53, 0x2d, &buf, 1);

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
