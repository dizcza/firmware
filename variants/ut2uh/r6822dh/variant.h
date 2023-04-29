#define USE_SX1268  // R6822DH-5W

#define SX126X_R6822DH

#define HAS_SCREEN 0
#define I2C_SDA 21
#define I2C_SCL 22

// GPS
#undef GPS_RX_PIN
#undef GPS_TX_PIN
#define GPS_RX_PIN NOT_A_PIN
#define GPS_TX_PIN NOT_A_PIN
#define HAS_GPS 0

#define BUTTON_PIN 2 // The middle button GPIO on the T-Beam
#define BUTTON_NEED_PULLUP
#define EXT_NOTIFY_OUT 12 // Overridden default pin to use for Ext Notify Module (#975).

#define LORA_CS     18
#define LORA_DIO0   NOT_A_PIN   // Not connected on the SX1262/SX1268 module
#define LORA_RESET  23  // RST for SX1276, and for SX1262/SX1268
#define LORA_DIO1   33  // IRQ for SX1262/SX1268
#define LORA_DIO2   32  // BUSY for SX1262/SX1268
#define LORA_DIO3   NOT_A_PIN   // Not connected on PCB, but internally on the TTGO SX1262/SX1268, if DIO3 is high the TXCO is enabled
// In transmitting, set TXEN as high communication level，RXEN pin is low level;
// In receiving, set RXEN as high communication level, TXEN is lowlevel;
// Before powering off, set TXEN、RXEN as low level.
#define LORA_RXEN   14 // Input - RF switch RX control, connecting external MCU IO, valid in high level
#define LORA_TXEN   RADIOLIB_NC // Input - RF switch TX control, connecting external MCU IO or DIO2, valid in high level

// common pinouts for SX126X modules
#define SX126X_CS    LORA_CS // NSS for SX126X
#define SX126X_DIO1  LORA_DIO1
#define SX126X_BUSY  LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN  LORA_RXEN
#define SX126X_TXEN  RADIOLIB_NC

// Set lora.tx_power to 13 for Hydra or other E22 900M30S target due to PA
#define SX126X_MAX_POWER 14
