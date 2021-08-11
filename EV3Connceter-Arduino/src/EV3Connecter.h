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
    int buffSize = 32;
    static int availableBytes;
    static void receiveEvent(int DataNum);
    static void requestEvent();
public:
    int begin(int size);
    // 読み込み
    int readInt();
    float readFloat();
    double readDouble();
    uint8_t readByte();
    void clearReceiveBuff();
    int available(){ return availableBytes - receivePoint;};
    // 送信
    int sentInt(int val);
    int sentFloat(float val);
    int sentDouble(double val);
    int sentByte(uint8_t val);
    void clearSendBuff();

    // デストラクタ
    ~EV3()
    {
        free(receiveBuff);
        free(sendBuff);
    }
};