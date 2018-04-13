

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  static int state = 0;  //detects what part of course rover is on
  static int distance; //variable to store reading from IR sensor
  static int vel; //variable to store rate of motion
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
  }

}
