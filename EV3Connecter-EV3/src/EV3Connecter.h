#define slaveAddress 0x0A
#define requestBuffSize 0x00

union ByteBit
{
    byte val;
    byte bits[1];
};
union IntBit
{
    int val;
    byte bits[2];
};
union FloatBit
{
    float val;
    byte bits[4];
};

class Arduino
{
private:
    static char *receiveBuff;
    static char *sendBuff;
    static int receivePoint;
    static int sendPoint;
    static int buffSize;
public:
    int begin(tSensors port);
    int requestData(bool isSync);
    int sendData();
};
