// Define the pins for the IR sensors and motor driver
const int sensorLeft = 12;
const int sensorRight = 11;
const int motorEnableA = 6;
const int motorEnableB = 5;
const int motorPin1 = 7;
const int motorPin2 = 8;
const int motorPin3 = 9;
const int motorPin4 = 10;

// Define the threshold for detecting the line
const int threshold = 500;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the motor driver pins as outputs
  pinMode(motorEnableA, OUTPUT);
  pinMode(motorEnableB, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);

  
  // // Set the motor enable pins to HIGH
  // int leftMotorSpeed = 0;
  // int rightMotorSpeed = 0;
}

void loop() {
  Serial.println("ad");
  // Read the sensor values
  
  // digitalWrite(motorEnableA, HIGH);
  // digitalWrite(motorEnableB, HIGH);
  int sensorValue1 = digitalRead(sensorLeft);
  int sensorValue2 = digitalRead(sensorRight);

  // Check if both sensors detect the line
  if (sensorValue1 ==0 && sensorValue2 ==0) {
    // Move the robot forward
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorEnableA, 50);
    digitalWrite(motorEnableB, 50);
    Serial.println("forward");
    // delay(500);
    // Turn left
    // digitalWrite(motorPin1, LOW);
    // digitalWrite(motorPin2, HIGH);
    // digitalWrite(motorPin3, HIGH);
    // digitalWrite(motorPin4, LOW);
    // delay(300);
  }
  // Check if only sensor1 detects the line
  else if (sensorValue1 ==1 && sensorValue2 == 0) {
    // Turn left
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorEnableA,50);
    digitalWrite(motorEnableB, 80);
    delay(80);
  }
  // Check if only sensor2 detects the line
  else if (sensorValue1==0 && sensorValue2 == 1) {
    // Turn right
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorEnableA, 80);
    digitalWrite(motorEnableB, 50);
    delay(80);
   }
   //if both the sensor detects the line :
   else if(sensorValue1 == 1 && sensorValue2 == 1){
         // Move the robot forward
     delay(500);
     digitalWrite(motorPin1, HIGH);
     digitalWrite(motorPin2, LOW);
     digitalWrite(motorPin3, HIGH);
     digitalWrite(motorPin4, LOW);
     digitalWrite(motorEnableA, 50);
     digitalWrite(motorEnableB, 50);    
  // }
  // If neither sensor detects the line, stop the robot
  }
  else {
    // stop the robot
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorEnableA, 0);
    digitalWrite(motorEnableB, 0);
    // delay(100);
    // Turn right
    //digitalWrite(motorPin1, HIGH);
    //digitalWrite(motorPin2, LOW);
    //digitalWrite(motorPin3, LOW);
   // digitalWrite(motorPin4, HIGH);
    //delay(300);
  }
}
