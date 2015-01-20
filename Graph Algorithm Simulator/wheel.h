void wheel_info()
{
	if(signal_LMB)
	{
		if(!select_for_wheel)
		{
			
			select_for_wheel=class_INFIGURE.Circle(struct_MOUSEAT.x,struct_MOUSEAT.y);
						
		}
		
		
	}
	if(select_for_wheel)
	{
		class_Transform.wheel_graph(select_for_wheel);
		
		select_for_wheel=0;
		mode_wheel=0;
		
	}
	else MASSAGE_TEXT_BIG("Select The center of the wheel");
		
}
