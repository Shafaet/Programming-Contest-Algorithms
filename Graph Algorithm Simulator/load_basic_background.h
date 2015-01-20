void show_position()
{
	COLOR_GREEN;
	char buffer1[100],buffer2[100];
	sprintf(buffer1,"%d",struct_MOUSEAT.x);
	sprintf(buffer2,"%d",struct_MOUSEAT.y);
	strcat(buffer1,",");strcat(buffer1,buffer2);
	
	int leftx=(switch_sidebar2)?840-300:840;
	class_SHAPE.TEXT(leftx,11,buffer1,font_small);
}
	
void LOAD_BACKGROUND()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	COLOR_BLACK;
	class_SHAPE.RECT(0,0,HEIGHT,WIDTH);
	COLOR_WHITE;
	
	show_position();
	class_SHAPE.LINE(0,25,WIDTH,25);
	class_SHAPE.LINE(0,25*2,WIDTH,25*2);
	
		COLOR_YELLOW;
		class_SHAPE.FILLED_RECT(0,0,15,HEIGHT);
	if(!switch_infobar)
	{
		COLOR_BLUE;
		class_SHAPE.FILLED_RECT(WIDTH,0,WIDTH-15,HEIGHT);
		
    }
    
	
	
   	
}

