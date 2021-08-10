EV3-Arduino互換機との通信を簡単にするライブラリ
Arduinoのアドレスは0x0Aとして扱う

機能(基礎)
class Arduino 機能が入ったクラス

bool Arduino::begin() // Arduinoとの通信を開始する。返り値trueで成功
void Arduino::send(uint8_t *data, int size) // *dataからsize(byte)分送信
uint8_t Arduino::read() // 受信バッファのポインタを返す

機能(発展)
void Arduino::setBuffSize(int num) // 受信バッファのサイズを決める　初期値10