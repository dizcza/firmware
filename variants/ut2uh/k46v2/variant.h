
#define I2C_SDA 21
#define I2C_SCL 22

#define BUTTON_PIN 13
#define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep
//#define EXT_NOTIFY_OUT 4 // Default pin to use for Ext Notify Plugin.

//#define PIN_BUZZER 25

#define USE_SX1262

#undef RF95_SCK
#undef RF95_MISO
#undef RF95_MOSI
#undef RF95_NSS
#undef RF95_RXEN
#undef RF95_TXEN

#define RF95_SCK 15
#define RF95_MISO 16
#define RF95_MOSI 2
#define RF95_NSS 25

#define LORA_RESET RADIOLIB_NC
#define LORA_DIO0 RADIOLIB_NC
#define LORA_DIO1 36
#define LORA_DIO2 39

// common pinouts for SX126X modules
#define SX126X_CS   RF95_NSS    // NSS for SX126X
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET

// Set lora.tx_power to 13 for Hydra or other E22 900M30S target due to PA
#define SX126X_MAX_POWER 22

// This board has different GPS pins than all other boards
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// Define if screen should be mirrored left to right
#define SCREEN_ROTATE

// LCD screens are slow, so slowdown the wipe so it looks better
#define SCREEN_TRANSITION_FRAMERATE 1 // fps
