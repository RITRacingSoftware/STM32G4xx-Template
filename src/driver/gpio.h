#pragma once

#include "stdbool.h"

void GPIO_init(void);
void GPIO_toggle_heartbeat(void);
void GPIO_set_heartbeat(bool state);