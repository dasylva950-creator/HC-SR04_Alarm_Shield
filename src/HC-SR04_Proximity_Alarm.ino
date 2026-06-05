// Pin Definitions
const int trigPin = 9;      // HC-SR04 Trigger pin
const int echoPin = 10;     // HC-SR04 Echo pin
const int alertPin = 13;    // Pin connected to both LED and Active Buzzer

// Threshold Configuration
const int distanceThreshold = 50; // Trigger distance in centimeters

void setup() {
  // Initialize serial communication for monitoring
  Serial.begin(9600);
  
  // Define pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertPin, OUTPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by sending a 10-microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin; returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  // Speed of sound is ~343 m/s or 0.0343 cm/us. 
  // Divide by 2 because the wave travels to the object and back.
  int distance = duration * 0.0343 / 2;
  
  // Print distance to the Serial Monitor (useful for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if an object is within the 50cm threshold
  // Note: 'distance == 0' handles out-of-range sensor errors
  if (distance > 0 && distance <= distanceThreshold) {
    digitalWrite(alertPin, HIGH);  // Turn on LED and Buzzer
  } else {
    digitalWrite(alertPin, LOW);   // Turn off LED and Buzzer
  }
  
  // Brief delay before the next measurement
  delay(100);
}
