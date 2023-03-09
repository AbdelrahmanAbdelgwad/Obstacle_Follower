# Obstacle Follower Arduino Code

## Introduction
This project demonstrates a simple obstacle-following robot using an ultrasonic sensor and a PID controller. The robot uses two servos to maintain a desired distance from an obstacle.

## Components
* Arduino UNO
* HC-SR04 ultrasonic sensor
* Two continuous servo motors
* Breadboard and jumper wires

## Operation
The robot uses the ultrasonic sensor to measure the distance to the obstacle, and the PID controller to adjust the servo angles to maintain a desired distance. The servos control the robot's motion, allowing it to follow the obstacle while keeping a constant distance.

## Limitations
Currently, the robot can only follow obstacles in one dimension (forward/backward). Additionally, the code may need to be tuned for different hardware configurations or operating environments.

## Future Improvements
Future versions of this project could include:
* Improved obstacle detection using multiple sensors or other technologies
* Additional motion control features, such as turning or avoiding obstacles
* Integration with other hardware or software platforms, such as a Raspberry Pi or ROS

