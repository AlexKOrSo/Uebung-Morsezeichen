#include <Arduino.h>
#include "avr/io.h"
#include "morse.h"

#define LED_R 8
#define TASTER 2


volatile uint8_t button_state = HIGH;




void configurePins()
{
  DDRB  |= _BV(PORTB0);
  PORTB |= _BV(PORTB2);

}





int main()
{
  Serial.begin(9600);
  while(true)
  {
    Serial.println("main");
    delay(1000);
  }
}

///void setup()
//{
 // Serial.println("setup");/
//}


//void changeLED(void)
//{
//  button_state=!button_state;
//  digitalWrite(LED_R,button_state);
//}
//
//
//
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(LED_R, OUTPUT);
//  pinMode(TASTER, INPUT);
//  pinMode(TASTER, INPUT_PULLUP);
//  attachInterrupt(digitalPinToInterrupt(TASTER), changeLED, CHANGE);
//}
//
//
//
//
//void loop() {
//  _NOP();
//  // put your main code here, to run repeatedly:
//
//}