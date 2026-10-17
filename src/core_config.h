/**
  * @file   core_config.h
  * @brief  Configuration file for the core library
  */

#ifndef CORE_CORE_CONFIG_H
#define CORE_CORE_CONFIG_H

/**
  * @brief  Name of the program. This is stored to the .progname section and
  *         can read be the bootloader to identify the stored program.
  */
#define PROGRAM_NAME_STRING "Template project"

/***************** CLOCK PARAMETERS ****************************/
/***************************************************************/
/**
  * @brief  Use the external oscillator. If not defined, the internal
  *         oscillator will be used instead
  */
#define CORE_CLOCK_USE_HSE 0
/**
  * @brief  Frequency of the external oscillator in kHz
  */
#define CORE_CLOCK_HSE_FREQ 24000
/**
  * @brief  Desired system clock frequency in kHz
  */
#define CORE_CLOCK_SYSCLK_FREQ 160000
/**
  * @brief  Frequency of the internal oscillator in kHz
  */
#define CORE_CLOCK_HSI_FREQ 16000
/**
  * @brief  Divider for the P output on the PLL
  */
#define CORE_CLOCK_PLLP_DIV 12

/***************** ERROR HANDLER PARAMETERS ********************/
/***************************************************************/
/**
  * @brief  Delay between toggling the heartbeat LED in the error handler.
  */
#define CORE_ERROR_HANDLER_BLINK_DELAY 200000


/********************** CAN PARAMETERS *************************/
/***************************************************************/
/**
  * @brief  Number of CAN messages that can be stored in the CAN FreeRTOS queue
  */
#define CORE_CAN_QUEUE_LENGTH 15
/**
  * @brief  Timeout waiting for RX queue
  */
#define CORE_CAN_RX_TIMEOUT 100
/**
  * @brief  Disable CAN FreeRTOS TX queues
  */
#define CORE_CAN_DISABLE_TX_QUEUE 0
/**
  * @brief  Disable CAN FreeRTOS RX queues
  */
#define CORE_CAN_DISABLE_RX_QUEUE 0
/**
  * @brief  Disable CAN FreeRTOS TX semaphores
  */
#define CORE_CAN_DISABLE_SEMAPHORE 0

/**
  * @brief If set, calls to core_CAN_send_message will block
  *        until the bus exits the bus-off state
  */
#define CORE_CAN_BUS_OFF_BLOCK 1

/**
  * @brief  Use FreeRTOS message buffers instead of queues for received data
  */
#define CORE_CAN_USE_MSGBUF 0
/**
  * @brief  Transmit timestamp messages in all message buffers when the CAN
  *         timestamp counter overflows.
  */
#define CORE_CAN_TIMESTAMP 1
/**
  * @brief  Use hardware timestamping when possible
  */
#define CORE_CAN_HW_TIMESTAMP 1
/**
  * @brief  Timer that stores the upper bits of the CAN timestamp
  */
#define CORE_CAN_TIMER  TIM2

#define CORE_CAN_MSGBUF1_SIZE 1024
#define CORE_CAN_MSGBUF2_SIZE 0
#define CORE_CAN_MSGBUF3_SIZE 0
#define CORE_FDCAN1_MSGBUF 1
#define CORE_FDCAN2_MSGBUF 1
#define CORE_FDCAN3_MSGBUF 1

// Ports and pins for CAN communication
#define CORE_FDCAN1_TX_PORT GPIOA
#define CORE_FDCAN1_TX_PIN  GPIO_PIN_12
#define CORE_FDCAN1_TX_AF   9
#define CORE_FDCAN1_RX_PORT GPIOA
#define CORE_FDCAN1_RX_PIN  GPIO_PIN_11
#define CORE_FDCAN1_RX_AF   9

#define CORE_FDCAN2_TX_PORT GPIOB
#define CORE_FDCAN2_TX_PIN  GPIO_PIN_13
#define CORE_FDCAN2_TX_AF   9
#define CORE_FDCAN2_RX_PORT GPIOB
#define CORE_FDCAN2_RX_PIN  GPIO_PIN_12
#define CORE_FDCAN2_RX_AF   9

#define CORE_FDCAN3_TX_PORT GPIOA
#define CORE_FDCAN3_TX_PIN  GPIO_PIN_15
#define CORE_FDCAN3_TX_AF   11
#define CORE_FDCAN3_RX_PORT GPIOB
#define CORE_FDCAN3_RX_PIN  GPIO_PIN_3
#define CORE_FDCAN3_RX_AF   11

