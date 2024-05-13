#include "can.h"

#include <stdbool.h>
#include <stdint.h>

#include <stm32g4xx_hal.h>

#define CAN_GPIOX GPIOB
#define CAN_PINS (GPIO_PIN_12 | GPIO_PIN_13)

static FDCAN_HandleTypeDef can;

bool CAN_init() {
	// Initialize pins
	GPIO_InitTypeDef gpio = {CAN_PINS, GPIO_MODE_AF_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_AF9_FDCAN2};
	HAL_GPIO_Init(CAN_GPIOX, &gpio);

	// Initialize CAN interface
	can.Instance = FDCAN2;
	can.Init.ClockDivider = FDCAN_CLOCK_DIV1;
	can.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
	can.Init.Mode = FDCAN_MODE_NORMAL;
	can.Init.AutoRetransmission = ENABLE;
	can.Init.TransmitPause = DISABLE;
	can.Init.ProtocolException = ENABLE;
	can.Init.NominalPrescaler = 10;
	can.Init.NominalSyncJumpWidth = 1;
	can.Init.NominalTimeSeg1 = 13;
	can.Init.NominalTimeSeg2 = 2;
	can.Init.DataPrescaler = 1; // Data timing fields unused for classic CAN
	can.Init.DataSyncJumpWidth = 1;
	can.Init.DataTimeSeg1 = 1;
	can.Init.DataTimeSeg2 = 1;
	can.Init.StdFiltersNbr = 0;
	can.Init.ExtFiltersNbr = 0;
	can.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
	if (HAL_FDCAN_Init(&can) != HAL_OK)
	{
		return false;
	}

	// Start can interface
	if (HAL_FDCAN_Start(&can) != HAL_OK)
	{
		return false;
	}

	return true;
}

bool CAN_send(uint32_t id, uint8_t dlc, uint64_t data) {
	FDCAN_TxHeaderTypeDef header = {0};
	header.Identifier = id;
	header.IdType = FDCAN_STANDARD_ID;
	header.TxFrameType = FDCAN_DATA_FRAME;
	header.DataLength = dlc;
	header.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	header.BitRateSwitch = FDCAN_BRS_OFF;
	header.FDFormat = FDCAN_CLASSIC_CAN;
	header.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
	header.MessageMarker = 0;

	if (HAL_FDCAN_GetTxFifoFreeLevel(&can) != 0) {
		HAL_StatusTypeDef err = HAL_FDCAN_AddMessageToTxFifoQ(&can, &header, (uint8_t*) &data);
		return (err == HAL_OK);
	}
	else {
		FDCAN_ErrorCountersTypeDef errors;
		HAL_FDCAN_GetErrorCounters(&can, &errors);
		FDCAN_ProtocolStatusTypeDef status;
		HAL_FDCAN_GetProtocolStatus(&can, &status);

		if (status.LastErrorCode != FDCAN_PROTOCOL_ERROR_NO_CHANGE) {
			int b = 0;
		}

		int a = 0;
	}

	return false;
}
