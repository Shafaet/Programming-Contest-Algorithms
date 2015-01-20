
int too_close(int atX,int atY)
{
				map<int,pair<int,int> >::iterator mit;
		
				for(mit=map_coordinate.begin();mit!=map_coordinate.end();mit++)
				{
					
				 int H=(*mit).second.first;
				 int K=(*mit).second.second;
				 if(H==atX && K==atY) continue;
				 int dist=(atX-H)*(atX-H)+(atY-K)*(atY-K);
				 
				 if(dist<2*4*default_radius*default_radius)return 1;
				 
				}
				return 0;
}
void collect_node_info()
{
	COLOR_YELLOW;
		MASSAGE_TEXT("Click left button to Draw Nodes");
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	(value==1 || mode_delete)?COLOR_GREEN:COLOR_BROWN;
	class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-187,HEIGHT);
	COLOR_WHITE;class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"Delete Last Node",font_small);
	if(signal_LMB)
	{
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
		if(value)
		{
			list<int>::iterator it;
			list_edges[Total_nodes].clear();
				
			
			REP(i,Total_nodes-1)
			{
				int flag=0;
			   while(1)
			   {
				   flag=0;
					for(it=list_edges[i].begin();it!=list_edges[i].end();it++)	
					if(*it==Total_nodes)
					{
				    flag=1;
				    //printf(">>%d %d\n",i,*it);
				    list_edges[i].erase(it);
				    break;
					}
				if(!flag) break;
			   }
				
			}
			REP(i,Total_nodes)REP(j,Total_nodes)if(i==Total_nodes || j==Total_nodes) adj_matrix[i][j]=0;
			map_coordinate.erase(Total_nodes);
			if(Total_nodes)
			Total_nodes--;
		
			
		}
		else
		{
		pair<int,int>temp_pair;
		
		if(!too_close(struct_MOUSEAT.x,struct_MOUSEAT.y) && VALID_AREA_FOR_NODE && Total_nodes<=29)
		{
			Total_nodes++;
			temp_pair.first=struct_MOUSEAT.x; temp_pair.second=struct_MOUSEAT.y;
			map_coordinate[Total_nodes]=temp_pair;
			
			createfile_and_writegraph("Autosave");
		}
		else 
		{
			
			COLOR_RED;
			if(Total_nodes==30) class_SHAPE.TEXT(60,35,"Warning: Cant draw more then 30 nodes",font_small);
			else
			{
			
			  class_SHAPE.TEXT(60,35,"Warning!!: Cant draw in restricted areas or too close to another node",font_small);
						
			}
			glutSwapBuffers();
			class_TIMER.wait(.8);
		}
		}
	}
	
}

