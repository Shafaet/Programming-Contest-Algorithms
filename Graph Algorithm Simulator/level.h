void getlevel()
{
	if(signal_KEY)
	{
		
		if(VALID_LEVEL_KEY && new_level.size()<4)
		{
			new_level.push_back(CHAR_PRESSED);
						
		}
		if(CHAR_PRESSED==BACKSPACE_KEY && new_level.size())
		{
					string::iterator it=new_level.end()-1;
					new_level.erase(it);
		}
		if(CHAR_PRESSED==ENTER_KEY)
		{
			map_level[select_for_level]=new_level;
			freeze=0;
			select_for_level=0;
			
			new_level.clear();
			glutPostRedisplay();
			
		}
					
		COLOR_RED;
		class_SHAPE.TEXT((WIDTH/2)-25,(HEIGHT/2),new_level,font_medium);
		signal_KEY=0;
	}
	
}
void level()
{
	COLOR_YELLOW;
	class_SHAPE.TEXT(60,10,"Select a Node to level it",font_small);
	if(signal_LMB)
	{
		
		RESET_signal_MOUSE;
		if(!select_for_level)
		{
			select_for_level=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
		    
		}
				
	}
   
   if(select_for_level)
   {
	   COLOR_RED;	color_selected_node(select_for_level);
	   freeze=1;
	   COLOR_WHITE;
	   class_SHAPE.FILLED_RECT((WIDTH/2)-40,(HEIGHT/2)-18,(WIDTH/2)+40,(HEIGHT/2)+18);
	   getlevel();
	   
   }	
}
