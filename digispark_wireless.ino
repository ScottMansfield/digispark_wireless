/**
 * Minimal setup to transmit by an NRF24L01+ wireless module.
 * The fun part is using a digispark and keeping the code to a minimum.
 * 
 * @author Scott Mansfield
 */

#include "NRF24L01P.h"
#include "pins.h"

void setup_NRF24L01P()
{
  // NRF24L01+ needs 100ms for both power on ramp up
  // (max) and the power on reset (max), so wait 200ms
  delay(200);
  
  // set configuration here
  
  // set PWR_UP to 1 to move to standby
  // The chip enable pin is tied to high,
  //  so it immediately moves to standby-II
  // lol
  
  // wait 5 ms for crystal to stabilize
  delay(5);
}

// SPI transfer, MSB first
uint8_t spi_transfer(uint8_t data)
{
  digitalWrite(CSN_PIN, LOW);
  
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
  
  // SPI chip select is active-low
  digitalWrite(CSN_PIN, HIGH);
  
  setup_NRF24L01P();
}

void loop()
{
  // lol
}
