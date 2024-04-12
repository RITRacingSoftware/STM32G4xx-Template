#include "interrupts.h"

#include "stm32g4xx_hal.h"

void Interrupts_init() {
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
}

void Interrupts_disable() {
	__disable_irq();
}