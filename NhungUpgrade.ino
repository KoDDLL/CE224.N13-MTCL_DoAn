const int buzzer = 12;
const int flamePin = 11;
const int SwPin = 3;
int Flame = HIGH;
int greenled = 4;
int redled = 5;
int blueled = 6;
int smokeA0 = A5;
int sensorThres = 400;
int Gas = LOW;
int Fire = LOW;

void setup() {
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(flamePin, INPUT);
  pinMode(SwPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(SwPin) == HIGH)
  {
    digitalWrite(greenled, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(blueled, LOW);
  }
  else
  {
    digitalWrite(greenled, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(blueled, LOW);
  }
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    Gas = HIGH;
  }
  else
  {
    Gas = LOW;
  }
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    Fire = HIGH;
  }
  else
  {
    Fire = LOW;
  }
  if (Gas == HIGH && Fire == HIGH)
  {
    
    digitalWrite(redled, HIGH);
    digitalWrite(greenled,HIGH);
    digitalWrite(blueled, LOW);
    delay(500);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    if (Gas == HIGH && Fire == LOW)
    {
      digitalWrite(greenled, HIGH);
      digitalWrite(redled, LOW);
      digitalWrite(blueled, LOW);
      for(int Alert = 0; Alert <4; Alert++)
        {
          delay(1000);
          if(Alert == 3)
          {
            digitalWrite(buzzer, HIGH);
            digitalWrite(redled, HIGH);
            digitalWrite(blueled,LOW);
          }
        }
    }
    else
    {
      if (Gas == LOW && Fire == HIGH)
      {
       digitalWrite(greenled, LOW);
       digitalWrite(redled, HIGH);
       digitalWrite(blueled, LOW);
       for(int Alert = 0; Alert <5; Alert++)
        {
          delay(1000);
          if(Alert == 4)
          {
            digitalWrite(buzzer, HIGH);
            digitalWrite(redled, HIGH);
            digitalWrite(blueled,LOW);
          }
        }
      }
      else
      {
        digitalWrite(greenled, LOW);
        digitalWrite(buzzer, LOW);
        digitalWrite(redled, LOW);
        digitalWrite(blueled, HIGH);
      }
    }
  }
}
