#pragma once


// A7608H pins
#define SW_PB_PIN           GPIO_NUM_0
    
#define A7608H_PWRKEY_PIN   GPIO_NUM_4
#define A7608H_RESET_PIN    GPIO_NUM_5
#define A7608H_DTR_PIN      GPIO_NUM_25
#define A7608H_TX_PIN       GPIO_NUM_26
#define A7608H_RX_PIN       GPIO_NUM_27
#define A7608H_RI_PIN       GPIO_NUM_33

// Build-in battery pins
#define BATT_18650_EN_PIN   GPIO_NUM_12
#define BATT_18650_ADC_PIN  GPIO_NUM_35

// TF card  pins
#define TF_CARD_MISO_PIN    GPIO_NUM_2
#define TF_CARD_CS_PIN      GPIO_NUM_13
#define TF_CARD_SCLK_PIN    GPIO_NUM_14
#define TF_CARD_MOSI_PIN    GPIO_NUM_15

// USB serial pins (Standard UART0)
#define USB_UART_TX_PIN     GPIO_NUM_1
#define USB_UART_RX_PIN     GPIO_NUM_3

// Default Wire pins
#define WIRE_SDA_PIN        GPIO_NUM_21
#define WIRE_SCL_PIN        GPIO_NUM_22

// Default VSPI pins
#define VSPI_SCK_PIN        GPIO_NUM_18
#define VSPI_MISO_PIN       GPIO_NUM_19
#define VSPI_MOSI_PIN       GPIO_NUM_23

// Free  GPIO pins
#define FREE_GPIO32         GPIO_NUM_32
#define FREE_GPIO34         GPIO_NUM_34
#define FREE_GPIO36         GPIO_NUM_36
#define FREE_GPIO39         GPIO_NUM_39