// Filters
#define CORE_FDCAN1_MAX_STANDARD_FILTER_NUM 28
#define CORE_FDCAN1_MAX_EXTENDED_FILTER_NUM 8
#define CORE_FDCAN2_MAX_STANDARD_FILTER_NUM 28
#define CORE_FDCAN2_MAX_EXTENDED_FILTER_NUM 8
#define CORE_FDCAN3_MAX_STANDARD_FILTER_NUM 28
#define CORE_FDCAN3_MAX_EXTENDED_FILTER_NUM 8

// Auto-retransmission config
#define CORE_FDCAN1_AUTO_RETRANSMISSION 1
#define CORE_FDCAN2_AUTO_RETRANSMISSION 1
#define CORE_FDCAN3_AUTO_RETRANSMISSION 1

// CAN FD config
#define CORE_FDCAN1_USE_FD 1
#define CORE_FDCAN2_USE_FD 1
#define CORE_FDCAN3_USE_FD 0

/********************* SPI PARAMETERS **************************/
/***************************************************************/
#define CORE_SPI1_SCK_PORT  GPIOA
#define CORE_SPI1_SCK_PIN   GPIO_PIN_5
#define CORE_SPI1_SCK_AF    5
#define CORE_SPI1_MISO_PORT GPIOA
#define CORE_SPI1_MISO_PIN  GPIO_PIN_6
#define CORE_SPI1_MISO_AF   5
#define CORE_SPI1_MOSI_PORT GPIOA
#define CORE_SPI1_MOSI_PIN  GPIO_PIN_7
#define CORE_SPI1_MOSI_AF   5
/**
  * @brief  Divider for SPI1 clock. SPI speed = SYSCLK / 2**(CORE_SPI1_DIVIDER + 1)
  */
#define CORE_SPI1_DIVIDER   7
/**
  * @brief  Size of an SPI transfer in bits
  */
#define CORE_SPI1_DATA_SIZE 8
#define CORE_SPI1_MASTER    1

#define CORE_SPI2_SCK_PORT  GPIOB
#define CORE_SPI2_SCK_PIN   GPIO_PIN_13
#define CORE_SPI2_SCK_AF    5
#define CORE_SPI2_MISO_PORT GPIOB
#define CORE_SPI2_MISO_PIN  GPIO_PIN_14
#define CORE_SPI2_MISO_AF   5
#define CORE_SPI2_MOSI_PORT GPIOB
#define CORE_SPI2_MOSI_PIN  GPIO_PIN_15
#define CORE_SPI2_MOSI_AF   5
/**
  * @brief  Divider for SPI2 clock. SPI speed = SYSCLK / 2**(CORE_SPI2_DIVIDER + 1)
  */
#define CORE_SPI2_DIVIDER   7
/**
  * @brief  Size of an SPI transfer in bits
  */
#define CORE_SPI2_DATA_SIZE 8
#define CORE_SPI2_MASTER    1

#define CORE_SPI3_SCK_PORT  GPIOC
#define CORE_SPI3_SCK_PIN   GPIO_PIN_10
#define CORE_SPI3_SCK_AF    6
#define CORE_SPI3_MISO_PORT GPIOC
#define CORE_SPI3_MISO_PIN  GPIO_PIN_11
#define CORE_SPI3_MISO_AF   6
#define CORE_SPI3_MOSI_PORT GPIOC
#define CORE_SPI3_MOSI_PIN  GPIO_PIN_12
#define CORE_SPI3_MOSI_AF   6
/**
  * @brief  Divider for SPI3 clock. SPI speed = SYSCLK / 2**(CORE_SPI3_DIVIDER + 1)
  */
#define CORE_SPI3_DIVIDER   7
/**
  * @brief  Size of an SPI transfer in bits
  */
#define CORE_SPI3_DATA_SIZE 8
#define CORE_SPI3_MASTER    1

#define CORE_SPI4_SCK_PORT  GPIOE
#define CORE_SPI4_SCK_PIN   GPIO_PIN_12
#define CORE_SPI4_SCK_AF    5
#define CORE_SPI4_MISO_PORT GPIOE
#define CORE_SPI4_MISO_PIN  GPIO_PIN_13
#define CORE_SPI4_MISO_AF   5
#define CORE_SPI4_MOSI_PORT GPIOE
#define CORE_SPI4_MOSI_PIN  GPIO_PIN_14
#define CORE_SPI4_MOSI_AF   5
/**
  * @brief  Divider for SPI4 clock. SPI speed = SYSCLK / 2**(CORE_SPI4_DIVIDER + 1)
  */
#define CORE_SPI4_DIVIDER   7
/**
  * @brief  Size of an SPI transfer in bits
  */
#define CORE_SPI4_DATA_SIZE 8
#define CORE_SPI4_MASTER    1


/******************** USART PARAMETERS *************************/
/***************************************************************/
/**
  * @brief  Size of the internal RX buffer. One buffer will be created for each
  *         USART module
  */
