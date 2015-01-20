void check_close()
{
    int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_close_button);
	value?COLOR_YELLOW:COLOR_BLUE;
	class_SHAPE.FILLED_RECT(WIDTH,HEIGHT,WIDTH-60,HEIGHT-20);
	COLOR_RED; class_SHAPE.TEXT(WIDTH-45,HEIGHT-13,"Close",font_small);
		
	if(signal_LMB)
	{
	      value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_close_button);
	      if(value) mode_credits=0;
	}
}	
void show_credits()
{
	
	COLOR_RED;
	
	
	class_SHAPE.FILLED_RECT(0,0,WIDTH,HEIGHT); 
	
     check_close();
	
}
