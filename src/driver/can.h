#pragma once

#include <stdint.h>

void CAN_init();
void CAN_send(uint32_t id, uint64_t data);