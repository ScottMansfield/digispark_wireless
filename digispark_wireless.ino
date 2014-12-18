
// MISO / DI / pin 0
#define MISO_PIN 0

// MOSI / DO / pin 1
#define MOSI_PIN 1

// SCLK / SCK / pin 2
#define SCLK_PIN 2

// CSN / pin3
#define CSN_PIN 3

////////////////////////////////////////////////////////
// REGISTER MAPPINGS
////////////////////////////////////////////////////////

// TODO: Macros to set each multi-bit value... and move the whole thing into a header file
// TODO: Macros to set a single bit to a value

#define CONFIG 0x00
#define MASK_RX_DR  6
#define MASK_TX_DS  5
#define MASK_MAX_RT 4
#define EN_CRC      3
#define CRCO        2
#define PWR_UP      1
#define PRIM_RX     0

#define EN_AA 0x01
#define ENAA_P5 5
#define ENAA_P4 4
#define ENAA_P3 3
#define ENAA_P2 2
#define ENAA_P1 1
#define ENAA_P0 0

#define EN_RXADDR 0x02
#define ERX_P5 5
#define ERX_P4 4
#define ERX_P3 3
#define ERX_P2 2
#define ERX_P1 1
#define ERX_P0 0

#define SETUP_AW 0x03

#define SETUP_RETR 0x04

#define RF_CH 0x05

#define RF_SETUP 0x06
#define CONT_WAVE  7
#define RF_DR_LOW  5
#define PLL_LOCK   4
#define RF_DR_HIGH 3
#define RF_PWR     2

#define STATUS 0x07
#define RX_DR   6
#define TX_DS   5
#define MAX_RT  4
#define TX_FULL 0

#define OBSERVE_TX 0x08

#define RPD 0x09

#define RX_ADDR_P0 0x0A
#define RX_ADDR_P1 0x0B
#define RX_ADDR_P2 0x0C
#define RX_ADDR_P3 0x0D
#define RX_ADDR_P4 0x0E
#define RX_ADDR_P5 0x0F

#define TX_ADDR 0x10

#define RX_PW_P0 0x11
#define RX_PW_P1 0x12
#define RX_PW_P2 0x13
#define RX_PW_P3 0x14
#define RX_PW_P4 0x15
#define RX_PW_P5 0x16

#define FIFO_STATUS 0x17
#define TX_REUSE 6
#define TX_FULL  5
#define TX_EMPTY 4
#define RX_FULL  1
#define RX_EMPTY 0

#define DYNPD 0x1C
#define DPL_5 5
#define DPL_4 4
#define DPL_3 3
#define DPL_2 2
#define DPL_1 1
#define DPL_0 0

#define FEATURE 0x1D
#define EN_DPL     2
#define EN_ACK_PAY 1
#define EN_DYN_ACK 0

// SPI transfer, MSB first
uint8_t spi_transfer(uint8_t data)
{
  USIDR = data;
  USISR = _BV(USIOIF); // clear flag

  while ((USISR & _BV(USIOIF)) == 0)
  {
    USICR = (1<<USIWM0)|(1<<USICS1)|(1<<USICLK)|(1<<USITC);
  }
  
  return USIDR;
}

void setup()
{
  pinMode(MISO_PIN,  INPUT);
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(SCLK_PIN, OUTPUT);
  pinMode(CSN_PIN,  OUTPUT);
  
  // Wait 100 milliseconds for the NRF24 to warm up
  delay(100);
}

void loop()
{
  // lol
}
