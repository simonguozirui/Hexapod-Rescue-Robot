#include <DHT.h>
DHT dht(33, DHT11);
const int LTrigPin = 29; 
const int LEchoPin = 28; 
const int RTrigPin = 40; 
const int REchoPin = 39; 


void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  /*button
    stop all movement when button is pushed */
  int Buttonval = digitalRead(32);  
  if (Buttonval == HIGH) { 
 
    //stop all motion
  } 

  /*Sound 
    Read data from Left and Right Analog Sound Sensor, calculate Sound Difference 
   */
  int Lsoundval;
  Lsoundval=analogRead(7);
  if (Lsoundval > 0)
  {}//0 can be replaced by walking noise
  int Rsoundval;
  Rsoundval=analogRead(14); 
  if (Rsoundval > 0)
  {}
  int SoundDifference;
  SoundDifference = abs(Rsoundval - Lsoundval);
  
  

  /*Light
    Read data from Left, Right and Front Analog Light Sensor
   */
  int Llightval;
  Llightval=analogRead(8);   
  if (Llightval>0)
  {}
  int Rlightval;
  Rlightval=analogRead(12);   
  if (Rlightval>0)
  {}
  int Flightval;
  Flightval=analogRead(13);   
  if (Rlightval>0)
  {}
  


  /*Flame
    Read data from Left and Right Analog Flame Sensor, calculate Flame Difference 
   */
  int Lflameval;
  Lsoundval=analogRead(9);
  if (Lflameval>0)
  {}
  int Rflameval;
  Rflameval=analogRead(11); 
  if (Rflameval>0)
  {}
  int FlameDifference;
  FlameDifference = abs(Rflameval - Lflameval);


  /*Temperature and humidity
    Read data from DHT11 
   */
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  float heatindex = dht.computeHeatIndex(temp, humid, false);  
  
  
  /*Harmful Gases
    Read data from MQ135
   */
  int Airqualityval;
  Airqualityval = analogRead(10);
 

  /*Motion 
    Read data from front, left and right Motion Sensor
   */
  if (digitalRead(24) == HIGH) 
    {} 
  if (digitalRead(26) == HIGH) 
    {} 
  if (digitalRead(53) == HIGH) 
    {} 

/*Ultrosonic 
    Read data from left and right Ultrosonic Sensor
   */

   digitalWrite(LTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(LTrigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(LTrigPin, LOW); 
   float Ldistance; 
   Ldistance = pulseIn(LEchoPin, HIGH) / 58.0; 
   Ldistance = (int(Ldistance * 100.0)) / 100.0; 
  

   digitalWrite(RTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(RTrigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(RTrigPin, LOW); 
   float Rdistance;
   Rdistance = pulseIn(REchoPin, HIGH) / 58.0; 
   Rdistance = (int(Rdistance * 100.0)) / 100.0; 
  

    
  delay(500); //refresh time
  
}
