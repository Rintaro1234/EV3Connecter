#include"EV3Connecter.h"

task main()
{
	int a = begin(S1);
	while(true)
	{
		requestData(true);
		int b = readInt();
		char c = readByte();
		float d = readFloat();

		eraseDisplay();
		displayBigTextLine(0*2, "%d", a);
		displayBigTextLine(1*2, "%d", b);
		displayBigTextLine(2*2, "%d", c);
		displayBigTextLine(3*2, "%lf", d);
		wait1Msec(1000);

		clearSendBuff();
		char e = 120;
		sendByte(e);
		int f = 10234;
		sendInt(f);
		sendData();
		wait1Msec(1000);
	}
}
