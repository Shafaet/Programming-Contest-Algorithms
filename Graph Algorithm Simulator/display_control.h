int WIDTH = 900;
int HEIGHT = 700;
int width  = WIDTH;
int height = HEIGHT;
void reshapeMainWindow (int newWidth, int newHeight)
{  
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0, newWidth, 0, newHeight, 0, 1 );
	glViewport( 0, 0, newWidth, newHeight );
	WIDTH = newWidth;
	HEIGHT = newHeight;
    glMatrixMode(GL_MODELVIEW); 
	glutPostRedisplay();
}

int const const_margin_sidebar = 130;
int const const_margin_sidebar2 = WIDTH-300;
