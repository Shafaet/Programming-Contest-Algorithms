class point_in_figures{
public:

	int RECT(int x,int y,list<SQBUTTONS>buttons)
	{
		list<SQBUTTONS>::iterator it;
		for(it=buttons.begin();it!=buttons.end();it++)
				if(x>(*it).downX && x<(*it).upX && y>(*it).downY && y<(*it).upY)   return (*it).id;
		
		return 0;
	}
	int Circle(int x,int y)
	{
		
		int temp=1;
		map<int,pair<int,int> >::iterator mit;
		
		for(mit=map_coordinate.begin();mit!=map_coordinate.end();mit++)
		 {
			 	int H=(*mit).second.first;
				int K=(*mit).second.second;
			    int dist=(x-H)*(x-H)+(y-K)*(y-K);
		    	if(dist<=default_radius*default_radius)return temp;
		    	temp++;
		
		 }
		 return 0;
	}
};

point_in_figures class_INFIGURE;
