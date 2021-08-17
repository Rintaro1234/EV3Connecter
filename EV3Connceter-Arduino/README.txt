EV3-Arduino互換機との通信を簡単にするライブラリ
Arduinoのアドレスは0x0Aとして扱う

機能
class EV3 このライブラリの機能が入ったクラス

int EV3::begin(int size) size分の送受信バッファを作成して、通信を始める(基本32byte)

読み込み
int readInt() int型として受信バッファを読み込む
float readFloat() float型として受信バッファを読み込む -Doubleと共用可-
uint8_t readByte() byte型として受信バッファを読み込む
uint8_t readReceiveBuff(uint8_t address) 受信バッファの中身をアドレスを指定して表示
void clearReceiveBuff() 受信バッファの中身を削除する
void resetReceivePointer() 受信バッファの中身を変えずにレシーブバッファポインタを最初に戻す

書き込み
int sentInt(int val) int型を受け取ってそれを送信バッファに入れる
int sentFloat(float val) float型を受け取ってそれを送信バッファに入れる -Doubleと共用可-
int sentByte(uint8_t val) uint8_t型を受け取ってそれを送信バッファに入れる
void beginTransmission() 送信バッファの中身を削除し、書き込みが始まることを示す
void endTransmission() 送信バッファの書き込み終了を示す
uint8_t readSendBuff(uint8_t address) 送信バッファの中身をアドレスを指定して表示
void clearSendBuff() 送信バッファの中身を削除する

使い方
送信
ev3.beginTransmission();
ev3.sentInt(val);
...;
...;
ev3.endTransmission();

受信
ev3.clearReceiveBuff() 前回の受信データを残したいときはev3.resetReceivePointer()
int val = ev3.readInt();
...;
...;

-注意！-
clerSendBuff<->endTransmission間は重い処理禁止