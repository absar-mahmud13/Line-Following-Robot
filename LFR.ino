// Pin Definitions
const int leftMotorForward = 5;
const int leftMotorBackward = 6;
const int rightMotorForward = 9;
const int rightMotorBackward = 10;

const int leftSensor = A0;  // Left IR sensor
const int rightSensor = A1; // Right IR sensor

void setup() {
  // Set up motor pins as output
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  // Set up sensor pins as input
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(leftSensor);
  int rightSensorValue = analogRead(rightSensor);

  // Debugging sensor values
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensorValue);

  // Threshold for detecting the line (adjust according to your setup)
  int threshold = 500;

  // Line-following logic
  if (leftSensorValue < threshold && rightSensorValue < threshold) {
    // Both sensors are on the line, move forward
    moveForward();
  } else if (leftSensorValue < threshold && rightSensorValue > threshold) {
    // Left sensor on the line, turn left
    turnLeft();
  } else if (leftSensorValue > threshold && rightSensorValue < threshold) {
    // Right sensor on the line, turn right
    turnRight();
  } else {
    // Both sensors off the line, stop or adjust accordingly
    stopRobot();
  }

  delay(100); // Add delay for stability
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

// Function to stop the robot
void stopRobot() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
