void load_data(void)
{
	SQBUTTONS temp;
	
	temp.downX=22; temp.downY=60-15; temp.upX=110; temp.upY=100-15; temp.id=sidebar_edge_button;
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=120-15; temp.upX=110; temp.upY=160-15; temp.id=sidebar_vertex_button; 
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180-15; temp.upX=110; temp.upY=220-15; temp.id=sidebar_movenode_button; 
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180+60-15; temp.upX=110; temp.upY=220+60-15;   temp.id=sidebar_addcost_button;
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180+60+60-15; temp.upX=110; temp.upY=220+60+60-15;   temp.id=sidebar_write_button;
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180+60+60+60-15; temp.upX=110; temp.upY=220+60+60+60-15;   temp.id=sidebar_clear_button;
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180+60+60+60+60-15; temp.upX=110; temp.upY=220+60+60+60+60-15;   temp.id=sidebar_read_button;
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180+60+60+60+60+60-15; temp.upX=110; temp.upY=220+60+60+60+60+60-15;   temp.id=sidebar_color_button;
	list_sidebar_buttons.push_back(temp);
	temp.downX=22; temp.downY=180+60+60+60+60+60+60-15; temp.upX=110; temp.upY=220+60+60+60+60+60+60-15;   temp.id=sidebar_level_button;
	list_sidebar_buttons.push_back(temp);
	int goup=0,godown=0;
	REP(i,9)
	{
		temp.downX=const_margin_sidebar2+10; temp.downY=80+goup; temp.upX=const_margin_sidebar2+135; temp.upY=120+goup; 
		temp.id=i; 
		list_sidebar2_buttons.push_back(temp);
		goup+=60;
	}
	goup=0;
	REP(i,9)
	{
		
		temp.downX=const_margin_sidebar2+165; temp.downY=80+goup; temp.upX=const_margin_sidebar2+290; temp.upY=120+goup; 
		temp.id=i+9; 
		list_sidebar2_buttons.push_back(temp);
		goup+=60;
	}
	temp.downX=WIDTH-50; temp.downY=HEIGHT-20; temp.upX=WIDTH; temp.upY=HEIGHT;  temp.id=button_Close;
	list_close_button.push_back(temp);
	temp.downX=WIDTH-140; temp.downY=HEIGHT-20; temp.upX=WIDTH-100; temp.upY=HEIGHT;  temp.id=button_Copy;
	list_close_button.push_back(temp);
	temp.downX=WIDTH-400; temp.downY=HEIGHT-20; temp.upX=WIDTH-290; temp.upY=HEIGHT;  temp.id=button_Remove;
	list_close_button.push_back(temp);
		
	
	temp.downX=WIDTH-60; temp.downY=0; temp.upX=WIDTH; temp.upY=20;  temp.id=1;
	list_credits_button.push_back(temp);
	godown=0;
	REP(i,5)
	{
		
		temp.downX=WIDTH-110;
		temp.downY=HEIGHT-60-godown;
		temp.upX=WIDTH-10;
		temp.upY=HEIGHT-20-godown;
		temp.id=i;
		list_colorbox_buttons.push_back(temp);
		godown+=50;
		
		
	}
	
	temp.downX=WIDTH-160; temp.downY=HEIGHT-20; temp.upX=WIDTH-40; temp.upY=HEIGHT;   temp.id=2;
	list_bipart_buttons.push_back(temp);
	temp.downX=WIDTH-270; temp.downY=HEIGHT-20; temp.upX=WIDTH-190; temp.upY=HEIGHT;   temp.id=1;
	list_bipart_buttons.push_back(temp);
			
}
