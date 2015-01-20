struct bell_edge{
    int x, y,cost;
   
}eb[100];

void run_bellman()
{
	Negative_cycle=0;
	if(!Total_nodes)
	{
		WARNING_TEXT("WARNING::NO GRAPH DETECTED");
		SWAPBUFFER
		class_TIMER.wait(2);
		mode_bell=0;
	}
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	(value==2)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"With Animation(slower)",font_small);
	(value==1)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"No Animation",font_small);
if(signal_LMB)
{
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	double speed=.4;
	if(value==1) speed=0;
	
	if(value)
	{
	int d[100];
	REP(i,Total_nodes)
	{
		int tt;
		if(i==1) tt=0;
		else tt=inf;
         d[i] = tt;
         if(value==2)
         {
			COLOR_GREEN;
			write_dist(tt,i);
		 }
		upd_bell[i]=0;
	 }
     
     
    int cc=0;
	REP(i,Total_nodes)
	for(int j=i+1;j<=Total_nodes;j++)
	{
		if(adj_matrix[i][j]!=0)
		{
			cc++;
			eb[cc].x=i;
			eb[cc].y=j;
			eb[cc].cost=adj_matrix[i][j];
			
		}
		
	}
	int i,j;
	
	for (i = 1; i <Total_nodes; ++i)
	{
		if(value==2)
		{
			COLOR_RED;
			color_selected_node(i);
		}
		for (j = 1; j <= cc; ++j)
		{
			if(value==2)
			{
				COLOR_GREEN;
				connect(eb[j].x,eb[j].y,1);
				write_dist(d[eb[j].y],eb[j].y);
				class_TIMER.wait(speed);
				SWAPBUFFER;
			}
			
			if (d[eb[j].x] + eb[j].cost < d[eb[j].y])
			{
				COLOR_BLACK;
				write_dist(d[eb[j].y],eb[j].y);
				d[eb[j].y] = d[eb[j].x] + eb[j].cost;
				upd_bell[eb[j].y]++;
				if(value==2)
				{
				COLOR_YELLOW;
				write_dist(d[eb[j].y],eb[j].y);
				}
					class_TIMER.wait(speed);
					SWAPBUFFER;
				
			}
			if(value==2)
			{
				COLOR_BLUE;
				connect(eb[j].x,eb[j].y,1);
				COLOR_GREEN;
				write_dist(d[eb[j].y],eb[j].y);
			}
			
		}
	}
				
	int NEG=0;
	for (j = 1; j <= cc; ++j)
			if (d[eb[j].x] + eb[j].cost < d[eb[j].y])
			{
				
				COLOR_BLACK;
				write_dist(d[eb[j].y],eb[j].y);
				d[eb[j].y] = d[eb[j].x] + eb[j].cost;
				upd_bell[eb[j].y]++;
				if(value==2)
				{
					COLOR_RED;
					write_dist(d[eb[j].y],eb[j].y);
				}
				
				class_TIMER.wait(speed);
				SWAPBUFFER;
				
				NEG=1;
			}
	COLOR_RED;
	if(NEG)MASSAGE_TEXT_BIG("NEGATIVE CYCLE FOUND!!");
	else MASSAGE_TEXT_BIG("NO NEGATIVE CYCLES!!");
	Negative_cycle=1;
	SWAPBUFFER;
	class_TIMER.wait(3);
	switch_infobar=1;
	//mode_bell=0;
}
}
}
