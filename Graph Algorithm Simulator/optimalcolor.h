void colorit(int src,int*vis)
{
	list<int>::iterator it;
	for(it=list_edges[src].begin();it!=list_edges[src].end();it++)
	{
		
		if(!vis[*it] && !clr[*it])
		{
	        list<int>::iterator mit;		
	        int tmp[10]={0};
	        for(mit=list_edges[*it].begin();mit!=list_edges[*it].end();mit++)
	        {
				if(*it==*mit)break;
			    tmp[clr[*mit]]=1;
							
			}
			for(int i=2;i<=14;i++)if(!tmp[i]){clr[*it]=i; break;}
			
			vis[*it]=1;
			colorit(*it,vis);
			
		}
		
	}
	
}

void optimal_color()
{
	clr.clear();
	
	int vis[100]={0};
	REP(i,Total_nodes)
	{
		if(!vis[i])
		{
			clr[i]=2;
			vis[i]=1;
			colorit(i,vis);
		}
	}
	map_color=clr;
	mode_optimal=0;
	REDISPLAY
}
