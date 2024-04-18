#include "i2c.h"

#include "stdbool.h"
#include "stdint.h"

#include "stm32g4xx_hal.h"

#define I2C_TIMEOUT 100

I2C_HandleTypeDef i2c1;

bool I2C_init() {
	i2c1.Instance = I2C1;
	i2c1.Init.Timing = 0x30909DEC;
	i2c1.Init.OwnAddress1 = 0;
	i2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2c1.Init.OwnAddress2 = 0;
	i2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	i2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&i2c1) != HAL_OK)
	{
		return false;
	}

	return true;
}

bool I2C_register_read(uint8_t bus, uint8_t devid, uint8_t regid, uint8_t* buf, uint8_t buflen) {
	HAL_I2C_Mem_Read(&i2c1, devid << 1, regid, I2C_MEMADD_SIZE_8BIT, buf, buflen, I2C_TIMEOUT);
}

bool I2C_register_write(uint8_t bus, uint8_t devid, uint8_t regid, uint8_t* buf, uint8_t buflen) {
	HAL_I2C_Mem_Write(&i2c1, devid << 1, regid, I2C_MEMADD_SIZE_8BIT, buf, buflen, I2C_TIMEOUT);
}