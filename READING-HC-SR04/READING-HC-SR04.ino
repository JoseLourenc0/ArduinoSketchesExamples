    //**SERVO MOTOR SG90**
#include <Servo.h> //Including the SERVO lib
#define SERVO 8 //8th port setted for SERVO module
Servo s; //Calling Servo as s for it's reading
int pos; // Servo Position

    //**SENSOR HC-SR04**
#include <Ultrasonic.h> //HC-SR04 Arduino sensor lib --> Add the lib using the zip file "Ultrasonic-master"
#define TRIGGER_PIN  3 //Trigger defined as the 3rd port, you can choose another one if you want
#define ECHO_PIN     2 //Echo defined as the 2nc port, you can choose another one if you want
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);//Setting the sensor values for arduino (lib Ultrasonic.h code, search about the lib you're using)


void setup() {
    //**SERVO**
    s.attach(SERVO); //Defining servo reading of position
    Serial.begin(9600);
    s.write(0); //SERVO starts at position 0

}

void loop() {
  

    //**SENSOR**
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);//cmMsec will read the distance in Centimeters 
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);//inMsec will read the distance in Inches
  Serial.print("Distancia: "); //The message is in portuguese and it means "Distance"
  Serial.println(cmMsec);//Here you can use inMsec instead of cmMsec for distance in inches
  //**SERVO**
  delay(50);
  if(cmMsec<20){
    for(pos=0;pos<180;pos++){//SERVO increases its position even 180° (that's the limit of SG90 model)
      s.write(pos);
      delay(5); //delay it's used because it decreases the precision of the angle/movement if it goes too fast in each angle
    }
    delay(100);
    for(pos=180;pos>=0;pos--){//it returns to the original position
      s.write(pos);
      delay(5); //delay it's used because it decreases the precision of the angle/movement if it goes too fast in each angle
    }
  }
}
