void collect_edge_info()
{
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	(value==2 || !mode_delete)?COLOR_GREEN:COLOR_BROWN;
	class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
	COLOR_WHITE; class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"Add Edge",font_small);
	(value==1 || mode_delete)?COLOR_GREEN:COLOR_BROWN;
	class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
	COLOR_WHITE;class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"Delete Edge",font_small);
	
	
	if(signal_LMB)
	{
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
		if(value==1) mode_delete=1; if(value==2) mode_delete=0;
		
		if(!select_1)
		{
			select_1=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
			COLOR_YELLOW;
			MASSAGE_TEXT("Select Pair of Edges to Connect or delete them");
		
		}
		else 
		{
			select_2=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
			if(select_2)
			{
				if(mode_delete && adj_matrix[select_1][select_2])
				{
					adj_matrix[select_1][select_2]=0;
					adj_matrix[select_2][select_1]=0;
					list<int>::iterator it;
					for(it=list_edges[select_1].begin();it!=list_edges[select_1].end();it++)if((*it)==select_2) {list_edges[select_1].erase(it); break;}
					for(it=list_edges[select_2].begin();it!=list_edges[select_2].end();it++)if((*it)==select_1) {list_edges[select_2].erase(it); break;}
					createfile_and_writegraph("Autosave");
				}
				
				else if(!adj_matrix[select_1][select_2] && !adj_matrix[select_2][select_1] && select_2!=select_1)
				{
					list_edges[select_1].push_back(select_2);
					list_edges[select_2].push_back(select_1);
					adj_matrix[select_1][select_2]=1;
					adj_matrix[select_2][select_1]=1;
					createfile_and_writegraph("Autosave");
			
				}
				
				else {COLOR_RED;class_SHAPE.TEXT(60,35,"Warning: Already connected!",font_small); glutSwapBuffers();class_TIMER.wait(1);	}
			}
			select_2=0;
			select_1=0;
		}
	}
	 COLOR_RED;
		color_selected_node(select_1);
}


