
void SIDEBAR_FUNC()
{
	RESET_mouse_on
	int value=0;
	value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_sidebar_buttons);

	if(value==sidebar_edge_button)
	mouse_on_Edge_button=1;
	if(value==sidebar_vertex_button) mouse_on_Vertex_button=1;
	if(value==sidebar_movenode_button) mouse_on_movenode_button=1;
	if(value==sidebar_addcost_button) mouse_on_addcost_button=1;
	if(value==sidebar_write_button) mouse_on_write_button=1;
	if(value==sidebar_clear_button) mouse_on_clear_button=1;
	if(value==sidebar_read_button) mouse_on_read_button=1;
	if(value==sidebar_color_button) mouse_on_color_button=1;
	if(value==sidebar_level_button) mouse_on_level_button=1;
	
	if(signal_LMB)	
	{
       value=0;		
       value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_sidebar_buttons);
       if(value) RESET_BAR_MODES;
       if(value==sidebar_edge_button) mode_edge=1; 
       if(value==sidebar_vertex_button) mode_vertex=1; 
       if(value==sidebar_movenode_button) mode_movenode=1; 
       if(value==sidebar_addcost_button) mode_addcost=1; 
       if(value==sidebar_write_button) {switch_sidebar=OFF;mode_write=1; }
       if(value==sidebar_read_button) {switch_sidebar=OFF;enter_name_now=0;mode_read=1; }
       if(value==sidebar_color_button) {switch_sidebar=OFF;mode_color=1; }
       if(value==sidebar_level_button) {switch_sidebar=OFF;mode_level=1; }
       if(value==sidebar_clear_button) clear_all();
       signal_LMB=0;
	}

}


void SHOW_SIDEBAR()
{
	
	COLOR_RED;
	class_SHAPE.FILLED_RECT(0,0,const_margin_sidebar,HEIGHT);
	
	COLOR_BLACK;
	class_SHAPE.TEXT(30,HEIGHT-20,"CGRAPH",font_large);
	class_SHAPE.TEXT(10,HEIGHT-40,"SIMULATOR",font_large);
	
	(mouse_on_Edge_button || mode_edge)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,60-15,110,100-15); //edge_button
	
	(mouse_on_Vertex_button || mode_vertex)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,120-15,110,160-15); //vertex_button
	
	(mouse_on_movenode_button || mode_movenode)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180-15,110,220-15); //vertex_button
	
	(mouse_on_addcost_button || mode_addcost)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180+60-15,110,220+60-15);
	
	(mouse_on_write_button || mode_write)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180+60+60-15,110,220+60+60-15);
	(mouse_on_clear_button )==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180+60+60+60-15,110,220+60+60+60-15);
	(mouse_on_read_button || mode_write)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180+60+60+60+60-15,110,220+60+60+60+60-15);
	(mouse_on_color_button || mode_color)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180+120+120+60-15,110,220+240+60-15);
	(mouse_on_level_button || mode_level)==true? COLOR_YELLOW:COLOR_WHITE;
	class_SHAPE.FILLED_RECT(22,180+120+120+60+60-15,110,220+240+60+60-15);
	
	COLOR_RED;
	class_SHAPE.TEXT(30,80-15,"Edge Mode",font_small);
	class_SHAPE.TEXT(30,140-15,"Vertex Mode",font_small);
	class_SHAPE.TEXT(30,200-15,"Move Node",font_small);
	class_SHAPE.TEXT(30,260-15,"Update Cost",font_small);
	class_SHAPE.TEXT(30,320-15,"Load Graph",font_small);
	class_SHAPE.TEXT(30,380-15,"Clear All",font_small);
	class_SHAPE.TEXT(30,440-15,"Save Graph",font_small);
	class_SHAPE.TEXT(30,500-15,"Node Color",font_small);
	class_SHAPE.TEXT(30,560-15,"Node Level",font_small);
}

