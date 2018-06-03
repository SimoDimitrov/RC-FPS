#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 2);

long state_x, state_y;
int b1, b2;
 
void setup() 
{
    Serial.begin(9600);
    BTserial.begin(9600);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
}
 
void loop()
{


    state_x = analogRead(A0);
    state_y = analogRead(A1);
    b1 = digitalRead(8);
    b2 = digitalRead(9);

     if(state_x < 400){
        Serial.println("f");
        BTserial.write("f");
      }else if(state_x > 600){
        Serial.println("b");
        BTserial.write("b");
      }else BTserial.write("s");


      if(state_y < 400){
        Serial.println("r");
        BTserial.write("r");
      }else if(state_y > 600){
        Serial.println("l");
        BTserial.write("l");
      }else BTserial.write("v");

      Serial.println(b1);
      Serial.println(b2);
}
