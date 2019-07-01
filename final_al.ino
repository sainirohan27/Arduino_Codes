  /* MQ-3 Alcohol Sensor Circuit with Arduino */

const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledpinred=13;//the anode of the LED connects to digital pin D13 of the arduino
const int ledpingreen=12;
const int led=10;

int limit;
int value;

void setup() {
Serial.begin(115200);//sets the baud rate
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledpinred, OUTPUT);//sets the pin as an output of the arduino
pinMode(ledpingreen, OUTPUT);
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
limit= digitalRead(DOUTpin);//reads the digital value from the alcohol sensor's DOUT pin
Serial.print("Alcohol value: ");
Serial.println(value);//prints the alcohol value
Serial.print("Limit: ");
Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(100);
if (value>600)
limit=1;
if (limit == HIGH){
digitalWrite(ledpinred, HIGH);//if limit has been reached, LED turns on as status indicator
}
else{
digitalWrite(ledpingreen, HIGH);//if threshold not reached, LED remains off
delay(1000);
digitalWrite(led, HIGH);
}
}
