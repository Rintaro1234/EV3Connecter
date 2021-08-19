#include <EV3Connecter.h>

EV3 ev3;

void setup()
{
    Serial.begin(9600);
    ev3.begin(32);
    pinMode(13, OUTPUT);
}

void loop()
{
  static int a = 0;
  ev3.beginTransmission();
  ev3.setInt(a);
  ev3.endTransmission();
  a++;

  ev3.resetReceivePointer();
  byte b = ev3.readByte();

  switch(b){
    case 0x10:
      digitalWrite(13, LOW);
    break;
    case 0x11:
      digitalWrite(13, HIGH);
    break;
    default:
    break;
  }

  Serial.println(b);

  delay(500);
}
