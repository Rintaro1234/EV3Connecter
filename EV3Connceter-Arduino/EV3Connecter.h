#pragma once
#include "Wire.h"

#defien MyAddress 0x0A

sturct typedef{
	uint8_t address, data, size;
}data_t

class EV3{
private:
    uint8_t funcAdd; // EV3からの実行命令
	uint8_t numFunc = 10;
	uint8_t buffsize = 32; // 受信バッファのサイズ
	uint8_t *receivreBuff; // 受信バッファのポインタ
	data_t *data;
	
	void receiveEvent(int DataNum); // 受信時に呼ばれる
	void requestEvent(); // データ送信要求時に呼ばれる

public:
	bool begin(); // EV3との接続開始
	void attach(uint8_t *data, int size, int address); // EV3からのデータ送信
	uint8_t receiveAdd(); // EV3から送られてきた機能アドレス
	void* receiveArg() { return data; } // データが入っているポインタを返す
};