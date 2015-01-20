void justkeep_mst()
{
	REP(i,Total_nodes)
	{
		REP(j,Total_nodes)
	    	adj_matrix[i][j]=0;
		
		list_edges[i].clear();
			
	}
	vector<edges_mst>::iterator it;
	for(it=vect_mst.begin();it<vect_mst.end();it++)
	{
		connect((*it).x,(*it).y,1);
	}
	
	
}
void draw_infobar()
	{
		int value=0;
		COLOR_GREEN;
		
		class_static_graph.Load_nodes();
			
		//COLOR_GREEN;
		//class_SHAPE.FILLED_RECT(WIDTH,HEIGHT-30,WIDTH-150,HEIGHT);
			
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_close_button);
		(value==1)?COLOR_YELLOW:COLOR_BLUE;
		class_SHAPE.FILLED_RECT(WIDTH,HEIGHT,WIDTH-50,HEIGHT-20);
		COLOR_RED;
		class_SHAPE.TEXT(WIDTH-45,HEIGHT-13,"Close",font_small);
	    (value==2)?COLOR_YELLOW:COLOR_BLUE;
	    class_SHAPE.FILLED_RECT(WIDTH-100,HEIGHT,WIDTH-140,HEIGHT-20);
	    COLOR_RED;
		class_SHAPE.TEXT(WIDTH-135,HEIGHT-13,"Details",font_small);
	    if(mode_minspanning_tree)
	    {
			(value==3)?COLOR_YELLOW:COLOR_BLUE;
			class_SHAPE.FILLED_RECT(WIDTH-290,HEIGHT,WIDTH-400,HEIGHT-20);
			COLOR_RED;
			class_SHAPE.TEXT(WIDTH-397,HEIGHT-13,"Remove other edges",font_small);
		}
	    //printf("%d\n",signal_LMB);
		if(signal_LMB)
		{
			value=0;
			value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_close_button);
		    if(mode_minspanning_tree && value==button_Remove) {justkeep_mst(); }
		    if(value==button_Copy)   {system("geany details");}
			
			if(value==button_Close){RESET_PANEL_MODES; switch_infobar=0; REMOVE_WARNING_INFO_TEXT("DONE!!");}
		}
		
	}
	

void info_dfs()
{
	
	draw_infobar();
	
	
}

void info_sssp()
{
	sssp_static=1;
	draw_infobar();
	sssp_static=0;
}

void info_sssp_dij()
{
	REP(i,Total_nodes) 
	{
		write_dist(sssp_dis_dij[i],i);
				
	}
	draw_infobar();
		
}
void info_mst()
{
	char buffer1[60],buffer2[60];
	strcpy(buffer1,"The Cost of Minimum Spanning Tree is ");
	sprintf(buffer2,"%d",spanning_cost);
	strcat(buffer1,buffer2);
	MASSAGE_TEXT_BIG(buffer1);
	vector<edges_mst>::iterator it;
	for(it=vect_mst.begin();it<vect_mst.end();it++)
	{
		connect((*it).x,(*it).y,1);
	}
	draw_infobar();
}
void info_euler()
{
	MASSAGE_TEXT("OUTPUT IS WRITTEN TO DETAILS FILE,CLICK THE BUTTON ABOVE TO SEE IT");
	draw_infobar();
}

void info_term()
{
	show_terms();
	
	draw_infobar();
}
void info_bell()
{
	FILE *fp=fopen("details","w");
	if(Negative_cycle)
	fprintf(fp,"Negative Cycle Exists!!\n");
	else fprintf(fp,"No Negative Cycle\n");
	fclose(fp);
	draw_infobar();
}
