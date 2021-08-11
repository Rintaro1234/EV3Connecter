EV3-Arduino互換機との通信を簡単にするライブラリ
Arduinoのアドレスは0x0Aとして扱う

機能
class EV3 このライブラリの機能が入ったクラス

int EV3::begin(int size) size分の送受信バッファを作成して、通信を始める

読み込み
int readInt() int型として受信バッファを読み込む
float readFloat() float型として受信バッファを読み込む
double readDouble() double型として受信バッファを読み込む
uint8_t readByte() バッファの中身を一つ読む
void clearReceiveBuff() レシーブバッファの中身を削除する
int available() 受信バッファのどこまで読んだかを確認する

書き込み
int sentInt(int val) int型を受け取ってそれを送信バッファに入れる
int sentFloat(float val) float型を受け取ってそれを送信バッファに入れる
int sentDouble(double val) double型を受け取ってそれを送信バッファに入れる
int sentByte(uint8_t val) uint8_t型を受け取ってそれを送信バッファに入れる
void clearSendBuff() 送信バッファの中身を削除する