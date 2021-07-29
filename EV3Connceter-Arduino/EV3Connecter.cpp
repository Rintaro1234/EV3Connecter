#include "EV3Connecter.h"

// EV3と接続する。
void EV3::initI2CPort()
{
    Wire.begin(0x0A);

    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestRvent);

    memset(func, NULL, sizeof(void*) * 256);
    pfunc[0] = *check();
}

// 接続を確認する
void EV3::check()
{
    // NULL
}

// 送信するアイテム
void EV3::sendItems(uint8_t *d, uint8_t num)
{
    pdata = d;
    datas = num;
}

// 関数を割り当てる
int16_t EV3::setFunc(void *p, uint8_t address)
{
    if(address != 0x00)
    {
        func[address] = p;
        return 0;
    }
    return -1;
}

// EV3から受信が来た時
void EV3::receiveEvent()
{
    getAddress = Wire.read();
    if(func[getAddress] != NULL)
    {
        func[getAddress]();
        Wire.write(0)
    }else{
        Wire.write(-1);
    }
}

// EV3から送信命令
void EV3::requestEvent()
{
    for(int i = 0; i < datas) Wire.write(pdata[i]);
}