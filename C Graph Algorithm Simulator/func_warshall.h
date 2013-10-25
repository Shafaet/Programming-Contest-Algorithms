void write_warshall()
{
	
	int mat[100][100];
	REP(i,Total_nodes)
	  REP(j,Total_nodes)
		{
			mat[i][j]=adj_matrix[i][j];
			if(!mat[i][j] && i!=j) mat[i][j]=INF;
		
		}
	
	REP(k,Total_nodes)
		REP(i,Total_nodes)
			REP(j,Total_nodes)
				if (mat[i][j]> mat[i][k]+mat[k][j])	mat[i][j]= mat[i][k]+mat[k][j];
	FILE *fp=fopen("Warshall_output","w");
	fprintf(fp,"Floyd Warshall Allpair shortest path Output:\n");
	REP(i,Total_nodes)
	{
	    REP(j,Total_nodes)
	    {
			fprintf(fp,"%d ",mat[i][j]);
			
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
					system("geany Warshall_output");
	
}
