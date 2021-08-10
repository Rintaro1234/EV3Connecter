#include "EV3Connecter.h"

uint8_t EV3::funcAdd; // EV3からの実行命令
uint8_t EV3::numFunc = 10; // 関数の数
uint8_t EV3::buffsize = 32; // 受信バッファのサイズ
uint8_t *EV3::receiveBuff; // 受信バッファのポインタ
bool EV3::connected = false;
data_t *EV3::data;

// 自身のアドレスが呼ばれた時に実行する関数
void EV3::receiveEvent(int DataNum)
{
	connected = true;
	funcAdd = Wire.read();
	DataNum--;
	for(int i = 0; i< DataNum; i++)
	{
		receiveBuff[i] = Wire.read();
	}
}

// データの送信を要求が来た時に実行する関数
void EV3::requestEvent()
{
	data_t d;
	for(int i = 0; i < numFunc; i++)
	{
		if(data[i].address == funcAdd)
		{
			d = data[i];
			break;
		}
	}
	for(int i = 0; i < d.size; i++)
	{
		Wire.write(d.data[i]);
	}
}

bool EV3::begin()
{
	Wire.begin(MyAddress);
	// メモリ確保
	receiveBuff = (uint8_t *)malloc(sizeof(uint8_t) * buffsize);
	data = (data_t *)malloc(sizeof(data_t) * numFunc);

	Wire.onReceive(receiveEvent); // 自身のアドレスが呼ばれた時に実行する関数
	Wire.onRequest(requestEvent); // データの送信を要求が来た時に実行する関数

	// 繋がったかチェック
	while(!connected){delay(10);}
	return connected;
}
