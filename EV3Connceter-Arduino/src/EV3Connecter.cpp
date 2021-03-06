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
    receivePoint = 0;
    availableBytes = DataNum;
    int i = 0;
    for(int i = 0; i < 32; i++) {receiveBuff[i] = Wire.read();}
    Serial.print(DataNum);
    Serial.println("CALLHERE");
    while(Wire.available()) Wire.read();
    uint8_t isFinish = 0x01;
    Wire.write(&isFinish, 1);
}

void EV3::requestEvent()
{
    
    if(receiveBuff[0] == 0x00)
    {
        Wire.write((uint8_t*)&buffSize, sizeof(int));
    }else{
        Wire.write(sendBuff, buffSize);
    }
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
    buff = *(int *)&receiveBuff[receivePoint];
    receivePoint += sizeof(int);
    return buff;
}

float EV3::readFloat()
{
    float buff;
    buff = *(float *)&receiveBuff[receivePoint];
    receivePoint += sizeof(float);
    return buff;
}

uint8_t EV3::readByte()
{
    uint8_t buff;
    buff = *(uint8_t *)&receiveBuff[receivePoint];
    receivePoint += sizeof(uint8_t);
    return buff;
}

void EV3::clearReceiveBuff()
{
    receivePoint = 0;
    availableBytes = 0;
    memset(receiveBuff, 0, sizeof(uint8_t) * buffSize);
}

/*---------書き込み---------*/

int EV3::setInt(int val)
{
    int isSuccess = -1;
    *(int *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(int);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

int EV3::setFloat(float val)
{
    int isSuccess = -1;
    *(float *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(float);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

int EV3::setByte(uint8_t val)
{
    int isSuccess = -1;
    *(uint8_t *)&sendBuff[sendPoint] = val;
    sendPoint += sizeof(uint8_t);
    if(sendPoint <= buffSize) isSuccess = 1;
    return isSuccess;
}

void EV3::clearSendBuff()
{
    sendPoint = 1;
    memset(sendBuff, 0, sizeof(uint8_t) * buffSize);
    sendBuff[0] = 0x00;
}