#define CORE_USART_RXBUFLEN         512
/**
  * @brief  Number of bits periods that must elapse since the most recent
  *         transmission for the receive interrupt to trigger
  */
#define CORE_USART_RX_TIMEOUT       64

/**
  * @brief  Enable the uprintf function
  */
#define CORE_USART_UPRINTF          0
/**
  * @brief  Size of the transmit buffer to which uprintf stores characters to
  *         be transmitted. The tranmit buffer is shared and is only defined 
  *         when uprintf is enabled
  */
#define CORE_USART_TXBUFLEN         512

#define CORE_USART1_TX_PORT GPIOC
#define CORE_USART1_TX_PIN  GPIO_PIN_4
#define CORE_USART1_TX_AF   7
#define CORE_USART1_RX_PORT GPIOC
#define CORE_USART1_RX_PIN  GPIO_PIN_5
#define CORE_USART1_RX_AF   7

#define CORE_USART2_TX_PORT GPIOA
#define CORE_USART2_TX_PIN  GPIO_PIN_2
#define CORE_USART2_TX_AF   7
#define CORE_USART2_RX_PORT GPIOA
#define CORE_USART2_RX_PIN  GPIO_PIN_3
#define CORE_USART2_RX_AF   7

#define CORE_USART3_TX_PORT GPIOB
#define CORE_USART3_TX_PIN  GPIO_PIN_10
#define CORE_USART3_TX_AF   7
#define CORE_USART3_RX_PORT GPIOB
#define CORE_USART3_RX_PIN  GPIO_PIN_11
#define CORE_USART3_RX_AF   7

#define CORE_UART4_TX_PORT  GPIOC
#define CORE_UART4_TX_PIN   GPIO_PIN_10
#define CORE_UART4_TX_AF    5
#define CORE_UART4_RX_PORT  GPIOC
#define CORE_UART4_RX_PIN   GPIO_PIN_11
#define CORE_UART4_RX_AF    5
#define CORE_UART4_IRQ_PRIO 5

#define CORE_UART5_TX_PORT  GPIOC
#define CORE_UART5_TX_PIN   GPIO_PIN_12
#define CORE_UART5_TX_AF    5
#define CORE_UART5_RX_PORT  GPIOD
#define CORE_UART5_RX_PIN   GPIO_PIN_2
#define CORE_UART5_RX_AF    5


/*********************** RTC PARAMETERS ************************/
/***************************************************************/
#define CORE_RTC_CENTURY            2000

/******************** BOOTLOADER PARAMETERS ********************/
/***************************************************************/
/**
  * @brief  FDCAN module over which the chip can be programmed via the bootloader
  */
#define CORE_BOOT_FDCAN             FDCAN2
/**
  * @brief  Bootloader board ID
  */
#define CORE_BOOT_FDCAN_ID          0x020
/**
  * @brief  Bootloader master ID. Status packets from the bootloader will have
  *         this value in the ID field of the extended CAN ID.
  */
#define CORE_BOOT_FDCAN_MASTER_ID   0x0A0
/**
  * @brief  Broadcast ID to which this board will respond. Only used for bank
  *         enumeration and reset.
  */
#define CORE_BOOT_FDCAN_BROADCAST_ID 0x7ff

/**
  * @brief  Enable external programming
  */
#define CORE_BOOT_EXTERNAL          0

/********************* TIMEOUT PARAMETERS **********************/
/***************************************************************/
/**
 * @brief Number of timeouts used
 */
#define CORE_TIMEOUT_NUM            0

/********************* WATCHDOG PARAMETERS *********************/
/***************************************************************/

// Timeout formula: timeout = (APB_clock_period(ms)) * 4096 * (2^(CORE_WATCHDOG_PRESCALER)) * (CORE_WATCHDOG_RELOAD_VAL + 1) ms
// APB clock set to system clock = 160MHz by default. APB_clock_period = 6.25ns = 6.25*10^(-6) ms
// Downcounter is 7 bits. When the lower 6 bits go to 0 (timer = 0x40), the interrupt is triggered if it is set.
// When the counter goes to 0x3F, the system reset is triggered.

/**
 * @brief Prescaler for watchdog timer driven by LSI (32kHz).
 * Frequency = 32kHz/(2^(CORE_WATCHDOG_PRESCALER + 2)). 3 bits (max 7)
 */
#define CORE_WATCHDOG_PRESCALER         6
/**
 * @brief Value that will be loaded into the watchdog counter upon reload. 11 bits (max 2047)
 */
#define CORE_WATCHDOG_RELOAD_VAL           500
/**
 * @brief Watchdog window. Must refresh when downcounter has counted lower than this number
 * for the refresh to be valid. If not, it will be reset 11 bits (max 2047)
 */
#define CORE_WATCHDOG_WINDOW_VAL           250

#endif //CORE_CORE_CONFIG_H
