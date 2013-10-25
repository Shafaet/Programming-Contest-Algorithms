
void COLOR_CHOICE(int n)
{
	
	if(n==2) COLOR_RED;
	else if(n==3) COLOR_YELLOW;
	else if(n==4) COLOR_BLUE;
	else if(n==5) COLOR_GREEN;
	else if(n==6) COLOR_BROWN;
	else if(n==7) COLOR_DBLUE;
	else if(n==8) COLOR_PINK;
	else if(n==9) COLOR_ORANGE1;
	else if(n==10) COLOR_BROWN2;
	else if(n==11) COLOR_PINK2;
	else if(n==12) COLOR_MORE1;
	else if(n==13) COLOR_MORE2;
	else if(n==14) COLOR_MORE3;
	else COLOR_WHITE;
	
}

void color()
{
	
	COLOR_YELLOW;
	class_SHAPE.TEXT(60,10,"Select a Node to Color it",font_small);
	
	
	
	if(signal_LMB)
	{
		RESET_signal_MOUSE;
		if(!select_for_color)
		{
			select_for_color=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
		    
		}
		else 
		{
			int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_colorbox_buttons);
			if(value)
			{
				
				map_color[select_for_color]=value;
				select_for_color=0;
			}
						
		}
	    		
	}
	
	if(select_for_color)
	{
			glLineWidth(1);
			COLOR_BROWN;
			class_SHAPE.FILLED_RECT(WIDTH,0,WIDTH-125,HEIGHT);
			
			int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_colorbox_buttons);
			int godown=0;
			for(int i=1;i<=7;i++)
			{
				COLOR_CHOICE(i);
				class_SHAPE.FILLED_RECT(WIDTH-110,HEIGHT-60-godown,WIDTH-10,HEIGHT-20-godown);
				if(i==value){glLineWidth(2);COLOR_BLACK;class_SHAPE.RECT(WIDTH-110,HEIGHT-60-godown,WIDTH-10,HEIGHT-20-godown);}
				godown+=50;
				
			}
	}
}
