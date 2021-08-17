#pragma once
#include "Wire.h"
#include <Arduino.h>

#define myAddress 0x0A

class EV3
{
private:
    static uint8_t *receiveBuff;
    static uint8_t *sendBuff;
    static int receivePoint;
    static int sendPoint;
    static int buffSize;
    static int availableBytes;
    static void receiveEvent(int DataNum);
    static void requestEvent();
public:
    int begin(int size);
    // 読み込み
    int readInt();
    float readFloat();
    uint8_t readByte();
    uint8_t readReceiveBuff(uint8_t address) {return receiveBuff[address]; };
    void clearReceiveBuff();
    void resetReceivePointer(){ receivePoint = 0;}
    // 送信
    int setInt(int val);
    int setFloat(float val);
    int setByte(uint8_t val);
    uint8_t readSendBuff(uint8_t address){ return sendBuff[address]; }
    void endTransmission(){ sendBuff[0] = 0x01; }
    void beginTransmission(){clearSendBuff();}
    void clearSendBuff();

    // デストラクタ
    ~EV3()
    {
        free(receiveBuff);
        free(sendBuff);
    }
};