
#define I2C_SDA 21
#define I2C_SCL 22

#define BUTTON_PIN 13
#define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep

#define USE_RF95

#define RF95_SCK 15
#define RF95_MISO 16
#define RF95_MOSI 2
#define RF95_NSS 25

#define LORA_RESET RADIOLIB_NC // Not connected
#define LORA_DIO0 36
#define LORA_DIO1 RADIOLIB_NC // Not really used
#define LORA_DIO2 39

// This board has different GPS pins than all other boards
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// Define if screen should be mirrored left to right
#define SCREEN_ROTATE

// LCD screens are slow, so slowdown the wipe so it looks better
#define SCREEN_TRANSITION_FRAMERATE 1 // fps

#define TFT_HEIGHT 240
#define TFT_WIDTH 320
#define TFT_OFFSET_X 0
#define TFT_OFFSET_Y 0
#define TFT_BUSY -1

#define ILI9341_SPI_HOST VSPI_HOST // VSPI_HOST or HSPI_HOST
