#include"EV3Connecter.h"

task main()
{
	int a = begin(S1);
	while(true)
	{
		requestData(true);
		int b = readInt();

		eraseDisplay();
		displayBigTextLine(0*2, "%d", a);
		displayBigTextLine(1*2, "%d", b);

		char e = 0x10;
		switch(getButtonPress(buttonEnter))
		{
			case 0:
				e = 0x10;
			break;
			case 1:
				e = 0x11;
			break;
		}

		int f = 10234;
		clearSendBuff();
		sendByte(e);
		sendInt(f);
		sendData();

	}
}
