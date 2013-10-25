class MYCLOCK
{
	public:
	void wait ( double seconds )
	{
		
		
		clock_t endwait;
		endwait = clock () + seconds * CLOCKS_PER_SEC ;
		while (clock() < endwait) {}
	}
	
	void animator_line ()
	{
		clock_t endwait;
		endwait = clock () + .035 * CLOCKS_PER_SEC ;
		while (clock() < endwait) {}
	}
};
MYCLOCK class_TIMER;
