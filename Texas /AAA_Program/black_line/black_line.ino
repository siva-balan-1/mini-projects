int sensor_value= 0;
int k = 0;
int a = 0; int b = 0; int c = 0; int d = 0; int e = 0; int f = 0; int g = 0; int h = 0;
void Forward(int x, int y)
{
  digitalWrite(55, HIGH);
  digitalWrite(54, LOW);
  digitalWrite(71, HIGH);
  digitalWrite(70, LOW);
  analogWrite(31,x);
  analogWrite(32,y);

}
void setup() {
  pinMode(61, OUTPUT);
  Serial.begin(9600); //bps
  pinMode(54, OUTPUT);
  pinMode(70, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(55, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(71, OUTPUT);
 
  }

  void loop() {
 digitalWrite(61,HIGH);
  pinMode(65,OUTPUT);
   pinMode(48,OUTPUT);
  pinMode(64,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(52,OUTPUT);
  pinMode(68,OUTPUT);
  pinMode(53,OUTPUT);
  pinMode(69,OUTPUT);
  digitalWrite(65,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(64,HIGH);
  digitalWrite(47,HIGH);
  digitalWrite(52,HIGH);
  digitalWrite(68,HIGH);
  digitalWrite(53,HIGH);
  digitalWrite(69,HIGH);
  delayMicroseconds(30);
   pinMode(65,INPUT_PULLUP);
   pinMode(48,INPUT_PULLUP);
  pinMode(64,INPUT_PULLUP);
  pinMode(47,INPUT_PULLUP);
  pinMode(52,INPUT_PULLUP);
  pinMode(68,INPUT_PULLUP);
  pinMode(53,INPUT_PULLUP);
  pinMode(69,INPUT_PULLUP);

  for (int k = 0; k < 10000; k++)
  {
    a = digitalRead(65);
    b = digitalRead(48); 
    c = digitalRead(64);
    d = digitalRead(47); 
    e = digitalRead(52); 
    f = digitalRead(68); 
    g = digitalRead(53); 
    h = digitalRead(69);
  }
  Serial.println(h); 
  Serial.println(g);
  Serial.println(f);
  Serial.println(e);
  Serial.println(d);
  Serial.println(c);
  Serial.println(b);
  Serial.println(a);
  int sensorvalue = (h * 128) + (g * 64) + (f * 32) + (e * 16) + (d * 8) + (c * 4) + (b * 2) + (a * 1);
  Serial.println(sensorvalue);
    Serial.println("   ");

    delay(500);
if (sensorvalue <= 7 && sensorvalue > 0)
{
 Serial.println("move right");
  Forward(20,0);
   
}
if (sensorvalue > 25&& sensorvalue<30)
{
 Serial.println("move right ");
  Forward(20,0);
 
} 
if (sensorvalue <= 32 && sensorvalue > 7 && sensorvalue !=28)
{
 Serial.println("move Forward");
  Forward(20,20);
 
} 

 if (sensorvalue>32 && sensorvalue<255)
{
  Serial.println("move left");
  Forward(0,20);
   
}
if (sensorvalue==0 || sensorvalue==255)
{
  Serial.println("stop");
  Forward(0,0);
  
}  

}
