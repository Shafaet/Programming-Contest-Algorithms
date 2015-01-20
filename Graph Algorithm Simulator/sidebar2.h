void SIDEBAR2_FUNC()
{
	COLOR_RED;
	class_SHAPE.TEXT(const_margin_sidebar2+80,HEIGHT-30,"Control Panel",font_large);
	RESET_mouse_on
	int value=0;
	value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_sidebar2_buttons);
	mouse_sensor_sidebar2=value;
	if(signal_LMB)	
	{
		signal_LMB=0;
		value=0;
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_credits_button);
		if(value)
		{
		    COMMONS1
			mode_credits=1;
					
		}
		
		else
		{
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_sidebar2_buttons);
		if(value) RESET_PANEL_MODES;
			if(value && (!Total_nodes && value!=sidebar2_term_button))
			{
			WARNING_TEXT("WARNING::NO GRAPH DETECTED");
			SWAPBUFFER
			class_TIMER.wait(.3);
			}
		else
		{
		if(value==sidebar2_unionfind_button)
		{
			mode_union_find=1;
			COMMONS1
			
			
			glutSwapBuffers();
			
		}
		if(value==sidebar2_sssp_button)
		{
			
			source_sssp=0;
			COMMONS1
			mode_sssp=1;
		
		}
		if(value==sidebar2_togglecost_button)
		{
			
			show_cost=!show_cost;
		}
		if(value==sidebar2_minspanning_tree_button)
		{
			COMMONS1
			mode_minspanning_tree=1;
		}
		if(value==sidebar2_sssp_dij_button)
		{
		
		  source_sssp_dij=0;
		  COMMONS1
		  mode_sssp_dij=ON;
			
			
		}
		if(value==sidebar2_spsp_button)
		{
			COMMONS1
			select1_spsp=0;
			select2_spsp=0;
			
			mode_spsp=ON;
			
		}
		if(value==sidebar2_complete_button)
		{
			COMMONS1
		    mode_complete=ON;
			
		}
		if(value==sidebar2_complement_button)
		{
			COMMONS1
		    mode_complement=ON;
			
		}
		if(value==sidebar2_optimal_button)
		{
		    COMMONS1	
		   mode_optimal=ON;	
		}
		if(value==sidebar2_ring_button)
		{
			COMMONS1	
		   mode_ring=ON;	
			
		}
		if(value==sidebar2_bipart_button)
		{
			COMMONS1	
			list_bipart_nodes.clear();
		   mode_bipart=ON;	
			
		}
		if(value==sidebar2_wheel_button)
		{			
			COMMONS1;
			mode_wheel=1;
		}
		if(value==sidebar2_bell_button)
		{
			COMMONS1;
			mode_bell=1;
		}
	    if(value==sidebar2_Eulerpath_button)
	    {
			COMMONS1;
			mode_eulerP=1;
		}
		if(value==sidebar2_term_button)
		{
			COMMONS1;
			mode_term=1;
			
		}
		if(value==sidebar2_matlist_button)
		{
			//puts("SS");
			write_matlist();
			
		}
		if(value==sidebar2_warshall_button)
		{
			write_warshall();
		}
	}
}
   }
}


void sidebar2_buttons_left()
{
	int goup=0;
	COLOR_WHITE;
	string S[10];
	S[1].assign("DFS Union Find");
	S[2].assign("BFS SSSP");
	S[3].assign("Show Cost");
	if(show_cost) S[3]+="(Turn off)";
	else S[3]+="(Turn on)";
	S[4].assign("Kruskta MST(min)");
	S[5].assign("Dijikstra SSSP");
	S[6].assign("Make Complete Bipartite");
	S[7].assign("Find Euler Path+Circuit");
	S[8].assign("TERMINOLOGY");
	
	REP(i,9)
	{
		if(i==mouse_sensor_sidebar2)COLOR_YELLOW;
		else COLOR_WHITE;
		class_SHAPE.FILLED_RECT(const_margin_sidebar2+10,80+goup,const_margin_sidebar2+135,120+goup); 
		if(S[i].size()) {COLOR_RED; class_SHAPE.TEXT(const_margin_sidebar2+15,80+goup+20,S[i],font_small);}
		goup+=60;
	}
}



void sidebar2_buttons_right()
{
	string S[10];
	S[1].assign("Single pair shortest path");
	S[2].assign("Make Complete Graph");
	S[3].assign("Complement Graph");
	S[4].assign("Optimal Coloring");
	S[5].assign("Make Ring");
	S[6].assign("Make Wheel");
	S[7].assign("Bellman ford");
    S[8].assign("Get Matrix and List");
    S[8].assign("Floyd Warshall Output");
	int goup=0;
	COLOR_WHITE;
	REP(i,9)
	{
		if(i+9==mouse_sensor_sidebar2)COLOR_YELLOW;
		else COLOR_WHITE;
		class_SHAPE.FILLED_RECT(const_margin_sidebar2+165,80+goup,const_margin_sidebar2+290,120+goup); 
		if(S[i].size()) {COLOR_RED; class_SHAPE.TEXT(const_margin_sidebar2+170,80+goup+20,S[i],font_small);}
		goup+=60;
	}
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_credits_button);
	value?COLOR_YELLOW:COLOR_BROWN;
	
	class_SHAPE.FILLED_RECT(WIDTH,0,WIDTH-60,20);
	COLOR_RED;
	class_SHAPE.TEXT(WIDTH-45,9,"Credits",font_small);
}


void SHOW_SIDEBAR2()
{
	
	COLOR_BLUE;
	class_SHAPE.FILLED_RECT(WIDTH,0,const_margin_sidebar2,HEIGHT);
	sidebar2_buttons_left();
	sidebar2_buttons_right();
	
}
