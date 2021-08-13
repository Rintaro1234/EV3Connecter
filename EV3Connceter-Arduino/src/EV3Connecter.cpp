#include "EV3Connecter.h"

uint8_t* EV3::receiveBuff;
uint8_t* EV3::sendBuff;
int EV3::receivePoint;
int EV3::sendPoint;
int EV3::availableBytes;
int EV3::buffSize;

/*---------バックグラウンド処理---------*/
void EV3::receiveEvent(int DataNum)
{
    availableBytes = DataNum;
    for(int i= 0; i < DataNum; i++) receiveBuff[i] = Wire.read();
    Serial.println("Called");
}

void EV3::requestEvent()
{
    Wire.write(sendBuff, buffSize);
    Serial.println("Requested");
}

/*---------機能---------*/

int EV3::begin(int size)
{
    int isConnected = -1;
    // 初期化
    buffSize = size;
    receiveBuff = (uint8_t*)malloc(sizeof(uint8_t) * buffSize); // 受信バッファ
    sendBuff    = (uint8_t*)malloc(sizeof(uint8_t) * buffSize); // 送信バッファ
    // ポート開放
    Wire.begin(myAddress);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    this->clearSendBuff();
    this->clearReceiveBuff();

    return isConnected;
}

/*---------読み込み---------*/

int EV3::readInt()
{
    int buff;
    buff = *(int *)receiveBuff[receivePoint];
    receivePoint += sizeof(int);
    return buff;
}

float EV3::readFloat()
{
    float buff;
    buff = *(float *)receiveBuff[receivePoint];
    receivePoint += sizeof(float);
    return buff;
}

double EV3::readDouble()
{
    double buff;
    buff = *(double *)receiveBuff[receivePoint];
    receivePoint += sizeof(double);
    return buff;
}

uint8_t EV3::readByte()
{
    uint8_t buff;
    buff = *(uint8_t *)receiveBuff[receivePoint];
    receivePoint += sizeof(uint8_t);
    return buff;
}

uint8_t EV3::readReceiveBuff(uint8_t address)
{
    return receiveBuff[address];
}

void EV3::clearReceiveBuff()
{
    receivePoint = 1;
    availableBytes = 0;
    memset(receiveBuff, 0, sizeof(uint8_t) * buffSize);
}

/*---------書き込み---------*/

int EV3::sendInt(int val)
{
    int isSuccess = -1;
    *(int *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(int);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

int EV3::sendFloat(float val)
{
    int isSuccess = -1;
    *(float *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(float);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

int EV3::sendDouble(double val)
{
    double isSuccess = -1;
    *(double *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(double);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

int EV3::sendByte(uint8_t val)
{
    int isSuccess = -1;
    *(uint8_t *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(uint8_t);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

uint8_t EV3::readSendBuff(uint8_t address)
{
    return sendBuff[address];
}

void EV3::clearSendBuff()
{
    sendPoint = 0;
    memset(sendBuff, 0, sizeof(uint8_t) * buffSize);
}
