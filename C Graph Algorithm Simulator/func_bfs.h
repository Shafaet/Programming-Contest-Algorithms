void write_detail_bfs()
{
FILE *fp=fopen("details","w");

fprintf(fp,"BFS OUTPUT:\n\nSOURCE NODE : %s\n",fprint_level(source_sssp).c_str());
REP(i,Total_nodes)
{
fprintf(fp,"Dist from Node %s to Node %s is %s\n",fprint_level(source_sssp).c_str(),fprint_level(i).c_str(),fprint_dist(sssp_dis[i]).c_str());
}

fclose(fp);
}
void bfs_sssp(int source,int *cmap,int *d,int speed)
	{
	
		 queue<int>actQ;
         queue<int>waitQ;
         actQ.push(source);
         cmap[source]=1;
		 int level=1;
	 while(true)
	 {
		 while(!actQ.empty())
		 {
			 int top=actQ.front(); actQ.pop();
			 list<int>::iterator it;
			 for(it=list_edges[top].begin(); it!=list_edges[top].end();it++)
			 {
				 
				 if(!cmap[*it])
				 {
					 d[*it]=level;
					 
					 int x1=map_coordinate[*it].first;
					 int y1=map_coordinate[*it].second;
					 COLOR_ORANGE;
					 class_SHAPE.FILLEDCIRCLE(x1,y1,default_radius);
					 int tx=map_coordinate[top].first;
					 int ty=map_coordinate[top].second;
					 COLOR_GREEN;
					 class_SHAPE.FILLEDCIRCLE(tx,ty,default_radius);
					 COLOR_RED;
					 glLineWidth(2);
					 if(speed==FASTER)class_SHAPE.LINE(tx,ty,x1,y1);
					 else class_SHAPE.animate_LINE(tx,ty,x1,y1);
					 write_dist(level,*it);
					 glutSwapBuffers();
					 class_TIMER.wait(.5);
					
					 cmap[*it]=1;
					 waitQ.push(*it);
					 
				 }
				 
			 }
			 
			 
		 }
          level++;
			if(waitQ.empty()) break;
			while(!waitQ.empty())
			{
			 actQ.push(waitQ.front());
			 waitQ.pop();
			 
			}
				
	}
	glLineWidth(1);
	COLOR_BLACK;
	
	
		 
		 COLOR_BLUE;
		 
		  glutSwapBuffers();
					 class_TIMER.wait(1);
  }
	


int select_node()
{
	//LOAD_BACKGROUND();
	//class_static_graph.Load_nodes();
	//class_static_graph.Load_edges();
//	glutSwapBuffers();
			
		if(signal_LMB)
		{
			int value=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
			return value;
		
		}
	
	
	return 0;
	
}


void run_sssp()
{
	if(!source_sssp)
	{
		source_sssp=select_node();
		MASSAGE_TEXT_BIG("Please Select a node");
	}
	
	else
	{
		COLOR_RED;	color_selected_node(source_sssp);
		int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
		(value==2)?COLOR_BLUE:COLOR_RED;
		class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
		COLOR_WHITE;
		class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"Slower Animation",font_small);
		(value==1)?COLOR_BLUE:COLOR_RED;
		class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
		COLOR_WHITE;
		class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"Faster Animation",font_small);
	
		if(signal_LMB && value)
		{
	
	
	
		REMOVE_MASSAGE_TEXT_BIG("Please Select a node");
		for(int i=1;i<30;i++)sssp_dis[i]=inf;
		
		MASSAGE_TEXT("Simulating breadth-first-search alogrithm to find Single Source Shortest Path");
		
		sssp_dis[source_sssp]=0;
		int cmap[100]={0};
        bfs_sssp(source_sssp,cmap,sssp_dis,value);
		COLOR_BLACK;
		REMOVE_MASSAGE_TEXT("Simulating breadth-first-search algorithm to find Single Source Shortest Path");
		write_detail_bfs();
		switch_infobar=1;
		
	
	
		}	
}

}
