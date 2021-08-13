#include <C:\Users\rinna\Documents\C\ev3dev\EV3Connecter\EV3Connceter-Arduino\src\EV3Connecter.h>
#include <C:\Users\rinna\Documents\C\ev3dev\EV3Connecter\EV3Connceter-Arduino\src\EV3Connecter.cpp>

EV3 ev3;

void setup()
{
    ev3.begin(32);
    ev3.clearSendBuff();
    Serial.begin(9600);
    int a = 1024;
    ev3.sendInt(a);
    uint8_t b = 255;
    ev3.sendByte(b);
    float c = 3.14;
    ev3.sendFloat(c);
    double d = 3.141592654;
    ev3.sendDouble(d);

    char read[32];
    for(int i = 0; i < 32; i++)
    {
      memset(read, '0', 32);
      String buff = String(ev3.readSendBuff(i), HEX);
      sprintf(read, "%2d: 0x%s\n", i, buff.c_str());
      Serial.print(read);
    }
    Serial.println("-------------------------------------");
}

void loop()
{
}
