void setup() {
  setupRemoteControl();
  setupFollowWall();
  setupFindBeacon();
}

void loop() {
  //suggestion: we should make a void loop that runs once, calling a function
  //for each task it performs and then terminating the program.  Example:
  
  remoteControl();  //function will do everything for remote control and return when remote control portion is over
  followWall();     //does all wall following, returns when finished
  findBeacon();     //you get the idea
  
  while(1);         //delays forever, the program is over
}


void setupRemoteControl(){
  //these functions handle the setup of variables, pins, etc, that each corresponding function will use
}

void remoteControl(){
  //each function does its task, but is able to call some functions usefell to all
  //parts of the code, such as something to make the motors move (such as below)
  forward(255);
}


void setupFollowWall(){
  
}

void followWall(){
  
}


void setupFindBeacon(){
  
}

void findBeacon(){
  
}

