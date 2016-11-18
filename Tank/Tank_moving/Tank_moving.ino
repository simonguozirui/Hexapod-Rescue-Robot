
const int LTrigPin = 29; 
const int LEchoPin = 28; 
const int RTrigPin = 40; 
const int REchoPin = 39; 
const int FTrigPin = 50; 
const int FEchoPin = 49; 
const int ButtonPin = 32;
const int LsoundPin = 7;
const int RsoundPin = 14;
const int LMotionPin = 24;
const int RMotionPin = 26;
const int FMotionPin = 53;
const int GreenledPin = 41;

int pwm_a = 3;   
int pwm_b = 11;  
int dir_a = 12;  
int dir_b = 13;  
#include <DHT.h>
DHT dht(33, DHT11);
#include <Servo.h> 
Servo hexabaseservo;  // create servo object to control a servo 
int angle_base = 0;
Servo cameraservo; 
int angle_camera = 0;
char signal = ' ';
#include <SoftwareSerial.h>
SoftwareSerial BTConnection(10,9);

void setup() {

  pinMode(LTrigPin, OUTPUT); 
  pinMode(LEchoPin, INPUT); 
  pinMode(RTrigPin, OUTPUT); 
  pinMode(REchoPin, INPUT); 
  pinMode(FTrigPin, OUTPUT); 
  pinMode(FEchoPin, INPUT); 
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  pinMode(ButtonPin,INPUT);
  pinMode(LMotionPin,INPUT);
  pinMode(RMotionPin,INPUT);
  pinMode(FMotionPin,INPUT);
  pinMode(GreenledPin, OUTPUT);
  Serial.begin(9600); 
  BTConnection.begin(9600); 
  cameraservo.attach(45);  
}



void backward() 
{ 
  digitalWrite(dir_a, HIGH);  
  digitalWrite(dir_b, HIGH);  
  analogWrite(pwm_a, 255);    
  analogWrite(pwm_b, 255);
}

void forward() 
{
  digitalWrite(dir_a, LOW);  
  digitalWrite(dir_b, LOW);  
  analogWrite(pwm_a, 255);   
  analogWrite(pwm_b, 255);
}


void turnleft() 
{
  digitalWrite(dir_a, HIGH);  
  digitalWrite(dir_b, LOW);  
  analogWrite(pwm_a, 255);   
  analogWrite(pwm_b, 255);
}


void turnright() //full speed backward
{
  digitalWrite(dir_a, LOW);  
  digitalWrite(dir_b, HIGH);  
  analogWrite(pwm_a, 255);   
  analogWrite(pwm_b, 255);
}
void stopmove() //stop
{ 
  digitalWrite(dir_a, LOW); 
  digitalWrite(dir_b, LOW); 
  analogWrite(pwm_a, 0);    
  analogWrite(pwm_b, 0); 
}

void motioncheck ()
{
   
   stopmove();
   int FMotionval=digitalRead(FMotionPin);
   int LMotionval=digitalRead(LMotionPin);
   int RMotionval=digitalRead(RMotionPin);
   if (FMotionval == HIGH || LMotionval == HIGH || RMotionval == HIGH)
   {Serial.println("find sth");
      Serial.print(FMotionval);
      Serial.print(LMotionval);
      Serial.println(RMotionval);}
   delay(1000);
}

void lightstop ()
{ 
  int Llightval;
  int Rlightval;
  int Flightval;
  Llightval=analogRead(8);   
  Rlightval=analogRead(12); 
  Flightval=analogRead(13);   
  Serial.print(Llightval);
  while (Llightval >1000 || Rlightval >1000 || Flightval> 1000)
  { 
    Serial.print(Llightval);
    Serial.print(Rlightval);
    Serial.print(Flightval);
    stopmove (); Serial.print("Llightval");    
    //remotemode();
  }
}


void hexabasemotorkeep90()
{
hexabaseservo.attach(15);  //the pin for the servo control 
angle_base = 105;
hexabaseservo.write(angle_base);
}

