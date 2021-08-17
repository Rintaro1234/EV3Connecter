EV3-Arduino互換機との通信を簡単にするライブラリ
Arduinoのアドレスは0x0Aとして扱う

int begin(tSensors port) Arduinoとの接続を開始する。返り値はArduinoのバッファサイズ。引数はArduinoが刺さっているポート

受信
void clearReceiveBuff() 受信バッファの中身を削除する
void requestData(bool isSync) Arduinoからデータを受信する 引数は基本true
int readInt() 受信バッファの内容をIntとして読み
float readFloat() 受信バッファの内容をFloatとして読む
byte readByte() 受信バッファの内容をByteとして読む

送信
void clearSendBuff() 送信バッファの中身を削除する
void setByte(byte val) 送信バッファにbyteの値を入れる
void setInt(int val) 送信バッファにintの値を入れる
void setFloat(float val) 送信バッファにfloatの値を入れる
int sendData() 送信バッファの中身をArduinoに送る

-DEBUG-
void copyReceiveBuff(char *data) 受信バッファの内容を*dataの中にコピーする
void copySendBuff(char *data) 送信バッファの中身を*dataの中にコピーする

使い方
送信
clearSendBuff();
setByte(val);
...;
...;
sendData();

受信
requestData(true);
readByte();
...;
...;

!read,setの順番はArduinoとそろえる!
例)Arduino -> EV3
Arduino側
ev3.beginTransmission();
ev3.setByte(val0);
ev3.setInt(val1);
ev3.endTransmission();
EV3側
requestData();
byte a = readByte();
int b = readInt();

例)EV3 -> Arduino
EV3側
clearSendBuff()
setByte(val0);
setInt(val1);
sendData();

Arduino側
ev3.resetReceivePointer();
byte a = ev3.readByte();
int b = ev3.readInt();