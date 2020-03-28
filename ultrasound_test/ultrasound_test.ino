const int trigPin = 6;
const int echoPin = 7;

// defines variables
long duration;
int distance;

int state = 0;
long lastStateChanged = 0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  long currentTime = millis();
  if (state == 0 && distance < 10 && currentTime - lastStateChanged > 3000 ) {
    state = 1;
    lastStateChanged = millis();
    motorRun();
  }
  delay(400);
}

void motorRun() {
  Serial.println("Run Motor");

  state = 0;
}
