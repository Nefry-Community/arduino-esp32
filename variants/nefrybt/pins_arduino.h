#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

//Display
static const uint8_t SDA2 = 21;
static const uint8_t SCL2 = 22;

static const uint8_t SS    = 25;
static const uint8_t MOSI  = 23;
static const uint8_t MISO  = 19;
static const uint8_t SCK   = 18;

static const uint8_t D0 = 22;
static const uint8_t D1 = 21;
static const uint8_t D2 = 23;
static const uint8_t D3 = 19;
static const uint8_t D4 = 18;

static const uint8_t A0 = 25;
static const uint8_t A1 = 26;
static const uint8_t A2 = 32;
static const uint8_t A3 = 33;
static const uint8_t A4 = 27;
static const uint8_t A5 = 14;
static const uint8_t A6 = 13;
static const uint8_t A7 = 35;

static const uint8_t T0 = 32;
static const uint8_t T1 = 33;
static const uint8_t T2 = 27;
static const uint8_t T3 = 14;
static const uint8_t T4 = 13;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

static const uint8_t LED_CLK = -1;
static const uint8_t LED_DO = 16;

static const uint8_t  boardId = 1;//Nefry BT

#endif /* Pins_Arduino_h */
