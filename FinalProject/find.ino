//needs pins to assign to sensor inputs, named N, S, E , W for north east south west
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
void find()
{
 
  if(digitalRead(N) == HIGH)
    return;
    
  else if(digitalRead(E) == HIGH)
     while(digitalRead(N) == LOW)
      {//rotate right (clockwise)
        
      }
  else
     while(digitalRead(N) == LOW)
      {//rotate left
        
      }

   return;
}

