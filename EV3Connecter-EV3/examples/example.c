#include"EV3Connecter.h"

task main()
{
	int a = begin(S1);
	while(true)
	{
		eraseDisplay();
		displayBigTextLine(0*2, "%d %d", a);

		wait1Msec(100);
	}
}
