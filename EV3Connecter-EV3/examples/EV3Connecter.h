#define slaveAddress 0x0A // Adress of Arduino
#define requestBuffSize 0x00 // Request BuffSize of Arduino

// bit2Byte
union ByteBit
{
    byte val;
    byte bits[1];
};
// bit2Int
union IntBit
{
    int val;
    byte bits[4];
};
// bit2Float
union FloatBit
{
    float val;
    byte bits[4];
};

char receiveBuff[32]; // Buffer of Items from Arduino
char sendBuff[32]; // Buffer of Items to send to Arduino
int receivePoint; // Pointer Of ReceiveBuff
int sendPoint; // Pointer Of SendBuff
tSensors port; // The port attached Arduino

// The function to clear ReceiveBuffer
void clearReceiveBuff()
{
	memset(receiveBuff, 0, sizeof(char)*32);
	receivePoint = 1;
}

// The function to clear SendBuffer
void clearSendBuff()
{
	memset(sendBuff, 0, sizeof(char)*34);
	sendBuff[0] = 33;
	sendBuff[1] = slaveAddress << 1;
	sendPoint = 2;
}

// wait until PortFree
void checkI2C()
{
	clearTimer(T1);
	while(nI2CStatus[port]!=0){if(time1[T1] > 500) break;}
}

// start Conennting to Arduino
int begin(tSensors val)
{
		port = val;
		// ResetBuffer
		clearReceiveBuff();
		clearSendBuff();
		// Connecting Test
		// Request ArduinoBufferSize
    char WBuf[3] = {2, slaveAddress << 1, requestBuffSize};
    char RBuf[2];
    sendI2CMsg(port, WBuf, 32);
    checkI2C();
    readI2CReply(port, RBuf, 32);
    IntBit buffSize;
    buffSize.val = 0;
    buffSize.bits[0] = RBuf[0];
    buffSize.bits[1] = RBuf[1];
    return buffSize.val;
}

// request ArduinoData
int requestData(bool isSync)
{
	clearReceiveBuff();
	do{
		char a[2] = {1, 0x0A << 1};
		sendI2CMsg(port, a, 32);
		checkI2C();
		readI2CReply(port, receiveBuff, 32);
		if(!isSync) break;
		wait1Msec(100);
	}while(receiveBuff[0] == 0x00);
  return 0;
}

// readReceiveBuffer as Integer
int readInt()
{
	IntBit a;
	a.val = 0;
	a.bits[0] = receiveBuff[receivePoint+0];
	a.bits[1] = receiveBuff[receivePoint+1];
	receivePoint += 2;
	return a.val;
}
// readReceiveBuffer as Float
float readFloat()
{
	FloatBit a;
	a.val = 0;
	a.bits[0] = receiveBuff[receivePoint+0];
	a.bits[1] = receiveBuff[receivePoint+1];
	a.bits[2] = receiveBuff[receivePoint+2];
	a.bits[3] = receiveBuff[receivePoint+3];
	receivePoint += 4;
	return a.val;
}
// readReceiveBuffer as Byte
byte readByte()
{
	ByteBit a;
	a.val = 0;
	a.bits[0] = receiveBuff[receivePoint+0];
	receivePoint += 1;
	return a.val;
}

// -DEBUG- copy ReceiveBuffer to *data
void copyReceiveBuff(char *data)
{
	memcpy(data, receiveBuff, sizeof(char) * 32);
}

// send ByteData to Arduino
void setByte(byte val)
{
	char *valp = &val;
	sendBuff[sendPoint+0] = valp[0];
	sendPoint += 1;
}

// send IntegerData to Arduino !Int of Arduino is 2byte. so you have to round between -32768 and 32767!
void setInt(int val)
{
	char *valp = &val;
	sendBuff[sendPoint+0] = valp[0];
	sendBuff[sendPoint+1] = valp[1];
	sendPoint += 2;
}

// send FloatData to Arduino
void setFloat(float val)
{
	char *valp = &val;
	sendBuff[sendPoint+0] = valp[0];
	sendBuff[sendPoint+1] = valp[1];
	sendBuff[sendPoint+2] = valp[2];
	sendBuff[sendPoint+3] = valp[3];
	sendPoint += 4;
}

// send Data to Arduino
int sendData()
{
	char isFinish = 0;
	do{
		sendI2CMsg(port, sendBuff, 32);
		checkI2C();
		readI2CReply(port, &isFinish, 32);
	}while(isFinish != 0x01);
  return isFinish;
}

// -DEBUG- copy SendBuffer to *data
void copySendBuff(char *data)
{
	memcpy(data, sendBuff, sizeof(char) * 32);
}
