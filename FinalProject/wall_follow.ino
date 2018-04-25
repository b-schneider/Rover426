



void setupFollowWall()
{
  //setup analog pin for IR sensor reading the wall;
  pinMode(A0, OUTPUT); 
}

void followWall() {
  int state = 1; //something to make sure we should be in this loop
  int distance = analogRead(A0); //variable to store reading from IR sensor
  static int vel = 255; //variable to store rate of motion, NEEDS TO BE INITALIZED BEFORE USE
  
  while(state == 1)
  {
    distance = analogRead(A0); //read a variable into distance
    map(distance, 2.22, 0.37, 10, 80); //map it to an actual distance

    
    if(distance > 22)
    {
      right(vel); //rotates towards wall
      delay(100); 
      forward(vel);
    }
    else if(distance < 18)
    {
      left(vel); //rotates away from wall
      delay(100); 
      forward(vel);
    }

    //some if statement to end this loop
    //state = 2;
    
  }
  
  return;
}
