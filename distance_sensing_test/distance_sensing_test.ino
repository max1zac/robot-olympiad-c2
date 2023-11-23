//Later change to TOF sensor
// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
const int buzzPin = 11;
// defines variables
float duration, distance;
const float target_distance = 3; //Adjust if the bot crashes

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

int measure_distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration*0.0343)/2;
  return distance;
}

void loop() {
  distance = measure_distance();
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance <= target_distance){
    tone(buzzPin,1500);
    Serial.println("STOP MOVING!!!");

  }
  else{
    noTone(buzzPin);
  }
}