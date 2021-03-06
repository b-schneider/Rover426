//set enable, motor controls, and potentiometer pins
//Motor A is on the left, motor B is on the right
const int ENA = 10;
const int ENB = 9;
const int MCA1 = 6;
const int MCA2 = 5;
const int MCB1 = 4;
const int MCB2 = 7;

void setUpRoverMotionRotation(){


  //setup for main
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MCA1, OUTPUT);
  pinMode(MCA2, OUTPUT);
  pinMode(MCB1, OUTPUT);
  pinMode(MCB2, OUTPUT);

  brake();
  
}
//const int POT = 0;





 // brake(); //start running the code with the motor stopped

//loop to test code
////initialize variables used
//int val = 0;
//int velocity = 0;
//void loop() {
//   val = analogRead(POT); //get value from potentiometer
//
//  if(val > 562) //if pot is high, motor goes forward
//  {
//    velocity = map(val, 563, 1023, 0, 255); //convert pot signal to PWM signal
//    forward(velocity); //send velocity to H - bridge 
//  }
//
//  else if(val < 462) //if pot is low, motor goes backward
//  { 
//    velocity = map(val, 461, 0, 0, 255);  //convert pot signal to PWM signal
//    backward(velocity); //send velocity to H - bridge
//  }
//
//  else //if pot is in the middle, stop motor
//  {
//    brake(); //stop the motor
//  }
//}

//moves motor forward
void forward(int rate)
{
    digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, HIGH); //sets motor controls to correct direction
    digitalWrite(MCA2, LOW);
    digitalWrite(MCB1, HIGH); //sets motor controls to correct direction
    digitalWrite(MCB2, LOW);
    analogWrite(ENA, rate); //writes velocity to enable pin
    analogWrite(ENB, rate); //writes velocity to enable pin
}

//moves motor backwards 
void backward(int rate)
{
    digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, LOW); //sets motor controls to correct direction
    digitalWrite(MCA2, HIGH);
    digitalWrite(MCB1, LOW); //sets motor controls to correct direction
    digitalWrite(MCB2, HIGH);
    analogWrite(ENA, rate); //writes velocity to enable pin
    analogWrite(ENB, rate);
}

void left(int rate) //rotates rover to the right
{
    digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, HIGH); //sets motor A forward
    digitalWrite(MCA2, LOW);
    digitalWrite(MCB1, LOW); //sets motor B backward
    digitalWrite(MCB2, HIGH);
    analogWrite(ENA, rate); //writes velocity to enable pins
    analogWrite(ENB, rate);
}

void right(int rate)
{
    digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, LOW); //sets motor A backward
    digitalWrite(MCA2, HIGH);
    digitalWrite(MCB1, HIGH); //sets motor B forward
    digitalWrite(MCB2, LOW);
    analogWrite(ENA, rate); //writes velocity to enable pins
    analogWrite(ENB, rate);
}

//stops motor by setting motor controls to low
void brake()
{
    digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, LOW); 
    digitalWrite(MCA2, LOW);
    digitalWrite(MCB1, LOW); 
    digitalWrite(MCB2, LOW);
    digitalWrite(ENA, HIGH);
    digitalWrite(ENB, HIGH);
}

//turns the rover to the right while moving forward
void turnRight(int rate)
{
  digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, HIGH); //sets motor A & B forward
    digitalWrite(MCA2, LOW);
    digitalWrite(MCB1, HIGH); 
    digitalWrite(MCB2, LOW);
    analogWrite(ENA,rate/5); //writes velocity to enable pins
    analogWrite(ENB, rate); //sets motor A slower than B
}

//turns the rover to the left while moving forward
void turnLeft(int rate)
 {
    digitalWrite(ENA, LOW); //stops old enable pin signal
    digitalWrite(ENB, LOW); //stops old enable pin signal
    digitalWrite(MCA1, HIGH); //sets motor A & B forward 
    digitalWrite(MCA2, LOW);
    digitalWrite(MCB1, HIGH);
    digitalWrite(MCB2, LOW);
    analogWrite(ENA, rate); //writes velocity to enable pinS
    analogWrite(ENB, rate/5); //sets motor B slower than A
  }

//set motor rate, from -1 (full backwards) to 1 (full forwards)
void setRightSpeed(double rate){
  digitalWrite(MCA1, rate>0? HIGH:LOW);
  digitalWrite(MCA2, rate>0? LOW:HIGH);
  analogWrite(ENA, 255*rate);
}

void setLeftSpeed(double rate){
  digitalWrite(MCB1, rate>0? HIGH:LOW);
  digitalWrite(MCB2, rate>0? LOW:HIGH);
  analogWrite(ENB, 255*rate);
}
  
/*Notes on the turning:
 * the faster motor pulls the slower motor closer to its speed
 * Because of that, the turn radius is very wide
 * this gets more pronounced at lower speeds
 */

