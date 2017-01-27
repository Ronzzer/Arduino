//
// NodeMCU blinky
//
// Assign Arduino Friendly Names to GPIO pins
   #define D0 16
   #define D1 5     // I2C Bus SCL (clock)
   #define D2 4     // I2C Bus SDA (data)
   #define D3 0
   #define D4 2     // Same as "LED_BUILTIN", but inverted logic
   #define D5 14    // SPI Bus SCK (clock)
   #define D6 12    // SPI Bus MISO 
   #define D7 13    // SPI Bus MOSI
   #define D8 15    // SPI Bus SS (CS)
   #define D9 3     // RX0 (Serial console)
   #define D10 1    // TX0 (Serial console)
 
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(D7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
