int odd_deg_count()
{
	int odd=0;
	MASSAGE_TEXT_BIG("Counting vertexes with odd degree");
	SWAPBUFFER;class_TIMER.wait(.3);
	REP(i,Total_nodes)
	{
		int cnt=0;
		REP(j,Total_nodes)
		{
		  if(adj_matrix[i][j]) cnt++; 
		 
		}
		if(cnt%2==1){ odd++; COLOR_GREEN;	color_selected_node(i);SWAPBUFFER;class_TIMER.wait(.5);}
	}
	REMOVE_MASSAGE_TEXT_BIG("Counting vertexes with odd degree");
	SWAPBUFFER;class_TIMER.wait(.3);
	return odd;
	
	
	
}
void eulerp_backtrack(int src,int vis[][50],int T_edge, FILE*fp,int speed)
{
	if((int)vect_eulerP.size()==T_edge+1)
	{
	    vector<int>::iterator mit;	
	    int goright=0,godown=0;;
	    for(mit=vect_eulerP.begin();mit<vect_eulerP.end();mit++)
	    {
			fprintf(fp,"%s ",fprint_level(*mit).c_str());
			char str[10];
			if(speed==SLOWER)
			{
			sprintf(str,"%d",*mit);
			COLOR_YELLOW;  class_SHAPE.TEXT(60+goright,35-godown,str,font_large);
			}
			goright+=20;
			if(goright>=650) {goright=0; godown=25;}
		}
		if(vect_eulerP[0]==vect_eulerP.back())fprintf(fp,"[+Circuit]");
		REP(i,Total_nodes) REP(j,Total_nodes)if(adj_matrix[i][j]) { if(speed==SLOWER){COLOR_RED;connect(i,j,1);}}
		
		if(speed==SLOWER)
		{
			SWAPBUFFER; 
			class_TIMER.wait(.12);
		}
		 
		LOAD_BACKGROUND();
		class_static_graph.Load_edges();
		class_static_graph.Load_nodes();
	
		REP(i,Total_nodes) REP(j,Total_nodes)if(adj_matrix[i][j]) {if(speed==SLOWER){COLOR_GREEN;connect(i,j,1);}}
		if(speed==SLOWER){SWAPBUFFER; class_TIMER.wait(.4);}
	    fprintf(fp,"\n");
		
		
	}
	list<int>::iterator it;
	for(it=list_edges[src].begin();it!=list_edges[src].end();it++)
	{
		if(!vis[src][*it] && !vis[*it][src])
		{
			
			vis[src][*it]=1; vis[*it][src]=1;
			if(speed==SLOWER){COLOR_GREEN;
			connect(src,*it,1);}
			if(speed==SLOWER){SWAPBUFFER; class_TIMER.wait(.5);}
			vect_eulerP.pb(*it);
			eulerp_backtrack(*it,vis,T_edge,fp,speed);
			
			vect_eulerP.ppb();
			vis[src][*it]=0; vis[*it][src]=0;
			if(speed==SLOWER){COLOR_BLUE;
			connect(src,*it,1);}
			if(speed==SLOWER){SWAPBUFFER; class_TIMER.wait(.2);}
			
		}
			
	}
	
	
}

void run_eulerP()
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
if(signal_LMB && value)
{
		WARNING_TEXT("WARNING::The backtrack algorithm may take long time if the graph is slightly large");
		SWAPBUFFER; class_TIMER.wait(1);
		REMOVE_WARNING_INFO_TEXT("WARNING::The backtrack algorithm may take long time if the graph is slightly large");
	int vis[50][50];
	
	
	FILE *fp=fopen("details","w");
	fprintf(fp,"Euler Paths: \n");
	int T_odd=odd_deg_count();
	if(T_odd==2 || T_odd==0)
	{
		REP(k,Total_nodes)
		{
		vect_eulerP.clear();
		int T_edge=0;
		REP(i,Total_nodes)
			REP(j,Total_nodes)
			{
			if(adj_matrix[i][j])T_edge++;
			vis[i][j]=0;
			}
		T_edge/=2;
		vect_eulerP.pb(k);
		eulerp_backtrack(k,vis,T_edge,fp,value);
	 
		}
	}
	else
	{
		fprintf(fp,"Graph with euler path must have exactly 0 or 2 odd degree,This graph doesnt fill the condition: \n");
		MASSAGE_TEXT_BIG("The graph must have exactly 0 or 2 odd degree to have euler path");
		SWAPBUFFER; class_TIMER.wait(1.2);
		REMOVE_MASSAGE_TEXT_BIG("The graph must have exactly 0 or 2 odd degree to have euler path");
	}
	 fclose(fp);
	switch_infobar=1;
	//mode_eulerP=0;
}
	
}
