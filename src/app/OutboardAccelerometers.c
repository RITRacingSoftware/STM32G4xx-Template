#include "OutboardAccelerometers.h"

#include <stdbool.h>
#include <stdint.h>

#include "can.h"
#include "i2c.h"
#include "gpio.h"

bool OutboardAccelerometers_init() {
	// Send startup signal
	uint8_t buf = 0b00001000;
	if (!I2C_register_write(0, 0x53, 0x2d, &buf, 1)) {
		return false;
	}

	return true;
}

void OutboardAccelerometers_update() {
	uint8_t buf[8];
	I2C_register_read(0, 0x53, 0x32, buf, 6);

	uint64_t data = *((uint64_t*) buf);

	// CAN_send(0x123, 6, data);

	// GPIO_set_heartbeat((buf[0]/128) == 0);
}
