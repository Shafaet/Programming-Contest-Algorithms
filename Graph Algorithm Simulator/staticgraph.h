void write_number(int temp,int H,int K)
{
	COLOR_RED;
	char buffer[5];
	sprintf(buffer,"%d",temp);
	if(map_level[temp]!="" && map_level[temp]!="_")
	class_SHAPE.TEXT(H-14,K-15,map_level[temp],font_small);
	else
	class_SHAPE.TEXT(H-14,K-14,buffer,font_small);
}

void write_dist(int temp,int n)
{
  int H=map_coordinate[n].first;
  int K=map_coordinate[n].second;
	char buffer1[10],buffer2[10];
	strcpy(buffer1,"(");
	if(temp==inf)
	strcpy(buffer2,"inf");
	else
	sprintf(buffer2,"%d",temp);
	strcat(buffer1,buffer2);
	strcat(buffer1,")");
	if(mode_bell)
	{
		strcat(buffer1,"[u-");
		sprintf(buffer2,"%d",upd_bell[n]);
		strcat(buffer1,buffer2);
		strcat(buffer1,"]");
	}
	
	class_SHAPE.TEXT(H+14,K+14,buffer1,font_small);
}

void write_cost(int x1,int y1,int x2,int y2,int ecost)
{
	
	
	int midx1=(x1+x2)/2;
	int midy1=(y1+y2)/2;
	int expand=0;
	char buffer[16]="\0";
	
	sprintf(buffer,"%d",ecost);
	COLOR_WHITE;
	int size=strlen(buffer);
	expand=size*5;
	class_SHAPE.FILLED_RECT(midx1-5,midy1-5,midx1+7+expand,midy1+9);
	COLOR_RED;
	class_SHAPE.TEXT(midx1,midy1,buffer,font_small);
	
		
}

class static_graph
{
	public:
	void Load_nodes()
	{
	

		int node_num=1;
		map<int,pair<int,int> >::iterator mit;
					
		for(mit=map_coordinate.begin();mit!=map_coordinate.end();mit++)
		{
			int clr=map_color[node_num];
			if(mode_sssp_dij || mode_union_find || mode_sssp)COLOR_WHITE;
			else
			COLOR_CHOICE(clr);
			
			int H=(*mit).second.first;
			int K=(*mit).second.second;
			if(select_for_move!=node_num)
			{
				
				class_SHAPE.FILLEDCIRCLE(H,K,default_radius);
				write_number((*mit).first,H,K);
			}
			if(sssp_static) 
			{
				write_dist(sssp_dis[node_num],node_num);
				
			}
			node_num++;
		}
	}
	void Load_edges()
	{
		list<int>::iterator it;
		if(mode_bipart || mode_wheel || mode_ring)
		{	
			COLOR_BLACK;
			class_SHAPE.FILLED_RECT(WIDTH-15,HEIGHT,15,51);
		}

		for(int i=1;i<=Total_nodes;i++)
		{
			int x1=map_coordinate[i].first;
			int y1=map_coordinate[i].second;
			for(it=list_edges[i].begin();it!=list_edges[i].end();it++)
			{
				int x2=map_coordinate[*it].first;
				int y2=map_coordinate[*it].second;
				COLOR_BLUE;
				class_SHAPE.LINE(x1,y1,x2,y2);
				int ecost=adj_matrix[i][*it];
				if(show_cost)
				write_cost(x1,y1,x2,y2,ecost);
				
			}
						
		}
	}

};
static_graph class_static_graph;
