// Pin Definitions
const int motor1Pin1 = 5;  // Motor 1 Forward
const int motor1Pin2 = 6;  // Motor 1 Backward
const int motor2Pin1 = 9;  // Motor 2 Forward
const int motor2Pin2 = 10; // Motor 2 Backward

// Sensor pins (6-sensor TCRT array)
const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;
const int sensor4 = A3;
const int sensor5 = A4;
const int sensor6 = A5;

void setup() {
  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set sensor pins as input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int s1 = analogRead(sensor1);
  int s2 = analogRead(sensor2);
  int s3 = analogRead(sensor3);
  int s4 = analogRead(sensor4);
  int s5 = analogRead(sensor5);
  int s6 = analogRead(sensor6);

  // Debugging sensor values
  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.print(s4); Serial.print(" ");
  Serial.print(s5); Serial.print(" ");
  Serial.println(s6);

  // Threshold value to detect the line (adjust based on your environment)
  int threshold = 500;

  // Line-following logic based on sensor values
  if (s3 < threshold && s4 < threshold) {
    // Move forward when the middle sensors detect the line
    moveForward();
  } else if (s1 < threshold || s2 < threshold) {
    // Turn left when left sensors detect the line
    turnLeft();
  } else if (s5 < threshold || s6 < threshold) {
    // Turn right when right sensors detect the line
    turnRight();
  } else {
    // Stop if no sensors detect the line
    stopRobot();
  }

  delay(100);  // Short delay for stability
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to stop the robot
void stopRobot() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
