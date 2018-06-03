#include <SoftwareSerial.h>
SoftwareSerial BTserial(11, 12); // RX | TX
#include <Servo.h>

const int forward = 2; // julto
const int backward = 4; // cerveno
const int left = 6; // zeleno
const int right = 8; // cerno

char in, state_m1 = 's', state_m2 = 'v';

long time;

Servo servo;

int pos = 0;

void setup() 
{

    Serial.begin(9600);

    pinMode(forward, OUTPUT);
    pinMode(backward, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(right, OUTPUT);
 
    BTserial.begin(9600);

    servo.attach(9);
    
//    for (pos = 0; pos <= 180; pos += 1) {
//      servo.write(pos);
//      delay(10);
//    }
//    for (pos = 90; pos >= 0; pos -= 1) {
//      servo.write(pos);
//      delay(10);
//    }
//  
}
 
void loop()
{
//        if (BTserial.available() > 0)
//        {

            Serial.print("Time: ");
            time = millis();
            Serial.print(time); 
            Serial.print(" ");
            
            in = BTserial.read();
            
            Serial.println(in);

            if(in == 'f')
            {
              digitalWrite(backward, LOW);
              digitalWrite(forward, HIGH);
            }

            if(in == 'b')
            {
              digitalWrite(forward, LOW);
              digitalWrite(backward, HIGH);

            Serial.print("Timeeeeeeeees: ");
            time = millis();
            Serial.println(time);
              
            }

            if(in == 's')
            {
              digitalWrite(backward, LOW);
              digitalWrite(forward, LOW);
            }



            if(in == 'l')
            {
              digitalWrite(right, LOW);
              digitalWrite(left, HIGH);
            }

            if(in == 'r')
            {
              digitalWrite(left, LOW);
              digitalWrite(right, HIGH);
            }

            if(in == 'v')
            {
              digitalWrite(left, LOW);
              digitalWrite(right, LOW);
            }
//         }
}
