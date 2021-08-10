EV3-Arduino互換機との通信を簡単にするライブラリ
Arduinoのアドレスは0x0Aとして扱う

機能(基本)
class EV3 機能が入ったクラス

bool EV3:begin() EV3との接続を開始する。
void EV3::attach(uint8_t *data, int size, int address) EV3からのaddressが送られてくると、*dataからsize分の値を送信する。
uint8_t EV3::receiveAdd() EV3から送られてきた実行命令。
void *EV3::receiveArg() EV3から送られてきた値が入っているポインタを返す。

機能(発展)

void EV3::setFuncNum(int num) 関数の数、初期値10 必要に応じて変更することでメモリの節約ができる。 
void EV3::setBuffSize(int num) 受信バッファのサイズ　初期値32byte 必要に応じて変更することでメモリの節約ができる。 
