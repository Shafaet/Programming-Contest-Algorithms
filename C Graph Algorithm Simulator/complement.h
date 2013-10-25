void complement_graph()
{
	int copy_mat[100][100];
	REP(i,Total_nodes)
	 REP(j,Total_nodes)
	 {
	    copy_mat[i][j]=adj_matrix[i][j];			
	    adj_matrix[i][j]=0;
	 }
	
	REP(i,Total_nodes)
	{
		list_edges[i].clear();		
	}
	REP(i,Total_nodes)
	     REP(j,Total_nodes)
	     {
			 if(i==j) continue;
			 if(!copy_mat[i][j])
			 {
				 adj_matrix[i][j]=1;
				 list_edges[i].push_back(j);
			 }
			 
		 }
		 mode_complement=0;
		 glutPostRedisplay();
}
