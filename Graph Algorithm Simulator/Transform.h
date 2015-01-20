void connect(int n1,int n2,int linetype)
{
	if(!adj_matrix[n1][n2])
	{
		adj_matrix[n1][n2]=1;
		adj_matrix[n2][n1]=1;
		list_edges[n1].push_back(n2);  list_edges[n2].push_back(n1);
	}
	int x1=map_coordinate[n1].first;	int y1=map_coordinate[n1].second;
	int x2=map_coordinate[n2].first;	int y2=map_coordinate[n2].second;
	
	if(linetype==2)
	class_SHAPE.animate_LINE(x2,y2,x1,y1);	
	if(linetype==1)
	class_SHAPE.LINE(x2,y2,x1,y1);	
	//SWAPBUFFER;
	//class_TIMER.wait(.5);
	//REDISPLAY;
	
}

void move_around(int front,int xx,int yy)
{
	int prevx=0,prevy=0;
		while(!(abs(map_coordinate[front].first-xx)<=1))
		{
			if(xx<map_coordinate[front].first)		map_coordinate[front].first-=2;
			if(xx>map_coordinate[front].first)		map_coordinate[front].first+=2;
			
			
			COLOR_GREEN;
			class_SHAPE.FILLEDCIRCLE(map_coordinate[front].first,map_coordinate[front].second,default_radius);
			COLOR_BLACK;
			if(prevx)class_SHAPE.FILLEDCIRCLE(prevx,prevy,default_radius);
			class_static_graph.Load_edges();
			class_static_graph.Load_nodes();
			
			SWAPBUFFER;
			
			class_TIMER.wait(.0000000001);
		    prevx=map_coordinate[front].first;prevy=map_coordinate[front].second;
		    
		}
		
		
		prevx=0; prevy=0;
    	while(!(abs(map_coordinate[front].second-yy)<=1))
		{
			if(yy<map_coordinate[front].second)		map_coordinate[front].second-=2;
			if(yy>map_coordinate[front].second)		map_coordinate[front].second+=2;
			//printf("%d %d\n",map_coordinate.second,pos[cnt][1]);
			
			COLOR_GREEN;
			class_SHAPE.FILLEDCIRCLE(map_coordinate[front].first,map_coordinate[front].second,default_radius);
			COLOR_BLACK;
			if(prevx)class_SHAPE.FILLEDCIRCLE(prevx,prevy,default_radius);
			class_static_graph.Load_edges();
			class_static_graph.Load_nodes();
			
			SWAPBUFFER;
			
			class_TIMER.wait(.0000000001);
		    prevx=map_coordinate[front].first;prevy=map_coordinate[front].second;
		    
		}
		
		
}



class Transform
{
	
	
	public:
void complete_graph()
	{
    int flag=0;	

	REP(i,Total_nodes)
	{
	  for(int j=i+1;j<=Total_nodes;j++)
	  {
		  if(adj_matrix[i][j]) continue;
		  flag=1;	
		  connect(j,i,1);
	  }
  }
  if(!flag)
  {
	  COLOR_RED;
	  class_SHAPE.TEXT(60,35,"Warning!!: The Graph is already Complete",font_small);
	  glutSwapBuffers();
	  class_TIMER.wait(1.5);
  }
  REDISPLAY;
	mode_complete=0;
}


void ring_graph()
{
	if(!select_for_wheel)
	{
	
		REP(i,Total_nodes)
		{
			REP(j,Total_nodes)
		    	adj_matrix[i][j]=0;
		
		list_edges[i].clear();
			
		}
	class_static_graph.Load_edges();
    class_static_graph.Load_nodes();
			
	}
	int first=0,last=0,flag=1;
	vector<int>vect_temp;
	REP(i,Total_nodes)if(i!=select_for_wheel) {vect_temp.push_back(i);}
	int size=vect_temp.size(),n1,n2;
	for(int j=0;j<size-1;j++)
	{
		n1=vect_temp[j]; n2=vect_temp[j+1];
		if(flag){first=n1; flag=0;}
		last=n2;
		COLOR_GREEN;
		connect(n2,n1,1);
		SWAPBUFFER;
		class_TIMER.wait(.7
		
		);
		
	
	}
	if(size>2)
	connect(first,last,1);
	REDISPLAY;
	mode_ring=0;
}


void align_nodes(list<int>list_nodes)
{
	list<int>::iterator it;
	 list_nodes.sort();
   int goleft=0,goup=0,godown=0;
   int pos[30][2],pos_2[30][2];
     for(int i=1;i<=29;i++)
     {
		 if((i-1)!=0 && (i-1)%8==0){goleft=0; goup+=80;}
		 pos[i][0]=70+goleft; pos[i][1]=80+goup;
		 goleft+=100;
		 
	 }
   goleft=0;
   for(int i=1;i<=29;i++)
   {
	   if((i-1)!=0 && (i-1)%8==0){goleft=0; godown+=80;}
	   pos_2[i][0]=70+goleft; pos_2[i][1]=HEIGHT-50-godown;
	   goleft+=100;
   }
   int cnt=1,tmap[50]={0};
   for(it=list_nodes.begin();it!=list_nodes.end();it++)
   {
	   tmap[*it]=1;
	   map_color[*it]=2;
   }
   REP(i,Total_nodes)if(!tmap[i]) map_color[i]=3;
   
   
   
    for(it=list_nodes.begin();it!=list_nodes.end();it++)
    {
		int front=*it;
		
		select_to_align=*it;
		move_around(front,pos[cnt][0],pos[cnt][1]);
		cnt++;
    }
    cnt=1;
    REP(i,Total_nodes)
    {
		
		if(!tmap[i])
		{
			move_around(i,pos_2[cnt][0],pos_2[cnt][1]);
			cnt++;
			
		}
		
	}
    select_to_align=0;
}


void bipartite_graph(list<int>list_nodes)
{
	list<int>::iterator it,it2;
	list<int>list_nodes2;
	list_nodes.sort();
	int tmap[50]={0};
	for(it=list_nodes.begin();it!=list_nodes.end();it++)
	{
		map_color[*it]=2;
		tmap[*it]=1;		
	}
	REP(i,Total_nodes)if(!tmap[i]) {list_nodes2.push_back(i); map_color[i]=3; }
     
    REP(i,Total_nodes) 
    {
		REP(j,Total_nodes)
		adj_matrix[i][j]=0;
		list_edges[i].clear();
	}
    class_static_graph.Load_edges();
    class_static_graph.Load_nodes();
			
     for(it=list_nodes.begin();it!=list_nodes.end();it++)
         for(it2=list_nodes2.begin();it2!=list_nodes2.end();it2++)
         {
			 COLOR_GREEN;
			 connect(*it,*it2,1);
			 			 
		 }
}

void wheel_graph(int center)
{
	REP(i,Total_nodes) 
    {
		REP(j,Total_nodes)
		adj_matrix[i][j]=0;
		list_edges[i].clear();
	}
    class_static_graph.Load_edges();
    class_static_graph.Load_nodes();
    REP(i,Total_nodes)
    {
		if(i==center) continue;
		COLOR_RED;
		SWAPBUFFER; class_TIMER.wait(.5);
	     connect(i,center,1);
			
	}
	SWAPBUFFER; class_TIMER.wait(.6);
	ring_graph();

}

};
Transform class_Transform;
