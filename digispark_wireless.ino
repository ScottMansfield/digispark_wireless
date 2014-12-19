/**
 * Minimal setup to transmit by an NRF24L01+ wireless module.
 * The fun part is using a digispark and keeping the code to a minimum.
 * 
 * @author Scott Mansfield
 */

#include "NRF24L01P.h"

// MISO / DI / pin 0
#define MISO_PIN 0

// MOSI / DO / pin 1
#define MOSI_PIN 1

// SCLK / SCK / pin 2
#define SCLK_PIN 2

// CSN / pin3
#define CSN_PIN 3

void setup_NRF24L01P()
{
  // lol
}

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
  
  setup_NRF24L01P();
}

void loop()
{
  // lol
}
