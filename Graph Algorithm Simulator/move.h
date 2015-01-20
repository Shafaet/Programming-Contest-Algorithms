void move_the_nodes()
{
	
	int x,y;
	if(select_for_move)
	{
		
		if(struct_MOUSEAT.y>58 && struct_MOUSEAT.x>35)
		{
			map_coordinate[select_for_move].first=struct_MOUSEAT.x;
			map_coordinate[select_for_move].second=struct_MOUSEAT.y;
			int H=map_coordinate[select_for_move].first;
			int K=map_coordinate[select_for_move].second;
			COLOR_RED;
			class_SHAPE.FILLEDCIRCLE(H,K,default_radius);
			write_number(select_for_move,H,K);
			if(signal_LMB)
			select_for_move=0;
		}
			
	}
	else if(signal_LMB)
	{
		
		
		select_for_move=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
		if(select_for_move)
		{
			x=map_coordinate[select_for_move].first;
			y=map_coordinate[select_for_move].second;
			createfile_and_writegraph("Autosave");
		}
			
	}
		
}
