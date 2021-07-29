#pragma once
#include "Wire.h"

class EV3{
private:
    void *pfunc[256];
    uint8_t getAddress;
    uint8_t datas;
    uint8_t *pdata;

    void receiveEvent();
    void requestEvent();
    void check();
public:
    void initI2CPort();
    void sendItems(uint8_t *d, uint8_t num);
    int setFunc(void *p, uint8_t address);
};