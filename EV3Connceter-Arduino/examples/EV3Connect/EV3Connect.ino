#include <EV3Connecter.h>

EV3 ev3;

void setup()
{
    ev3.begin(32);
}

void loop()
{
    ev3.clearSendBuff();
    int a = 1024;
    ev3.sentInt(a);
    uint8_t b = 255;
    ev3.sentByte(b);
    float c = 3.14;
    ev3.sentFloat(c);
    double d = 3.141592654;
    ev3.sentDouble(d);
}
