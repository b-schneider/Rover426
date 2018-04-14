





void followWall() {
  int state = 1; //something to make sure we should be in this loop
  static int distance; //variable to store reading from IR sensor
  static int vel; //variable to store rate of motion, NEEDS TO BE INITALIZED BEFORE USE
  while(state == 1)
  {
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
    state = 2;
    
  }
  
  return;
}
