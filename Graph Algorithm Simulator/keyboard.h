void graphicKeys (unsigned char key, int x, int y)
{
  
	 if(freeze)
	 {
		 signal_KEY=1;
		 CHAR_PRESSED=key;
		 	glutPostRedisplay();
	 }
	 
}
