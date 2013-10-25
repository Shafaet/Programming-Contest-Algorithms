void getcost()
{
	COLOR_RED;
	color_selected_node(select_2);
	
	freeze=1;
	
		COLOR_WHITE;
		class_SHAPE.FILLED_RECT((WIDTH/2)-40,(HEIGHT/2)-18,(WIDTH/2)+40,(HEIGHT/2)+18);
		if(signal_KEY)
		{
	
				if(CHAR_PRESSED==ENTER_KEY)
				{
					
					char buffer[10];
					adj_matrix[select_1][select_2]=atoi(strcpy(buffer,input_cost.c_str()));
					adj_matrix[select_2][select_1]=atoi(strcpy(buffer,input_cost.c_str()));
					printf("%d\n",atoi(strcpy(buffer,input_cost.c_str())));
					input_cost.clear();
					freeze=0;
					RESET_SELECTION;
					mode_addcost=1;
					glutPostRedisplay();
				}
				if(CHAR_PRESSED==BACKSPACE_KEY && input_cost.size())
				{
					string::iterator it=input_cost.end()-1;
					input_cost.erase(it);
					
				}
			    if( ((CHAR_PRESSED>='0' && CHAR_PRESSED<='9') || CHAR_PRESSED=='-') && input_cost.size()<=4)
			    {					
				
					input_cost.push_back(CHAR_PRESSED);
				}
			
			COLOR_RED;
			class_SHAPE.TEXT((WIDTH/2)-25,(HEIGHT/2),input_cost,font_medium);
			signal_KEY=0;
		}
		
}
void collect_cost_info()
{
	
       COLOR_YELLOW;
	class_SHAPE.TEXT(130,10,"Select Pair of Edges to add costs",font_small);
	
	if(signal_LMB)
	{
		
		RESET_signal_MOUSE;
		if(!freeze)
		{
			if(!select_1)
				select_1=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
			else
			{
				select_2=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
				if(!select_2)
				select_1=0;
			
			}
		}
		
	}
	COLOR_BLUE;
	if(select_2)
	{
		if(adj_matrix[select_1][select_2])
		getcost();
		else { RESET_SELECTION;}
	}
	COLOR_RED;
	color_selected_node(select_1);
}
