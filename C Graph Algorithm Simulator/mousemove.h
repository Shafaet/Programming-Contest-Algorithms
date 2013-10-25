void mouseAction(int button, int state, int x, int z)
{
	if(freeze) return;
	
		if(button==GLUT_LEFT_BUTTON)
		{
			if (state == GLUT_DOWN)
			{
		       signal_LMB=1;
		       glutPostRedisplay();	 
			}
			if(state==GLUT_UP)
			{

				RESET_signal_MOUSE
				glutPostRedisplay();	 
			}
		}
			if(button==GLUT_RIGHT_BUTTON)
		{
			if (state == GLUT_DOWN)
			{
		       signal_RMB=1;
		       glutPostRedisplay();	 
			}
			if(state==GLUT_UP)
			{
				RESET_signal_MOUSE
				//glutPostRedisplay();	 
			}
				
	}
}

void mouseMovement(int mx, int my)
{

	struct_MOUSEAT.x=mx;
	struct_MOUSEAT.y=HEIGHT-my;
	if(!freeze)
	glutPostRedisplay();
}
