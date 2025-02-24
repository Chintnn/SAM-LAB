const int infrared=7; /* infrared sensor O/P pin */
const int ledpin=3;
const int buzzerpin=3;

void setup()
{
  pinMode(infrared, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop()
{
  int sensor_output;
  sensor_output = digitalRead(infrared);
  if(sensor_output == HIGH)
  {
    Serial.print("no object in sight\n\n");
    digitalWrite(ledpin, LOW);
    digitalWrite(buzzerpin, LOW);
    delay(500);
  }
  else 
  {
    Serial.print("object detected\n\n");
    digitalWrite(ledpin, HIGH);
    digitalWrite(buzzerpin, HIGH);
    delay(500);
  }
}