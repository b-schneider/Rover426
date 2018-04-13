void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int inputVal = analogRead(A0);

  if(inputVal < 204)
     avoid(0);
  if(inputVal >= 204 && inputVal < 409)
     avoid(1);
  if(inputVal >= 409 && inputVal < 614)
     avoid(2);
  if(inputVal >= 614 && inputVal < 819)
     avoid(3);
  if(inputVal >= 819)
     avoid(4);

Serial.println(inputVal);
  
}
void avoid(int sector)
{
  if(sector == 0)
    {digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    }
  else if(sector == 1)
    {digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
    }

  else if(sector == 2)
    {digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    }

  else if(sector == 3)
    {digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    }

  else if(sector == 4)
    {digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    }

}

