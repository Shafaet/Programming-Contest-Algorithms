void path (int i, int j,int p[][100]) {
  if (i!=j)  
   path(i,p[i][j],p);
   vect_path.push_back(j);
  	
}
void RUN_WARSHALL(int src,int dest)
{
	vect_path.clear();
	int mat[100][100];
	int p[100][100];
	REP(i,Total_nodes)
	  REP(j,Total_nodes)
		{
			mat[i][j]=adj_matrix[i][j];
			if(!mat[i][j] && i!=j) mat[i][j]=INF;
		    
			p[i][j]=i;
		}
		
	REP(k,Total_nodes)
	REP(i,Total_nodes)
     REP(j,Total_nodes)
         if (mat[i][j]> mat[i][k]+mat[k][j])
          {
             mat[i][j]= mat[i][k]+mat[k][j];
             p[i][j]= p[k][j];               
          }   
         if(mat[src][dest]<INF)
         {
         path(src,dest,p);
         
     int size=vect_path.size();
     int prev=src;
     REP(i,size-1)
     {
		 
		 
		int x1=map_coordinate[prev].first;
		int y1=map_coordinate[prev].second;
				
		int x2=map_coordinate[vect_path[i]].first;
		int y2=map_coordinate[vect_path[i]].second;
		COLOR_GREEN;
		glLineWidth(2);
		class_SHAPE.animate_LINE(x1,y1,x2,y2);		
		 prev=vect_path[i];
	 }
		}
		else
		WARNING_TEXT("No Path");
	 SWAPBUFFER;
    class_TIMER.wait(2);
}



void find_spsp()
{

   if(signal_LMB)
   {
		  
		if(!select1_spsp)
		{
		
			select1_spsp=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
			
		}	
		else
		{
			select2_spsp=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
			if(select2_spsp)
			{
	
				RUN_WARSHALL(select1_spsp,select2_spsp);
				select1_spsp=0;
				select2_spsp=0;
				mode_spsp=0;
				
			}
			
			
		}	 
	}
	COLOR_RED;
	color_selected_node(select1_spsp);
		
}
