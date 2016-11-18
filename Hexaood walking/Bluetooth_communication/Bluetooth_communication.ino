
int pwm_a = 3;
int pwm_b = 11;
int dir_a = 12;
int dir_b = 13;

#include <Servo.h> 
Servo hexabaseservo;  // create servo object to control a servo 
Servo cameraservo; 
int angle_base = 0;
int angle_camera = 0;


#include <SoftwareSerial.h>
SoftwareSerial BTConnection(10,9);

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


void setup(){
  
  BTConnection.begin(9600);
  Serial.begin(9600);
  hexabaseservo.writeMicroseconds(1500); //set initial servo position if desired
  hexabaseservo.attach(15);  //the pin for the servo control
  cameraservo.attach(45);  
}

char signal = ' ';
void loop(){

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
   if (signal == 'G'){
      forward();
  }
  if (signal == 'I'){
      backward();
  }
  if (signal == 'H'){
     turnleft();
  }
    if (signal == 'H'){
     turnright();
  }
 }


