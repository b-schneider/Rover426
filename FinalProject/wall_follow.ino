int wallFollowPin = A0;

void setupFollowWall(){
  
}



void followWall() {
  int state = 1; //something to make sure we should be in this loop
  static double distance=0; //variable to store reading from IR sensor
  static int vel = 128; //variable to store rate of motion, NEEDS TO BE INITALIZED BEFORE USE

  
  
  while(state == 1)
  {
    distance = distance*.8+.2*getDistance(wallFollowPin);

    Serial.println(distance);
    
//    if(distance > 22)
//    {
//      right(vel); //rotates towards wall
//      delay(100); 
//      forward(vel);
//    }
//    else if(distance < 18)
//    {
//      left(vel); //rotates away from wall
//      delay(100); 
//      forward(vel);
//    }
//
//    //some if statement to end this loop
//    if (0)
//    state = 2;
    
  }
  
  return;
}

double getDistance(int pinNum){
  //21.347 = gain
  //.1194 = offset
  return 21.347/(analogRead(pinNum)*5/1024.-.1194);
}

