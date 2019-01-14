/* 74HC165 ESP8266 ~ NodeMCU 1.0 (ESP-12E Module)
 * speed-test reading 18 shift (in) registers
 * 
 * adapted from article by João Alves
 * https://jpralves.net/post/2015/09/08/multiple-inputs-parallel-to-series.html
 * 
 * Pinos usados: 
     D0  (gpio16) - Load Pin (1) do 74HC165 
     D6  (gpio12) - Q7 Pin (9) do 74HC165 
     D5  (gpio14) - CLOCK Pin (2) do 74HC165 
 * Sketch que usa o shiftIn. 
*/ 

const byte LATCH = D0; 
const byte DATA  = D6; 
const byte CLOCK = D5; 
const byte chips = 18; // number of 74HC165 (8bit) chips used

static unsigned long lastMillis;
static unsigned long frameCount;
static unsigned int framesPerSecond;
const int seconds = 1;

void setup() { 
  Serial.begin(230400); 
  pinMode(LATCH, OUTPUT); 
  pinMode(CLOCK, OUTPUT); 
  pinMode(DATA, INPUT); 
  digitalWrite(CLOCK, HIGH); 
  digitalWrite(LATCH, HIGH);
} 

void loop() { 
  unsigned long now = millis();
  frameCount ++; // Once around the moon ...
  
  byte Switch[chips];
  
  digitalWrite(CLOCK, HIGH); 
  digitalWrite(LATCH, LOW); 
  digitalWrite(LATCH, HIGH); 
  
  for (byte i=0; i<chips; i++) { 
    Switch[i] = shiftIn(DATA, CLOCK, MSBFIRST);
  }
  
  if (now - lastMillis >= seconds * 1000) {
    framesPerSecond = frameCount / seconds;
    
    for (byte i=0; i<8; i++) { 
      Serial.print((Switch[0] & (1<<i)) != 0 ? 0 : 1); 
    }
     
    Serial.print(" "); 
    
    for (byte i=0; i<8; i++) { 
      Serial.print((Switch[1] & (1<<i)) != 0 ? 0 : 1); 
    } 
    
    Serial.print(" "); 
    Serial.print(framesPerSecond);
    Serial.println(" fps"); 

    frameCount = 0;
    lastMillis = now;
  }
}
