void setup() {
  Serial.begin(9600);  //not used on mobile rover, but could be used for debuging

  setUpRoverMotionRotation();
//  setupRemoteControl();
  setupFollowWall();
//  setupFindBeacon();
  setupVictoryMusic();
  setupRemoteControl();

}

void loop() {
  //suggestion: we should make a void loop that runs once, calling a function
  //for each task it performs and then terminating the program.  Example:
  
//  remoteControl();  //function will do everything for remote control and return when remote control portion is over
//  followWall();     //does all wall following, returns when finished
//  findBeacon();     //you get the idea
//
//  forward(255);
//  delay(1000);
//  backward(255);
//  delay(1000);
//  left(255);
//  delay(1000);
//  right(255);
//  delay(1000);
//  brake();

  remoteControl();

  playVictoryMusic();
  
  while(1);         //delays forever, the program is over
}




