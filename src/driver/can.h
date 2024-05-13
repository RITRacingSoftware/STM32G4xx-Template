#pragma once

#include <stdbool.h>
#include <stdint.h>

bool CAN_init();
bool CAN_send(uint32_t id, uint8_t dlc, uint64_t data);