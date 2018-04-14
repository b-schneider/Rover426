//void setup() {
//  pinMode(9, OUTPUT);
//  pinMode(10, OUTPUT);
//  pinMode(11, OUTPUT);
//  pinMode(12, OUTPUT);
//  pinMode(13, OUTPUT);
//  Serial.begin(9600);
//}
//just to test if it switches using a pot
//void loop() {
//  int inputVal = analogRead(A0);
//
//  if(inputVal < 204)
//     avoid(0);
//  if(inputVal >= 204 && inputVal < 409)
//     avoid(1);
//  if(inputVal >= 409 && inputVal < 614)
//     avoid(2);
//  if(inputVal >= 614 && inputVal < 819)
//     avoid(3);
//  if(inputVal >= 819)
//     avoid(4);
//
//Serial.println(inputVal);
//  
//}
void avoid(int, int);
//sectors go from left to right. So 0 is far left, 4 is far right

void avoid(int sector, int rate)
{
  if(sector == 0)
    {//do nothing? figured I'd have it in here
    }
  else if(sector == 1) //if something is too close front left
    {right(rate); 
    delay(100);
    forward(rate);
    }

  else if(sector == 2) //if something is too close in front
    {right(rate);
    delay(100);
    forward(rate);
    }

  else if(sector == 3) //if somethingis too close front right
    {
      //rotate left, move forward
      left(rate);
      delay(100);
      forward(rate);
    }

  else if(sector == 4)
    {//do nothing? figured I'd have it in here
    }

}

