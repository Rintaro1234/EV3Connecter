#pragma once
#define ArduinoAddress 0x0A

typedef char uint8_t;

class Arduino
{
private:
    uint8_t *receiveBuff; // 受信バッファ
    int BuffSize = 32; // 受信バッファサイズ
public:
    bool begin();
    bool send(uint8_t *data, int size);
    uint8_t *read(){return receiveBuff;};
    void setBuffSize(int num){BuffSize = num;}
};