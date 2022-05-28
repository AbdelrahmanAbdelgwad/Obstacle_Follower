#define echoPin 8 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 9 //attach pin D3 Arduino to pin Trig of HC-SR04
#include<Servo.h>  // servo library to control right and left servo

// defines variables
long duration; // variable for the duration of sound wave travel
int d_t; // variable for the distance measurement
int D_t = 10;  // desired distance to keep 

float e_sum = 0;   // variable to accumulte the sum of errors for the integral term     
float e_t;         // variable for the current error 

float P_I_D;       // variable for the PID controller value
int prev = 0;      // variable for the previous error  
float servo_r;     // variable for the value of the right servo
float servo_l;     // variable for the value of the right servo
Servo servo_left;  // Defining left servo
Servo servo_right; // Defining right servo

// tuned PID parameter values
int kp = 5;
int ki = 0.45;
int kd = 0.05;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  servo_right.attach(4);
  servo_left.attach(5);
}
void loop() {
  Ultrasonic_sensor();
  PID_control(kp,ki,kd,d_t); 
  Servo_control(P_I_D);
  }

  
int Ultrasonic_sensor()    // Function for Ultrasonic sensor readings 
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  d_t = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(d_t);
  Serial.println(" cm");
  return d_t;
  }


float PID_control(int kp, int ki, int kd, int d_t )   // Function for PID control
{
  e_t = D_t - d_t;
  e_sum = e_sum + e_t;
  P_I_D = kp*e_t + ki*e_sum + kd*(e_t - prev);
  prev = e_t;
  if (e_t > 2 && e_t < -2)
  {e_sum = 0;}
  Serial.print("PID = ");
  Serial.println(P_I_D);
  return P_I_D;
  }


  void Servo_control(float P_I_D)   // Function for servos control using PID values
  {
  servo_r = map(P_I_D,-38,38,1100,1900);
  servo_l = map(P_I_D,-38,38,1900,1100);
  servo_right.writeMicroseconds(servo_r);
  servo_left.writeMicroseconds(servo_l);
    }
