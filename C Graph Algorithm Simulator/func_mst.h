void write_detail_mst()
{
	FILE *fp=fopen("details","w");
	fprintf(fp,"MST OUTPUT:\n\n\n");
	fprintf(fp,"Spanning Cost: %d\n",spanning_cost);
	for(vector<edges_mst>::iterator it=vect_mst.begin();it<vect_mst.end();it++)
	{
		fprintf(fp,"%s connected with %s\n",fprint_level((*it).x).c_str(),fprint_level((*it).y).c_str());
		
	}
	fclose(fp);
		
}
int pr[10002];
int find(int r) 
{ 
	return r==pr[r]?r:(pr[r]=find(pr[r])); 
}

int run_kruskals_mst_min(int anim)
{
	int u,v;
	
	int r=0;
	glutSwapBuffers();
		
	vector<mst_min>::iterator it;
	for(it=mst_min_vect.begin();it<mst_min_vect.end();it++)
	
	{
		glLineWidth(2);
		u=find((*it).u);	
		v=find((*it).v);
		
		int x1=map_coordinate[(*it).u].first;    int y1=map_coordinate[(*it).u].second;
	    int x2=map_coordinate[(*it).v].first;    int y2=map_coordinate[(*it).v].second;
	    
	    if(anim==SLOWER)
	    {
			COLOR_RED;    
			class_SHAPE.LINE(x1,y1,x2,y2);
			glutSwapBuffers();
			class_TIMER.wait(.5);
		}
		
		if(u!=v) 
		{
	        if(anim==SLOWER)
	        {
				COLOR_GREEN;
				class_SHAPE.LINE(x1,y1,x2,y2);
			}
	      	r+=(*it).w;
	      	edges_mst t;
	      	t.x=(*it).u; t.y=(*it).v;
	      	vect_mst.push_back(t);
			pr[u]=v;
			if(anim==SLOWER)
			{
				glutSwapBuffers();
				class_TIMER.wait(.5);
			}
		}	
		else
		{
			glLineWidth(3);
			COLOR_BLACK;
	        class_SHAPE.LINE(x1,y1,x2,y2);
	        glLineWidth(1);
	        if(anim==SLOWER)
	        {
				COLOR_BLUE;
				class_SHAPE.LINE(x1,y1,x2,y2);
			}
			
		}
			
			
	
	}
	if(anim==SLOWER)
	{
		glutSwapBuffers();
		class_TIMER.wait(2.5);
	}
	return r;
}

void collect_minspan_info()
{
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_bipart_buttons);
	(value==2)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-160,HEIGHT-20,WIDTH-40,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-157,HEIGHT-13,"Show Animaton",font_small);
	(value==1)?COLOR_BLUE:COLOR_RED;
	class_SHAPE.FILLED_RECT(WIDTH-270,HEIGHT-20,WIDTH-190,HEIGHT);
	COLOR_WHITE;
	class_SHAPE.TEXT(WIDTH-267,HEIGHT-13,"No Animation",font_small);
if(signal_LMB)
{
	if(value)
	{
	int i;
    mst_min_vect.clear();
    vect_mst.clear();
	int taken[100][100];
	REP(i,99)REP(k,99) taken[i][k]=0;
	
	for(i=1;i<=Total_nodes;i++)
	{
		
		list<int>:: iterator it;
		for(it=list_edges[i].begin();it!=list_edges[i].end();it++)
		{
			mst_min temp;
			temp.u=i; temp.v=*it; temp.w=adj_matrix[i][*it];
			if(!taken[temp.u][temp.v] && !taken[temp.v][temp.u])
			{
				mst_min_vect.push_back(temp);
				taken[temp.u][temp.v]=1; taken[temp.v][temp.u]=1;
			}
	
		}
	
	}
	
	vector<mst_min>::iterator it;
	sort(mst_min_vect.begin(),mst_min_vect.end());
	
	for(i=0;i<=1000;i++) pr[i]=i;
	spanning_cost=run_kruskals_mst_min(value);
	
	glLineWidth(1);
	write_detail_mst();
	switch_infobar=1;	
	}
}

}

