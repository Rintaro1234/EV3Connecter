#include"EV3Connecter.h"

task main()
{
	int a = begin(S1);
	char Buff[32];
	while(true)
	{
		char RBuff[3] = {2, 0x0A << 1, 0x01};
		sendI2CMsg(S1, RBuff, 32);
		requestData(true);
		copyReceiveBuff(Buff);
		int b = readInt();
		char c = readByte();
		float d = readFloat();
		eraseDisplay();
		displayBigTextLine(0*2, "%d", a);
		displayBigTextLine(1*2, "%d", b);
		displayBigTextLine(2*2, "%d", c);
		displayBigTextLine(3*2, "%lf", d);

		wait1Msec(100);
	}
}
