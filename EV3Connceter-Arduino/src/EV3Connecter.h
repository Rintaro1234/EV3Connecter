#pragma once
#include "Wire.h"

#define MyAddress 0x0A

typedef struct{
	uint8_t address, size;
	uint8_t *data;
}data_t;

class EV3{
private:
    static uint8_t funcAdd; // EV3からの実行命令
	static uint8_t numFunc; // 関数の数
	static uint8_t buffsize; // 受信バッファのサイズ
	static uint8_t *receiveBuff; // 受信バッファのポインタ
	static bool connected; // 繋がっているか
	static data_t *data;
	
	static void receiveEvent(int DataNum); // 受信時に呼ばれる
	static void requestEvent(); // データ送信要求時に呼ばれる

public:
	bool begin(); // EV3との接続開始
	void attach(uint8_t *data, int size, int address); // EV3からのデータ送信
	
	uint8_t receiveAdd() { return funcAdd; }; // EV3から送られてきた機能アドレス
	void* receiveArg() { return data; } // データが入っているポインタを返す
	void setFuncNum(int num) { numFunc = num; } // 関数の数
	void setBuffSize(int num) { buffsize = num; } // 受信バッファのサイズ
};