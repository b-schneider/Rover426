void setup() {
  Serial.begin(9600);  //not used on mobile rover, but could be used for debuging
  
  setupRemoteControl();
  setupFollowWall();
  setupFindBeacon();
  setupVictoryMusic();

}

void loop() {
  //suggestion: we should make a void loop that runs once, calling a function
  //for each task it performs and then terminating the program.  Example:
  
  remoteControl();  //function will do everything for remote control and return when remote control portion is over
  followWall();     //does all wall following, returns when finished
  findBeacon();     //you get the idea

  playVictoryMusic();
  
  while(1);         //delays forever, the program is over
}


void setupFollowWall(){
  
}



void setupFindBeacon(){
  
}

void findBeacon(){
  
}

