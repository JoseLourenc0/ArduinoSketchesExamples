# ArduinoSketchesExamples  
Arduino Sketches using the arduino bluetooth module HC-06 (SLAVE), SERVO MOTOR SG90 and HC-SR04 Ultrasonic sensor (Lib Ultrasonic.h included in Ultrasonic-master.zip).  

COMMUNICATION-HC-06: Ultrasonic Sensor reads the container's level (in that project it'll be used to measure alcohol level, which in that case just for example, it's been used 30cm for a container) and send to the bluetooth module (HC-06), which send to a smartphone connected to the module to be readen for someone (App indicated: BlueCore Tech Serial Monitor-Arduino).  

READING-HC-SR04: Ultrasonic Sensor reads the distance (you can choose in cm or in inches) and if it's less than 20cm (just for example in the code), SG90 rotates in 180 degrees and returns to originial position.