void ultrosnicwalking()
{
   digitalWrite(LTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(LTrigPin, HIGH); 
   float Ldistance; 
   Ldistance = pulseIn(LEchoPin, HIGH) / 58.0;  
   Serial.print (Ldistance,0);
   Serial.print(" ");

   digitalWrite(RTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(RTrigPin, HIGH); 
   float Rdistance;
   Rdistance = pulseIn(REchoPin, HIGH) / 58.0; 
   Serial.print (Rdistance,0);
   Serial.print(" ");
   
   digitalWrite(FTrigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(FTrigPin, HIGH); 
   float Fdistance; 
   Fdistance = pulseIn(FEchoPin, HIGH) / 58.0; 
   Serial.println (Fdistance,0);
   
   if (Fdistance<20 && (Ldistance >20 || Rdistance >20)) 
   {  Serial.println("Turning Left");
      if(Ldistance > Rdistance)
      {turnleft ();}
      else
      {turnright ();}
    }
   else if(Fdistance<20 && (Ldistance <20 && Rdistance <20)) 
   {//turn platform to search
   }
   else if (Fdistance>20 && (Ldistance >20 && Rdistance >20))
   {    //Serial.print("driving Forward");
    forward();}
   /*else if (Fdistance>20 && (Ldistance <20 || Rdistance <20))
   {if(Ldistance > Rdistance)
      {turnleft ();}
      else
      {turnright ();}   
   }*/   
}

void soundstop()
{
  int Lsoundval;
  Lsoundval=analogRead(LsoundPin);
  Serial.print(Lsoundval,DEC);
  Serial.print(" ");
  int Rsoundval;
  Rsoundval=analogRead(RsoundPin); 
  Serial.println(Rsoundval,DEC);
  while (Lsoundval >150 || Rsoundval >150)
  {
    stopmove ();
    //remotemode();
  }
}

void temphumid ()
{
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  float heatindex = dht.computeHeatIndex(temp, humid, false);  
  BTConnection.print("humidity " );   
  BTConnection.print(humid, 0);
  BTConnection.print(" temp " );   
  BTConnection.print(temp, 0);
  BTConnection.print(" heatindex " );   
  BTConnection.println(heatindex, 0);
}

void Airquality ()
{
  int Airqualityval;
  Airqualityval = analogRead(10);
  BTConnection.print("Air Quality " ); 
  BTConnection.println( Airqualityval, DEC); 
   
}



void flameturn ()
{ 
  int Lflameval;
  Lflameval=analogRead(9);
  //Serial.print("Left Flame Value " );  
  //Serial.print(Lflameval,DEC);
  if (Lflameval > 100)
   {turnright();
   Serial.print("l");}
  int Rflameval;
  Rflameval=analogRead(11); 
  //Serial.print(" Right Flame Value " );   
  //Serial.print(Rflameval,DEC);
   if (Rflameval > 100)
   {turnleft();Serial.print("r");}  
}

void Greenled()
{
  digitalWrite(GreenledPin, HIGH); 
}

void remotemode()
{ int i = 0;
  //for (i = 0; i < 100; i++){
   // BTConnection.println("Possible life signal!!! Please open remote");}
  if (BTConnection.available()){
    signal = BTConnection.read();
    Serial.print(signal);

  }
  if (signal == 'L'){
    angle_base -=1;
    hexabaseservo.write(angle_base);
    delay(10); 
  }
  if (signal == 'R'){
    angle_base +=1;
    hexabaseservo.write(angle_base);
    delay(10); 
  }
  
    if (signal == 'F'){
    angle_camera -=1;
    cameraservo.write(angle_camera);
    delay(15); 
  }
  if (signal == 'B'){
    angle_camera +=1;
    cameraservo.write(angle_camera);
    delay(15); 
  }
}

void gps()
{
   BTConnection.println("GPS location: 9999.9999, 9999.9999");
}
void loop()
{ 

  remotemode();
   
  /*int i = 0;
  for (i = 0; i < 100; i++)
  {
   //buttonstop ();
   hexabasemotorkeep90();
   //forward();
   ultrosnicwalking();
   soundstop ();
   //temphumid ();
   //Airquality ();
   //lightstop ();
   //flameturn ();
   //Greenled();
   //gps();
  }
  
 /* for (i = 0; i< 5; i++)
  {
   buttonstop ();
   motioncheck ();
   Greenled();
  }*/ 
}




