#include "EV3Connecter.h"

void EV3::receiveEvent(int DataNum)
{
	funcAdd = Wire.read();
	DataNum--;
	for(int i = 0; i< DataNum; i++)
	{
		receiveBuff[i] = Wire.read();
	}
}
void EV3::requestEvent()
{
	for(int i = 0; i < numFunc; i++)
	{
		if(data[i].address == funcAdd)
		{
			data_t d = data[i];
			for(int j = 0; j < d.size; j++)
			{
				Wire.write(d.data[j]);
			}
		}
	}
}

void EV3::begin()
{
	Wire.onReceive(receiveEvent); // 自身のアドレスが呼ばれた時に実行する関数
	Wire.onRequest(requestEvent); // データの送信を要求が来た時に実行する関数
}
