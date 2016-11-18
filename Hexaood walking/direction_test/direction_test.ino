/*
 5/22/2012
  Timothy Holmberg
  SparkFun Electronics
  
  This code includes the ddition of fade in and out PWM. Also a stop feature. And the addition of individual functions for motor control 
  
  This was a revision of the example sketch that originated from Pete Dokter's code for Arduino that shows very basically how to control an Ardumoto 
  motor driver shield with a 5V Arduino controller board. http://www.sparkfun.com/datasheets/DevTools/Arduino/Ardumoto_test_3.pde
  
  This also includes parts of the Fading Example,  Created 1 Nov 2008 By David A. Mellis, modified 30 Aug 2011 By Tom Igoe http://arduino.cc/en/Tutorial/Fading
 
*/

int pwm_a = 3;   
int pwm_b = 11;  
int dir_a = 12;  
int dir_b = 13;  
void setup()
{
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
}

void loop()
{  
  stopmove();
  delay(1000);
  backward();    
  delay(1000);
  forward();      
  delay(1000);
  turnleft();
  delay(1000);
  turnright();
  delay(1000);

}


/* Let's take a moment to talk about these functions. The forw and back functions are simply designating the direction the motors will turn once they are fed a PWM signal.
If you only call the forw, or back functions, you will not see the motors turn. On a similar note the fade in and out functions will only change PWM, so you need to consider
the direction you were last set to. In the code above, you might have noticed that I called forw and fade in the same grouping. You will want to call a new direction, and then
declare your pwm fade. There is also a stop function. 
*/


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

