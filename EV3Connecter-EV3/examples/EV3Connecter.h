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
	memset(sendBuff, 0, sizeof(char)*32);
	sendPoint = 1;
}

// wait until PortFree
void checkI2C()
{
	while(nI2CStatus[port]!=0)
  {}
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
    readI2CReply(port, RBuf, 32)
    IntBit buffSize.;
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
		readI2CReply(port, receiveBuff, 32);
		displayBigTextLine(6*2, "%d", receiveBuff[0]);
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

// -DEBUG- readReceiveBuffer
int readInt(int address)
{
	return receiveBuff[address];
}

// -DEBUG- copy ReceiveBuffer to *data
void copyReceiveBuff(char *data)
{
	memcpy(data, receiveBuff, sizeof(char) * 32);
}

// send Data to Arduino
int sendData()
{
    return 0;
}
