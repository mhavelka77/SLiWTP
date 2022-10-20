// tick variables
long lastTick = 0;
long tickDelay = 2;

// transmitter variables
const int ledPin = 33;
bool ledOn = false;
char currentByte;
bool sending = false;
int currentBit = 7;

// receiver variables
const int sensPin = 39;
bool receiving = false;
int currentReceivedBit = 7;
char receivedValue = 0;
int logicalThreshold = 0;


void setup() {
  // setup
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // calibration
  digitalWrite(ledPin, HIGH);
  delay(100);
  int highValue = 4096 - analogRead(sensPin);
  digitalWrite(ledPin, LOW);
  delay(100);
  int lowValue = 4096 - analogRead(sensPin);
  // set the threshold as a middle value between HIGH and LOW
  logicalThreshold = (highValue + lowValue) / 2;
  
  // print out the values
  Serial.println(highValue);
  Serial.println(lowValue); 
}

void loop() {
  
  // using internal clock to run the tick every 'tickDelay' ms
  if ((millis() - lastTick) > tickDelay) {
      
      // TRANSMITTER CODE
      
      // Begin sending byte if received on serial line
      if (!sending && Serial.available() > 0) {
        currentByte = Serial.read();
        sending = true;
        ledOn = true;
      } else if (sending) {
        ledOn = (currentByte >> currentBit) & 0x01; // step by step take each of the 8 bits in char
        currentBit--;
        // if one byte is sent, end the process of sending
        if (currentBit < 0) {
          currentBit = 7;
          sending = false;
        }
      } else {
        ledOn = false;  
      }

      // write the desired bit
      digitalWrite(ledPin, ledOn);
      
     
      
      // RECEIVER CODE
      delay(0); // wait for the LED to light up (probably unnecesarry when running on RTOS)
      int receivedBit = 0;
      int sensValue = 4096 - analogRead(sensPin);
      // determine logical value from analog signal
      if (sensValue > logicalThreshold) {
        receivedBit = 1;
      } else {
        receivedBit = 0;
      }

      // If receiving is active, compute the byte value bit by bit
      if (receiving) { 
        receivedValue += receivedBit * (pow(2, currentReceivedBit));
        currentReceivedBit--;

        // end of receiving one byte
        if (currentReceivedBit < 0) {
          receiving = false;
          currentReceivedBit = 7;
          Serial.print(receivedValue);
          receivedValue = 0;
        }
      } else {
        if (receivedBit == 1) {
          receiving = true;  
        }
      }
      

      // loop maintanance
      lastTick = millis();  
  }
}
