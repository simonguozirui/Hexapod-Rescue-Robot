/*
int E1 = 3;     //M1 Speed Control
int E2 = 11;     //M2 Speed Control
int M1 = 12;     //M1 Direction Control
int M2 = 13;     //M1 Direction Control

void setup() {
  // put your setup code here, to run once:

}

void stopmove()                    //Stop
{
  digitalWrite(E1,0); 
  digitalWrite(M1,LOW);    
  digitalWrite(E2,0);   
  digitalWrite(M2,LOW);    
}   
void forward ()          //Move forward
{
  analogWrite (E1,255);      //PWM Speed Control
  digitalWrite(M1,LOW);    
  analogWrite (E2,255);    
  digitalWrite(M2,LOW);
}  
void backward ()          //Move backward
{
  analogWrite (E1,255);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,255);    
  digitalWrite(M2,LOW);
}
void turnleft ()             //Turn Left
{
  analogWrite (E1,255);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,255);    
  digitalWrite(M2,LOW);
}
void turnright ()             //Turn Right
{
  analogWrite (E1,255);
  digitalWrite(M1,LOW);    
  analogWrite (E2,255);    
  digitalWrite(M2,HIGH);
}
 
void loop()
{
  //stopmove ();
  delay(1000);
 forward ();
  delay(1000);
 // backward (); 
  delay(1000);
  //turnleft (); 
  delay(1000);
  //turnright ();
  delay(2000);

}*/


/*
 5/22/2012
  Timothy Holmberg
  SparkFun Electronics
  
  This code includes the ddition of fade in and out PWM. Also a stop feature. And the addition of individual functions for motor control 
  
  This was a revision of the example sketch that originated from Pete Dokter's code for Arduino that shows very basically how to control an Ardumoto 
  motor driver shield with a 5V Arduino controller board. http://www.sparkfun.com/datasheets/DevTools/Arduino/Ardumoto_test_3.pde
  
  This also includes parts of the Fading Example,  Created 1 Nov 2008 By David A. Mellis, modified 30 Aug 2011 By Tom Igoe http://arduino.cc/en/Tutorial/Fading
 
*/

int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 12;  //direction control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 13;  //direction control for motor outputs 3 and 4 is on digital pin 13

void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);\
}

void loop()
{  
  stop();
  delay(1000);
  backward();    
  delay(1000);
  forward();      
  delay(1000);
  left();
  delay(1000);
  right();
  delay(1000);
}


/* Let's take a moment to talk about these functions. The forw and back functions are simply designating the direction the motors will turn once they are fed a PWM signal.
If you only call the forw, or back functions, you will not see the motors turn. On a similar note the fade in and out functions will only change PWM, so you need to consider
the direction you were last set to. In the code above, you might have noticed that I called forw and fade in the same grouping. You will want to call a new direction, and then
declare your pwm fade. There is also a stop function. 
*/


void foreward() //full speed forward
{ 
  digitalWrite(dir_a, HIGH);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, HIGH);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, 255);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 255);
}

void backward() //full speed backward
{
  digitalWrite(dir_a, LOW);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 255);   //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);
}


void left() //full speed backward
{
  digitalWrite(dir_a, HIGH);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 255);   //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);
}


void right() //full speed backward
{
  digitalWrite(dir_a, LOW);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, HIGH);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 255);   //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 255);
}
void stop() //stop
{ 
  digitalWrite(dir_a, LOW); //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW); //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 0);    //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 0); 
}

