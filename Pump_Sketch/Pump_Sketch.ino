int ENA = 9;
int IN1 = 7;
int IN2 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(ENA, 255);
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 
}
