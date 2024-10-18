#pragma once

#include "stdbool.h"
#include "stdint.h"

// Initialize I2C
bool I2C_init();

// Read I2C register
bool I2C_register_read(uint8_t bus, uint8_t devid, uint8_t regid, uint8_t* buf, uint8_t buflen);

// Write I2C register
bool I2C_register_write(uint8_t bus, uint8_t devid, uint8_t regid, uint8_t* buf, uint8_t buflen);