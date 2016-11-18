#include <DHT.h>
DHT dht(33, DHT11);
const int LTrigPin = 29; 
const int LEchoPin = 28; 
const int RTrigPin = 40; 
const int REchoPin = 39; 


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LTrigPin, OUTPUT); 
  pinMode(LEchoPin, INPUT); 
  pinMode(RTrigPin, OUTPUT); 
  pinMode(REchoPin, INPUT); 
}

void loop(){
  /*button
    stop all movement when button is pushed */
  int Buttonval = digitalRead(32);  
  if (Buttonval == HIGH) { 
    Serial.println("button pressed");
    //stop all motion
  } 

  /*Sound 
    Read data from Left and Right Analog Sound Sensor, calculate Sound Difference 
   
  int Lsoundval;
  Lsoundval=analogRead(7);
  Serial.print("Left Sound Value " );  
  Serial.print(Lsoundval,DEC);
  int Rsoundval;
  Rsoundval=analogRead(14); 
  Serial.print(" Reft Sound Value " );   
  Serial.print(Rsoundval,DEC);
  int SoundDifference;
  SoundDifference = abs(Rsoundval - Lsoundval);
  Serial.print(" SoundDifference");
  Serial.println(SoundDifference, DEC);
  */

  /*Light
    Read data from Left, Right and Front Analog Light Sensor
  
  int Llightval;
  Llightval=analogRead(8);   
  Serial.print("Left Light Value ");
  Serial.print(Llightval,DEC);
  int Rlightval;
  Rlightval=analogRead(12);   
  Serial.print(" Right Light Value ");
  Serial.print(Rlightval,DEC);
  int Flightval;
  Flightval=analogRead(13);   
  Serial.print(" Front Light Value ");
  Serial.println(Flightval,DEC);
  */

  /*Flame
    Read data from Left and Right Analog Flame Sensor, calculate Flame Difference 
   
  int Lflameval;
  Lsoundval=analogRead(9);
  Serial.print("Left Flame Value " );  
  Serial.print(Lflameval,DEC);
  int Rflameval;
  Rflameval=analogRead(11); 
  Serial.print(" Right Flame Value " );   
  Serial.print(Rflameval,DEC);
  int FlameDifference;
  FlameDifference = abs(Rflameval - Lflameval);
  Serial.print(" FlameDifference");
  Serial.println(FlameDifference, DEC);
   */

  /*Temperature and humidity
    Read data from DHT11 
  
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  float heatindex = dht.computeHeatIndex(temp, humid, false);  
  Serial.print("humidity " );   
  Serial.print(humid, 0);
  Serial.print(" temp " );   
  Serial.print(temp, 0);
  Serial.print(" heatindex " );   
  Serial.println(heatindex, 0);
*/
  
  /*Harmful Gases
    Read data from MQ135*/
   
  int Airqualityval;
  Airqualityval = analogRead(10);
  Serial.print("Air Quality " ); 
  Serial.println( Airqualityval, DEC);  
 
  /*Motion 
    Read data from front, left and right Motion Sensor
   
  if (digitalRead(24) == HIGH) 
    {Serial.println("Left Motion Detected");} 
  if (digitalRead(26) == HIGH) 
    {Serial.println("Right Motion Detected");} 
  if (digitalRead(53) == HIGH) 
    {Serial.println("Front Motion Detected");} 
  */
   /*Ultrosonic 
    Read data from left and right Ultrosonic Sensor
   

   digitalWrite(LTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(LTrigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(LTrigPin, LOW); 
   float Ldistance; 
   Ldistance = pulseIn(LEchoPin, HIGH) / 58.0; 
   Ldistance = (int(Ldistance * 100.0)) / 100.0; 
   Serial.print("Left Distance "); 
   Serial.print(Ldistance); 
   Serial.print(" cm "); 

   digitalWrite(RTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(RTrigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(RTrigPin, LOW); 
   float Rdistance;
   Rdistance = pulseIn(REchoPin, HIGH) / 58.0; 
   Rdistance = (int(Rdistance * 100.0)) / 100.0; 
   Serial.print(" Right Distance "); 
   Serial.print(Rdistance); 
   Serial.println(" cm "); 
   */


    
   delay(500); //refresh time
  
}
