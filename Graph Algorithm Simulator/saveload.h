void save_graph()
{
	FILE *fp=fopen("out","w");
	REP(i,Total_nodes)
	{
	 fprintf(fp,"%6d  %6d  %6d\n",i,map_coordinate[i].first,map_coordinate[i].second);
	}
	fprintf(fp,"\n\n");
	REP(i,Total_nodes)
	{
	    REP(j,Total_nodes)
	    {
			fprintf(fp,"%d  ",adj_matrix[i][j]);
		}
	  fprintf(fp,"\n");
	}
	fclose(fp);
	
}

