#include "BuildOpt.h"

#define I2C_SDA 21
#define I2C_SCL 22

#define BUTTON_PIN 13
#define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep

// SX1276
#define USE_RF95

#define HAS_SCREEN 0

#define RF95_SCK 15
#define RF95_MISO 16
#define RF95_MOSI 2
#define RF95_NSS 25

#define LORA_RESET RADIOLIB_NC
#define LORA_DIO0 36
#define LORA_DIO1 RADIOLIB_NC
#define LORA_DIO2 39

// This board has different GPS pins than all other boards
#define HAS_GPS 0
#define GPS_RX_PIN 0
#define GPS_TX_PIN 0
