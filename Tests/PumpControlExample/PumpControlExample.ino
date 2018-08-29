int enable = 5;
int up = 2;
int down = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  digitalWrite(up, HIGH);
  digitalWrite(down, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int currentValue = 0; currentValue < 255; currentValue++){
      Serial.println(currentValue);
      analogWrite(enable, currentValue); 
      delay(30);
  }
}
