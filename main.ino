const int sensPin = 39;
const int ledPin = 33;

long last = 0;
long del = 500;
bool ledOn = false;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensValue = 4096 - analogRead(sensPin);
  Serial.println(sensValue);

  
  delay(100);

  if ((millis() - last) > del) {
      ledOn = !ledOn;
      digitalWrite(ledPin, ledOn);
      last = millis();
  }
}
