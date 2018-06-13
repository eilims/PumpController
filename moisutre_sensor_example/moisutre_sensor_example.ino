uint8_t powerPin = 2;
uint8_t dataPin1 = A0;
uint8_t dataPin2 = A1;
uint8_t dataPin3 = A2;
uint8_t dataPin4 = A3;
uint8_t count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(powerPin, HIGH);
  delay(100);
  uint16_t data1 = analogRead(dataPin1);
  uint16_t data2 = analogRead(dataPin2);
  uint16_t data3 = analogRead(dataPin3);
  uint16_t data4 = analogRead(dataPin4);
  Serial.print("Sensor 1: ");
  Serial.println(data1);
  Serial.print("Sensor 2: ");
  Serial.println(data2);
  Serial.print("Sensor 3: ");
  Serial.println(data3);
  Serial.print("Sensor 4: ");
  Serial.println(data4);
  delay(500);
}
