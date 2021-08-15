#include "EV3Connecter.h"

int Arduino::begin(tSensors port)
{
    char WBuf[3] = {2, slaveAddress << 1, requestBuffSize};
    char RBuf[1];
    sendI2CMsg(port, WBuf, 1);
    checkI2C(port);
    readI2CReply(port, RBuf, 1)
    checkI2C(port);
    buffSize = RBuf[0];

    receiveBuff = (char*)malloc(sizeof(char) * buffSize);
    sendBuff = (char*)malloc(sizeof(char) * buffSize);

    return buffSize;
}

int Arduino::requestData(bool isSync)
{
    return 0;
}

int Arduino::sendData()
{
    return 0;
}
