int rightSensor = A1;
int leftSensor = A2;

void setup()
{
  Serial.begin(9600);
  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("right: ");
  Serial.println(analogRead(rightSensor));
  Serial.print("left: ");
  Serial.println(analogRead(leftSensor));
  delay(1000);
}