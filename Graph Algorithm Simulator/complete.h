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
		  adj_matrix[i][j]=1;
		  adj_matrix[j][i]=1;
		  list_edges[i].push_back(j);
		  list_edges[j].push_back(i);
		  int x1=map_coordinate[i].first;
		  int y1=map_coordinate[i].second;
			flag=1;	
		  int x2=map_coordinate[j].first;
		  int y2=map_coordinate[j].second;
		  COLOR_BLUE;
		  class_SHAPE.animate_LINE(x1,y1,x2,y2);	
	  }
  }
  if(!flag)
  {
	  COLOR_RED;
	  class_SHAPE.TEXT(60,35,"Warning!!: The Graph is already Complete",font_small);
	  glutSwapBuffers();
	  class_TIMER.wait(1.5);
  }
	mode_complete=0;
}

};
Transform class_Transform;

