//set pins to sensor outputs, named N, S, E , W for north east south west
int N, E, S, W;


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

