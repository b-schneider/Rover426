
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
void find()
{
 
  if(analogRead(E) > analogRead(W))
     while(analogRead(N) <= analogRead(W) && analogRead(N) <= analogRead(E) && analogRead(N) <= analogRead(S)/*E and W are not almost the same*/)
      {//rotate right
        
      }
  else
     while(analogRead(N) <= analogRead(W) && analogRead(N) <= analogRead(E) && analogRead(N) <= analogRead(S)/*E and W are not almost the same*/)
      {//rotate left
        
      }

 
}

