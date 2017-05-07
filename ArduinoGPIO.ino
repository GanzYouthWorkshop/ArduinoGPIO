void setup()
{
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  Serial.begin(9600);
}

void loop()
{
  char level;
  char port;
   
  while(Serial.available() > 1)
  {
    Serial.println(Serial.available());
    level = Serial.read();
    if(level == 'H')
    {
      level = 1;
    }
    else if(level == 'L')
    {
      level = 0;
    }
    else
    {
      level = 2;
    } 
    port = Serial.read();
    
    if(level < 2)
    {
      Serial.print(port - 48); Serial.println(level ? ": HIGH" : ": LOW");
      digitalWrite(port - 48, level ? HIGH : LOW);
      level = 2;
    }
  }
}
