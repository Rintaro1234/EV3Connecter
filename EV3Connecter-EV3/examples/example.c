
task main()
{
	char RBuf[32];
	char WBuf[] = {1, 0x0A << 1};
	memset(RBuf, 0, 32);
	int b = 0;

	while(true)
	{
		sendI2CMsg(S1, WBuf, 32);
		Wait1Msec(100);
		ReadI2CReply(S1, RBuf, 32);
		Wait1Msec(100);

		int a = (int)RBuf[0] << 0 | (int)RBuf[1] << 8;
		eraseDisplay();
		displayBigTextLine(0*2, "%d %d", a, b%2);
		b++;
		while(100);
	}
}
