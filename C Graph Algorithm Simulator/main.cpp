#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<queue>
#include<ctime>
#include<GL/glut.h>
using namespace std;
#include "cgraph.h"


void display ()
{
	   
	LOAD_BACKGROUND();
	class_static_graph.Load_edges();
	class_static_graph.Load_nodes();
	
	
		
	
		if(!switch_infobar && !mode_write && !mode_read && !mode_credits)
		{   
			if(mode_complete) 	class_Transform.complete_graph(); 
			if(mode_ring) 	class_Transform.ring_graph(); 
		    if(mode_complement) complement_graph();
		    if(mode_optimal) optimal_color();
		    if(mode_bipart) bipart_info();
		    if(mode_wheel) wheel_info();
		    if(mode_bell) run_bellman();
		    if(mode_eulerP) run_eulerP();
		    if(mode_minspanning_tree)collect_minspan_info();
		    if(mode_term)switch_infobar=1;
			if(CONDITION_SIDEBAR1) {switch_sidebar=ON;SHOW_SIDEBAR();}
			else switch_sidebar=OFF;
			if(switch_sidebar==ON) SIDEBAR_FUNC();
			
			if(CONDITION_SIDEBAR2) {switch_sidebar2=ON;SHOW_SIDEBAR2();}
			else switch_sidebar2=OFF;
			if(switch_sidebar2==ON)   SIDEBAR2_FUNC();
			
			
			if(!mode_edge && !mode_addcost) RESET_SELECTION;
			if(mode_sssp) 	run_sssp();
			else if(mode_sssp_dij)		run_sssp_dij();
			else if(mode_spsp) {find_spsp();}
			else if(mode_union_find)run_union_find();
			else if(switch_sidebar==OFF && mode_vertex)	
			collect_node_info();
			else if(switch_sidebar==OFF && mode_edge )	
			collect_edge_info();
			else if(switch_sidebar==OFF && mode_movenode )
			move_the_nodes();
			else if(switch_sidebar==OFF && mode_addcost)
			collect_cost_info();
		    else if(switch_sidebar==OFF && mode_color)
		    {
			   color();
			}
	        else if(switch_sidebar==OFF && mode_level)
		    {
			   level();
			}
		}
		
		
		if(mode_credits) {show_credits();}
	    if(switch_infobar)
	    {
			if(mode_union_find) {info_dfs();}
			if(mode_sssp) {info_sssp();}
			if(mode_sssp_dij) {info_sssp_dij();}
			if(mode_minspanning_tree){info_mst();}
			if(mode_eulerP){info_euler();}
			if(mode_term){info_term();}
			if(mode_bell){info_bell();}
		}
		if(mode_write || mode_read)filebrowser();
	
	 
		
	
	
	glutSwapBuffers();
}


int main(int argc, char *argv[])
{

  	load_data();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("CGRAPH SIMULATOR");
	glutDisplayFunc(display);
	glutKeyboardFunc(graphicKeys);  
	glutPassiveMotionFunc(mouseMovement);
	glutMouseFunc(mouseAction);
	glutReshapeFunc(reshapeMainWindow);
	glutMainLoop();
	return 0;
}


