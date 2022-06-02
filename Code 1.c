#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define delay 500

// LED 1
long led1On = 0;
byte led1State = HIGH;

// LED 2
long led2On = 0;
byte led2State = HIGH;

// LED 3
long led3On = 0;
long led3Off = 0;
byte led3State = HIGH;

// LED 4
long led4On = 0;
long led4Off = 0;
byte led4State = HIGH;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

void loop()
{
  long timeNow = millis();

  // LED 1 on off 1 sec
  if (timeNow - led1On > delay * 2)
  {
    led1On += delay * 2;
    if (led1State == HIGH)
    {
      led1State = LOW;
    }
    else
    {
      led1State = HIGH;
    }
    digitalWrite(led1, led1State);
  }

  // LED 2 on off 2 sec
  if (timeNow - led2On > delay * 4)
  {
    led2On += delay * 4;
    if (led2State == HIGH)
    {
      led2State = LOW;
    }
    else
    {
      led2State = HIGH;
    }
    digitalWrite(led2, led2State);
  }

  // LED 3 on 0.5sec off 1 sec
  if (timeNow - led3On > delay && led3State == HIGH)
  {
    led3On += delay;
    led3State = LOW;
    digitalWrite(led3, led3State);
  }
  else if (timeNow - led3Off > delay * 2 && led3State == LOW)
  {
    led3Off += delay * 2;
    led3State = HIGH;
    digitalWrite(led3, led3State);
  }

  // LED 4 on 1.5sec off 2 sec
  if (timeNow - led4On > delay*3 && led4State == HIGH)
  {
    led4On += delay*3;
    led4State = LOW;
    digitalWrite(led4, led4State);
  }
  else if (timeNow - led4Off > delay * 4 && led4State == LOW)
  {
    led4Off += delay * 4;
    led4State = HIGH;
    digitalWrite(led4, led4State);
  }
}
