void write_detail_union()
{
	FILE *fp=fopen("details","w");
	int largest=0,smallest=INF,i;
	fprintf(fp,"UNION FIND OUTPUT:\n\nThe components are:\n");
	for(i=1; ;i++)
	{
		if(list_connected_components[i].size()==0)break;
		int size=list_connected_components[i].size();
		if(size>largest) largest=size;
		if(size<smallest) smallest=size;
		for(list<int>::iterator vit=list_connected_components[i].begin();vit!=list_connected_components[i].end();vit++)
		fprintf(fp,"%d ",*vit);
		fprintf(fp,"\n");
	}
	fprintf(fp,"Number of components %d\n",i-1);
	fprintf(fp,"The largets Component size is %d\n",largest);
	fprintf(fp,"The Smalles Component size is %d\n",smallest);
	fclose(fp);
	
	
}
void dfs_union_find(int source,int *index_map,int area_no,int speed)
	{
		
		
		list<int>::iterator it;
			list_connected_components[area_no].push_back(source);
		for ( it=list_edges[source].begin() ; it != list_edges[source].end(); it++ )
		{
			
			if(index_map[(*it)]==0)
			{
				COLOR_YELLOW;
				int x1=map_coordinate[*it].first;
				int y1=map_coordinate[*it].second;
				
				int sx=map_coordinate[source].first;
				int sy=map_coordinate[source].second;
				COLOR_GREEN;
		       if(speed==FASTER) 
		       {
					class_SHAPE.LINE(sx,sy,x1,y1);
					SWAPBUFFER;
					class_TIMER.wait(.25);
					
					
				}
		       else	class_SHAPE.animate_LINE(sx,sy,x1,y1);
				COLOR_YELLOW;
				class_SHAPE.FILLEDCIRCLE(x1,y1,default_radius);
				
				COLOR_RED;
				write_number(*it,x1,y1);
				
                index_map[*it]=1;
				dfs_union_find(*it,index_map,area_no,speed);
			}
			
                                                               
       }
	}

void show_components()
{
	if(!Total_nodes) return;
	MASSAGE_TEXT("Showing Connected components......");
	glutSwapBuffers();
	
	class_TIMER.wait(1);
	for(int i=1; ;i++)
	{ 
		class_static_graph.Load_nodes();
		class_static_graph.Load_edges();
		
				if(i!=1)
				class_TIMER.wait(.4);
				COLOR_GREEN;
						
				if(list_connected_components[i].size()==0)break;
				
				for(list<int>::iterator vit=list_connected_components[i].begin();vit!=list_connected_components[i].end();vit++)
				{
					COLOR_RED;
					int temp=*vit;
					int x=map_coordinate[temp].first;
					int y=map_coordinate[temp].second;
				      
					class_SHAPE.FILLEDCIRCLE(x,y,default_radius);
					glutSwapBuffers();	
				}
				
			}
	
	
		
	
	}



void run_union_find()
{
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	(value==2)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"Slower Animation",font_small);
	(value==1)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"Faster Animation",font_small);
if(signal_LMB)
{
	signal_LMB=0;
		int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	if(value)
	{
	LOAD_BACKGROUND();
	SWAPBUFFER;
	int cmap[100]={0},area_no=1;
	for(int i=0;i<30;i++)list_connected_components[i].clear();
	for(int i=1;i<=Total_nodes;i++)
	{
         
         MASSAGE_TEXT("Simulating depth-first-search alogrithm to find Strongly connected componenents");
         if(!cmap[i])
        {
			COLOR_GREEN;
			int x1=map_coordinate[i].first;
			int y1=map_coordinate[i].second;
			class_SHAPE.FILLEDCIRCLE(x1,y1,default_radius);
			COLOR_RED;
			write_number(i,x1,y1);
			glutSwapBuffers();
			class_TIMER.wait(.5);
			cmap[i]=1;
			dfs_union_find(i,cmap,area_no++,value);
			
		
		}
		if((int)list_connected_components[area_no-1].size()>Largest_union) Largest_union=list_connected_components[area_no-1].size();
	}
	glutSwapBuffers();
	LOAD_BACKGROUND();
	class_static_graph.Load_nodes();
	class_static_graph.Load_edges();
	COLOR_BLACK;
    class_SHAPE.TEXT(60,10,"Simulating depth-first-search alogrithm to find Strongly connected componenents",font_small);
    glutSwapBuffers();
    if(Total_nodes)  class_TIMER.wait(.3);
	show_components();
	write_detail_union();
	switch_infobar=1;	
}
}
}
