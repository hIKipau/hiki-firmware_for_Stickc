#define ST7789_DRIVER

#define TFT_WIDTH  135
#define TFT_HEIGHT 240

#define TFT_MOSI 15
#define TFT_SCLK 13
#define TFT_CS 5
#define TFT_DC   23
#define TFT_RST -1  // Использует RST ESP32


#define TFT_INVERSION_ON
// #define TFT_RGB_ORDER TFT_BGR  // Раскомментировать если цвета "перепутаны"

#define SPI_FREQUENCY 27000000  // 40 MHz
#define SPI_READ_FREQUENCY 20000000
#define SMOOTH_FONT 1

#define SUPPORT_TRANSACTIONS