void write_detail_dij()
{
FILE *fp=fopen("details","w");
fprintf(fp,"DIJKSTRA OUTPUT: SOURCE NODE : %s\n",fprint_level(source_sssp_dij).c_str());
REP(i,Total_nodes)
{
fprintf(fp,"Dist from Node %s to Node %s is %s\n",fprint_level(source_sssp_dij).c_str(),fprint_level(i).c_str(),fprint_dist(sssp_dis_dij[i]).c_str());
}

fclose(fp);
	
}

void dijkstra(int source,int value)
{
	if(value==SLOWER)
	MASSAGE_TEXT("Running DIJKSTRA to Find single source shortest path");
	 REP(i,Total_nodes) 
	 {
		 
		 if(value==SLOWER)
		 {
			 INFO_TEXT("Assigning Infinity to all nodes except source!");
			COLOR_BLUE;
			write_dist(sssp_dis_dij[i],i);
			glutSwapBuffers(); class_TIMER.wait(.2);
		 }
		 if(i==source) sssp_dis_dij[i]=0;
		 else sssp_dis_dij[i]=inf;
		
	}
	 REMOVE_WARNING_INFO_TEXT("Assigning Infinity to all nodes except source!");
	 priority_queue<data> actq;
	 priority_queue<data> waitq;
	 data e;
	 e.city=source;
	 e.dist=0;
	 actq.push(e);
	while(true)
	{
		if(value==SLOWER)INFO_TEXT("Updating Distance!");
     while(!actq.empty())
     {
		 
		 data top=actq.top();
		 actq.pop();
		 int topcost=sssp_dis_dij[top.city];
		 list<int>::iterator it;
		 
		 
		 int H=map_coordinate[top.city].first;
			int K=map_coordinate[top.city].second;
		 if(value==SLOWER)
		 {
			 COLOR_CHOICE(GREEN);
			 
			class_SHAPE.FILLEDCIRCLE(H,K,default_radius);
			glutSwapBuffers();	 class_TIMER.wait(.3);
		}
		 
		 
		 for(it=list_edges[top.city].begin();it!=list_edges[top.city].end();it++)
		 {
			 
			 data temp;
			 temp.city=*it;
			 temp.dist=adj_matrix[*it][top.city]+topcost;
			 if(sssp_dis_dij[temp.city]>temp.dist)
			 {
	 
				 
				 if(value==SLOWER)
				 {
					 int H2=map_coordinate[temp.city].first;
					int K2=map_coordinate[temp.city].second;
					COLOR_BLACK;	 write_dist(sssp_dis_dij[temp.city],temp.city);
					COLOR_RED;	 write_dist(temp.dist,temp.city);
					class_SHAPE.LINE(H,K,H2,K2);
					COLOR_CHOICE(YELLOW);
					class_SHAPE.FILLEDCIRCLE(H2,K2,default_radius);
					glutSwapBuffers();		class_TIMER.wait(.4);
					COLOR_BLUE;
					class_SHAPE.LINE(H,K,H2,K2);
				}
				 
				 
				 sssp_dis_dij[temp.city]=temp.dist;
				 waitq.push( temp );
			 }
		 }
		 if(value==SLOWER)
		 {
		 COLOR_CHOICE(RED);
		 class_SHAPE.FILLEDCIRCLE(H,K,default_radius);
		 glutSwapBuffers();
		 class_TIMER.wait(.3);
		 }
		 
		 
		}
		if(waitq.empty()) break;
		
		if(value==SLOWER){glutSwapBuffers(); class_TIMER.wait(.3);}
		while(!waitq.empty())
		{
		
			actq.push(waitq.top());
			waitq.pop();
		}
	
	}
	REMOVE_WARNING_INFO_TEXT("Updating Distance!");
write_detail_dij();

}


void run_sssp_dij()
{
	
	if(!source_sssp_dij)
	{
		MASSAGE_TEXT_BIG("Please Select a node");
		
		source_sssp_dij=select_node();    //defined in func_bfs
	}
	else
	{
		COLOR_RED;	color_selected_node(source_sssp_dij);
		int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
		(value==2)?COLOR_BLUE:COLOR_RED;
		class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
		COLOR_WHITE;
		class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"With Animation",font_small);
		(value==1)?COLOR_BLUE:COLOR_RED;
		class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
		COLOR_WHITE;
		class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"No Animation",font_small);
		if(signal_LMB && value)
		{
		dijkstra(source_sssp_dij,value);
		source_sssp=0;
		switch_infobar=1;	
		}
	}
	
}
