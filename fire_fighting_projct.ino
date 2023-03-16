
#include <SoftwareSerial.h> // Library for using serial communication
SoftwareSerial SIM900(6,7); // Pins 10, 11 are used as used as software serial pins TX AND RX RESP
String incomingData;   // for storing incoming serial data
boolean state=0;
String number="";
String message;
unsigned char FLAG_ON=0;
int buzzer=3;
int pump=4; 
int flame=2;

void pumpon(void);
void pumpoff(void);
void initialise(void);
void callprocess(void);
void setup()
{
  pinMode(buzzer,OUTPUT);
  pinMode(pump,OUTPUT);
  pinMode(flame,INPUT);
  digitalWrite(buzzer,LOW);
 digitalWrite(pump,HIGH); 
initialise();  
}

void loop()
{
if(digitalRead(flame)==LOW){
digitalWrite(buzzer,HIGH);
 digitalWrite(pump,LOW); 
Serial.println("Sending SMS..");
number= "8660381200";
 message="FIRE ALERT";
  SIM900.print("AT+CMGS=\""+number+"\"\n"+message+(char)26); // Replace it with your mobile number
   delay(5000);

number= "7090736385";
 message="FIRE ALERT";
  SIM900.print("AT+CMGS=\""+number+"\"\n"+message+(char)26); // Replace it with your mobile number
   delay(5000);

 
}

else{
digitalWrite(buzzer,LOW);
 digitalWrite(pump,HIGH); 

}
}
void initialise(void)
{
 
  Serial.begin(9600); // baudrate for serial monitor
  SIM900.begin(9600); // baudrate for GSM shield
  delay(15000);
  SIM900.print("AT\r");
  delay(100);
  SIM900.print("AT+CMGF=1\r");
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  SIM900.print("AT&W\r");
  delay(100);
  SIM900.print("AT+CMGDA=ALL\"\r");
  delay(100);
  SIM900.print("AT+CMGS=\"7090736385\"\r"); // Replace it with your mobile number
  delay(100);

  SIM900.print("POWER ON");   // The SMS text you want to send
  delay(100);
  SIM900.print((char)26);  // ASCII code of CTRL+Z
 SIM900.println();
 
}
