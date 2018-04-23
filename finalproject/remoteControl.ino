//if you do not have IRLibAll.h, just comment this whole file out to compile
#include "IRLibAll.h" //includes a lot of things we do not need.  Flash useage could be reduced by changing

#define BTN1 0x20FF28D7
#define BTN2 0x20FF38C7
#define BTN3 0x20FF40BF
#define BTN4 0x20FF20DF
#define BTN5 0x20FFA05F
#define BTN6 0x20FF609F
#define BTN7 0x20FF10EF
#define BTN8 0x20FF08F7
#define BTN9 0x20FF8877
#define REPT 0xFFFFFFFF

#define IRreceiverPin 2 //can be changed to any pin (do not need PWM or analog)

#define BTNdelay 150 //number of microseconds to wait and see if button is held down. 150 works well by experimentation, may be able to go lower for more prescice control

IRrecvPCI myReceiver(IRreceiverPin);
IRdecodeNEC myDecoder;

void setupRemoteControl(){
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println("ending remoteControl setup");
}

void remoteControl(){
  backward(255);
  unsigned long depressedBTN = 0;
  unsigned long lastBTNtime = 0;
  while(depressedBTN != BTN1){  //loop until power button (BTN1) is pressed
      if (myReceiver.getResults()) {  //if the receiver has read something in
      myDecoder.decode();           //fill myDecoder.value with code of pressed button
      depressedBTN = myDecoder.value;
      lastBTNtime = millis();
      switch(depressedBTN){
        //if button 1 is pressed, terminate remote control mode
        case BTN1:
        Serial.println("POWER PRESSED, ENDING REMOTE CONTROL");
        break;
        
        //if button 2 is pressed, do nothing
        case BTN2:
        Serial.println('2');
        break;
        
        //if button 3 is pressed, move forward
        case BTN3:
        forward(255);   //full speed forward (I think)
        Serial.println("FORWARD PRESSED, GOING");
        break;

        //if button 4 is pressed, rotate left
        case BTN4:
        left(255);
        Serial.println("LEFT PRESSED, SPNNING");
        break;

        //if button 5 is pressed, do nothing
        case BTN5:
        Serial.println('5');
        break;
        
        //if button 6 is pressed, rotate right
        case BTN6:
        right(255);
        Serial.println("RIGHT PRESSED, SPINNING");
        break;
        
        //if button 7 is pressed, move backward
        case BTN7:
        backward(255);
        Serial.println("BACKWARD PRESSED, GOING");
        break;
        
        //if button 8 is pressed, do nothing
        case BTN8:
        Serial.println('8');
        break;
        
        //if button 9 is pressed, do nothing
        case BTN9:
        Serial.println('9');
        break;
        
        //if button is heald down, do not change anything
        case REPT:
        Serial.println("Repeat");
        break;
        
        default://if any other codes are sent, just stop
        Serial.print("UNRECOGNIVED CODE(");
        Serial.print(depressedBTN);
        Serial.println(")\n");
        //brake();
        depressedBTN = 0;           //do I need this?
      }
      myReceiver.enableIRIn();      //Restart receiver to be able to receive next code
    }else{      //if no results are ready in the reciever, stop (this is probably the wrong way to do this)
      if(millis()-BTNdelay > lastBTNtime){
        brake();  //maybe instead check if no button has been pressed for half a second (or some time interval)
        Serial.println("TIMEOUT");
      }
      depressedBTN = 0;
    }
  }
}
