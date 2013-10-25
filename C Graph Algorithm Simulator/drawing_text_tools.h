class shapes
{
	public:
	void LINE(int x1,int y1,int x2,int y2)
	{
		glBegin(GL_LINE_STRIP);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();
	
	}
	
	void FILLEDCIRCLE(int H,int K,int r)
	{        
			glBegin(GL_LINE_LOOP);
			for(int rr=1;rr<r;rr++)
				for(int angle=0;angle<=360;angle++)
				 glVertex2f(H+ sin(angle) * rr, K + cos(angle) * rr);
				glEnd();
	}
	
	void FILLED_RECT(int downx,int downy,int upx,int upy)
	{
		glBegin(GL_QUADS);
		glVertex2f(downx,downy);
		glVertex2f(upx,downy);
		glVertex2f(upx,upy);
		glVertex2f(downx,upy);
		glEnd();
				
		
	}
		
	void RECT(int downx,int downy,int upx,int upy)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(downx,downy);
		glVertex2f(upx,downy);
		glVertex2f(upx,upy);
		glVertex2f(downx,upy);
		glVertex2f(downx,downy);
		glEnd();
				
		
	}
	void TEXT(int tx,int ty,string s,void *font)
	{
		glRasterPos2i(tx,ty);
		for (string::iterator i = s.begin(); i != s.end(); ++i)
		glutBitmapCharacter(font, *i);
		
	}
    void animate_LINE(double x1,double y1,double x2,double y2)
    {
		
		double threshold=fabs((x1-x2)/50);
		double px=x1,py;
		if(fabs(x1-x2)<1e-8) 
		{
			threshold=fabs((y1-y2)/50);
			py=y1;
			while(1)
			{
				if(y2>y1) py+=threshold;
				else py-=threshold;
				glBegin(GL_LINE_STRIP);
				glVertex2f(x1+eps,y1+eps);
				glVertex2f(px+eps,py+eps);
				glEnd();
				glutSwapBuffers();
				class_TIMER.animator_line();
				if(y2<y1){if(py<x2 || fabs(py-y2)<1e-11) break;}
				if(y2>y1){if(py>y2 || fabs(py-y2)<1e-11) break;}
			}
	         
		}
		else
		{
			while(1)
			{
	
			py=(px*(y1-y2)+(x1*y2)-(x2*y1))/(x1-x2);
			if(x2<x1) px-=threshold;
			if(x2>x1) px+=threshold;
			glBegin(GL_LINE_STRIP);
			glVertex2f(x1,y1);
			glVertex2f(px,py);
			glEnd();
			glutSwapBuffers();
			
			class_TIMER.animator_line();
			if(x2<x1){if(px<x2 || fabs(px-x2)<1e-11) break;}
			if(x2>x1){if(px>x2 || fabs(px-x2)<1e-11) break;}
			}
		}
			
	}
};

shapes class_SHAPE;


void WARNING_TEXT(string str)
{
	
	COLOR_RED;class_SHAPE.TEXT(60,35,str,font_small); glutSwapBuffers();class_TIMER.wait(1);
}
void MASSAGE_TEXT(string str){	COLOR_YELLOW;  class_SHAPE.TEXT(60,10,str,font_small);}
void MASSAGE_TEXT_BIG(string str){	COLOR_YELLOW;  class_SHAPE.TEXT(60,10,str,font_large);}

void MASSAGE_TEXT_BIG2(string str){	COLOR_GREEN;  class_SHAPE.TEXT(60,35,str,font_large);}

void REMOVE_MASSAGE_TEXT_BIG(string str){	COLOR_BLACK;  class_SHAPE.TEXT(60,10,str,font_large);}
void REMOVE_MASSAGE_TEXT_BIG2(string str){	COLOR_BLACK;  class_SHAPE.TEXT(60,35,str,font_large);}

void REMOVE_MASSAGE_TEXT(string str){	COLOR_BLACK;    class_SHAPE.TEXT(60,10,str,font_small);}
void INFO_TEXT(string str){	COLOR_GREEN;class_SHAPE.TEXT(60,35,str,font_small); glutSwapBuffers();class_TIMER.wait(.5);}
void REMOVE_WARNING_INFO_TEXT(string str)
{
	
	COLOR_BLACK;class_SHAPE.TEXT(60,35,str,font_small); glutSwapBuffers();class_TIMER.wait(1);
}
void color_selected_node(int node)
{
	if(!node)return;
	map<int,pair<int,int> >::iterator mit;
	int node_num=1;
	
		for(mit=map_coordinate.begin();mit!=map_coordinate.end();mit++)
		{
			if(node_num==node)
			{
				
				int H=(*mit).second.first;
				int K=(*mit).second.second;
				class_SHAPE.FILLEDCIRCLE(H,K,default_radius);
				break;
			}
		    node_num++;
		}
		

}

string fprint_level(int n)
{
	char lv[20];
	if(map_level[n]=="" ||map_level[n]=="_")
	{
		sprintf(lv,"%d",n);
		return lv;
		
	}
	return map_level[n];
}
string fprint_dist(int d)
{
	char temp[10];
	if(d>=INF) return "infinity";
	sprintf(temp,"%d",d);
	return temp;
	
}
