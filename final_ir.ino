

int sensorpin = 0;                 
int val = 0,i,v,x;                 
const int buzzer = 9; //buzzer to arduino pin 9

void setup()
{
  Serial.begin(9600);               
   pinMode(buzzer, OUTPUT); 
}
 
void loop()
{
  val = digitalRead(sensorpin);       
  Serial.println(val);            
  x=0;
  if(val==0)
  for(i=0;i<5;i++)
  {
    v = digitalRead(sensorpin); 
    Serial.println(v);    
      if(v==0)
      x++;
      delay(500);
  }
  if(x==5)
  {
  Serial.println("eye closed wake up!!!");
  for(i=0;i<10;i++)
  {tone(buzzer, 500); 
  delay(200);        
  noTone(buzzer);    
  delay(200);        
  }
  }
  delay(500);                    
}
