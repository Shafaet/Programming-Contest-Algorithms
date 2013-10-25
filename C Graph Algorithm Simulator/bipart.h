void load_bipart_buttons()
{
	
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	(value==2)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"Move and Make Bipartite",font_small);
	(value==1)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"Make Bipartite",font_small);
  	
}
void bipart_info()
{
	list<int>::iterator it;
	 
   load_bipart_buttons();
    for(it=list_bipart_nodes.begin();it!=list_bipart_nodes.end();it++)
    {
		COLOR_RED;
		color_selected_node(*it);
    }
   
    if(signal_LMB)
    {
		
		int value=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
		if(value)
		{
			int flag=1;
			for(it=list_bipart_nodes.begin();it!=list_bipart_nodes.end();it++)
			 if(*it==value) flag=0;
			
			if(flag)
			list_bipart_nodes.push_back(value);
			else
			{WARNING_TEXT("Warning:: Already Selected");	}
		}
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
		
		if(value)
		{
			if(!list_bipart_nodes.size()) {WARNING_TEXT("Error:: No Node Selected");}
			else
			{
				if(value==2)class_Transform.align_nodes(list_bipart_nodes);
				class_Transform.bipartite_graph(list_bipart_nodes);
				mode_bipart=0;
			}
		}
		
		
	}
   
}
