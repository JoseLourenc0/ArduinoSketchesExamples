#include <SoftwareSerial.h> //Bluetooth Arduino module lib (Module HC-06)
#include <Ultrasonic.h> //HC-SR04 Arduino sensor lib --> Add the lib using the zip file "Ultrasonic-master"

#define TRIGGER_PIN  3 //Trigger defined as the 3rd port, you can choose another one if you want
#define ECHO_PIN     2 //Echo defined as the 2nc port, you can choose another one if you want

SoftwareSerial serial1(10, 11); // RX=10, TX=11 , you can't choose the RX,TX ports cuz they're used for Arduino Serial communication with the system (in this project it's setted to be used to read the sensor HC-SR04 data

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN); //Setting the sensor values for arduino (lib Ultrasonic.h code, search about the lib you're using)

String textoRecebido = ""; 
unsigned long delay1 = 0;

void setup() {

  serial1.begin(9600); 
  Serial.begin(9600);

}

void loop() {
  
  delay(1000); //It just read in each second due the communication with the Module HC-06 used
  float cmMsec, inMsec; 
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);//cmMsec will read the distance in Centimeters 
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);//inMsec will read the distance in Inches
  Serial.print("Distancia: "); //The message is in portuguese and it means "Distance"
  Serial.println(cmMsec);//Here you can use inMsec instead of cmMsec for distance in inches

  /*PC=how much of the container is filled, PT=how much the container has in centimeters/inches , PV=how much of the container is empty :
  In that case 30cm will be used just as an example
  PC=PT-PV , PC=30-cmMsec -->cm . PC% = PC*100/30 
  */
  float fPC=(30-cmMsec)*10/3; //Here you can use inMsec instead of cmMsec for distance in inches
  serial1.print("Nível do containere: "); //The message in your smartphone, you can use the app "BlueCore Tech Serial Monitor - Arduino" , the message is in portuguese and it means "Container Level" given in percentage
  serial1.print(fPC);
  serial1.println("%");   
}
