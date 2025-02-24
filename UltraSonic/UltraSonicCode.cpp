const int trigPin = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 3; // Echo Pin of Ultrasonic Sensor
const int blue=8;
const int white=9;
const int yellow=7;

void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(yellow, OUTPUT);
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() 
{
  long duration, distance;
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on High state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Calculating the distance
  if (distance <= 10) 
  {
      digitalWrite(blue, HIGH);
      digitalWrite(white, LOW);
      digitalWrite(yellow, LOW);
  }
  else if (10<distance && distance <= 20) 
  {
      digitalWrite(blue, LOW);
      digitalWrite(white, HIGH);
      digitalWrite(yellow, LOW);
  }
  else 
  {
      digitalWrite(blue, LOW);
      digitalWrite(white, LOW);
      digitalWrite(yellow, HIGH);
  }
  // Prints the distance on the Serial Monitor
  Serial.print("Distnace :- ");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}
