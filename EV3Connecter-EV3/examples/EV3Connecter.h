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

char receiveBuff[32];
char sendBuff[32];
int receivePoint;
int sendPoint;

void checkI2C(tSensors port)
{
	while(nI2CStatus[port]!=0)
  {}
}

int begin(tSensors port)
{
    char WBuf[3] = {2, slaveAddress << 1, requestBuffSize};
    char RBuf[2];
    sendI2CMsg(port, WBuf, 1);
    checkI2C(port);
    readI2CReply(port, RBuf, 1)
    IntBit buffSize;
    buffSize.bits[0] = RBuf[0];
    buffSize.bits[1] = RBuf[1];
    return buffSize.val;
}

int requestData(bool isSync)
{
    return 0;
}

int sendData()
{
    return 0;
}
