void close_func()
{
	int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_close_button);
	value?COLOR_YELLOW:COLOR_GREEN;
	class_SHAPE.FILLED_RECT(WIDTH,HEIGHT,WIDTH-60,HEIGHT-20);
	COLOR_RED;
	class_SHAPE.TEXT(WIDTH-45,HEIGHT-13,"Close",font_small);
	if(signal_LMB)
	{
		value=0;
		value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_close_button);
		if(value) {mode_read=0;mode_write=0;}
	}
		
}

void loadfile(string str)
{
	clear_all();
	char fname[50];
	int N;
	strcpy(fname,str.c_str());
	strcat(fname,".gph");
	FILE *fp2=fopen(fname,"r");
	fscanf(fp2,"%d",&N);
	for(int i=1;i<=N;i++)
	{
		int x,y,clr;
		char lv[10];
		Total_nodes++;
		fscanf(fp2,"%d%d%d%s",&x,&y,&clr,lv);
		
		map_level[i]=lv;
		pair <int,int>temp=make_pair (x,y);
		map_coordinate[i]=temp;
		map_color[i]=clr;
		
	}
	REP(i,N)
	{
		REP(j,N)
		{
			fscanf(fp2,"%d",&adj_matrix[i][j]);
			if(adj_matrix[i][j])
			{
				list_edges[i].push_back(j);
		
			}
		}
		
		
	}
	fclose(fp2);
}

void createfile_and_writegraph(string str)
{
	char name[50];
	strcpy(name,str.c_str());
	strcat(name,".gph");
	FILE *fp=fopen(name,"w");
	fprintf(fp,"%d\n",Total_nodes);
	REP(i,Total_nodes)
	{
	   fprintf(fp,"%d %d %d ",map_coordinate[i].first,map_coordinate[i].second,map_color[i]);	
	   if(map_level[i]=="")
	   fprintf(fp,"%s\n","_");
	   else
	   fprintf(fp,"%s\n",map_level[i].c_str());
	}
	
	REP(i,Total_nodes)
	{
		REP(j,Total_nodes)
		{
		  fprintf(fp,"%d ",adj_matrix[i][j]);
		}
		fprintf(fp,"\n");
	}

	fclose(fp);
	string S;
	if(str!="Autosave")
	{
		S="The file "+str+" has been written successfully";
	
		MASSAGE_TEXT_BIG2(S);
		SWAPBUFFER;class_TIMER.wait(1);
	}

}
void filebrowser()
{
	COLOR_BLUE;
	class_SHAPE.FILLED_RECT(0,0,WIDTH,HEIGHT);
	close_func();
	string graphfiles[100];
	system("ls -1 > filelist");
     int Total_file=0;
	FILE *fp=fopen("filelist","r");


	char filename[50];
	while(fgets(filename,100,fp)!='\0')
	{
		
		int size=strlen(filename);
		if(size>3 && filename[size-2]=='h' && filename[size-3]=='p' && filename[size-4]=='g' && filename[size-5]=='.')
		{
			filename[size-5]='\0';
			graphfiles[++Total_file].assign(filename);
		}
				
	}
	fclose(fp);	
	list_files_button.clear();
	
	int SX=90,SY=600,goleft=0,godown=0;
	int add=0;
	if(mode_read) add=1;
	REP(i,Total_file+add)
	{
		
		SQBUTTONS temp;
		temp.downX=SX+goleft; temp.upX=SX+goleft+125; temp.downY=SY-godown; temp.upY=SY+40-godown; temp.id=i;
		list_files_button.push_back(temp);
		if(i%5==0){goleft=0; godown+=70;}
		else goleft+=145; 
		
	}
	MASSAGE_TEXT_BIG("Click on a file to load,Right click to delete");
	
	SX=90,SY=600,goleft=0,godown=0;
	REP(i,Total_file+add)
	{
		int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_files_button);
		(value==i && !freeze)==true? COLOR_YELLOW:COLOR_WHITE;
		
		
		class_SHAPE.FILLED_RECT(SX+goleft,SY-godown,SX+125+goleft,SY+40-godown); 
		
		COLOR_RED;
		if(i<=Total_file)
		class_SHAPE.TEXT(SX+goleft+5,SY+40-godown-15,graphfiles[i],font_small);
		else
			class_SHAPE.TEXT(SX+goleft+5,SY+40-godown-15,"Empty Slot",font_small);
			
		
		
		
		if(i%5==0){goleft=0; godown+=70;}
		else goleft+=145; 
	}
	if(signal_RMB)
	{
		
		int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_files_button);
		if(value)
		{
			char command[20];
			string temp="rm ";
			temp+=graphfiles[value]+".gph";
			strcpy(command,temp.c_str());
			system(command);
		}
	}
	
	if(signal_LMB)
	{
		signal_LMB=0;
	      if(mode_write)
	      {
			int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_files_button);
			if(value && value<=Total_file)
			{
				cout<<graphfiles[value]<<endl;
				loadfile(graphfiles[value]);
				mode_write=0;
			}
			if(value==Total_file+1)puts("empty slot");
			
		  }
		  if(mode_read)
		  {
			  int value=class_INFIGURE.RECT(struct_MOUSEAT.x,struct_MOUSEAT.y,list_files_button);
			  
				if(value && value<=Total_file)
				{
					string temp;
					temp.assign(graphfiles[value]);
					createfile_and_writegraph(temp);
					cout<<temp<<endl;
				}  
				else if(value==Total_file+1)
				{
					
					new_file_name.clear();
				    enter_name_now=Total_file+1;
				    freeze=1;
				}
 			  
		  }
	
	}
	
	
	 if(enter_name_now!=0)
	 {
					
	    SQBUTTONS slot=list_files_button.back();
		COLOR_RED;
		class_SHAPE.FILLED_RECT(slot.downX,slot.downY,slot.upX,slot.upY);
		
		if(signal_KEY)
		{
			signal_KEY=0;
			COLOR_YELLOW;
			if((inside('a',CHAR_PRESSED,'z') || inside('0',CHAR_PRESSED,'9') || inside('A',CHAR_PRESSED,'Z') || CHAR_PRESSED=='_') && new_file_name.size()<=15)
				new_file_name.push_back(CHAR_PRESSED);
			if(CHAR_PRESSED==BACKSPACE_KEY && new_file_name.size())
			{
				
				string::iterator it=new_file_name.end()-1;
					new_file_name.erase(it);
			}
			if(CHAR_PRESSED==ENTER_KEY)
			{
				
				freeze=0;
				enter_name_now=0;
				createfile_and_writegraph(new_file_name);
				glutPostRedisplay();
			}
			
		}
		class_SHAPE.TEXT(slot.downX+5,slot.upY-20,new_file_name,font_small);
	 }
	
	
}

void write_matlist()
{
	FILE *fp=fopen("Matrix_list","w");
	fprintf(fp,"Adjacency MATRIX:\n");
	REP(i,Total_nodes)
	{
	    REP(j,Total_nodes)
	    {
			fprintf(fp,"%d ",adj_matrix[i][j]);
			
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"Adjacency LIST:\n");
	REP(i,Total_nodes)
	{
		list<int>::iterator it;
		fprintf(fp,"%s >> ",fprint_level(i).c_str());
		for(it=list_edges[i].begin();it!=list_edges[i].end();it++)
		fprintf(fp,"%s ",fprint_level(*it).c_str());
		fprintf(fp,"\n");
		
	}
	fclose(fp);
	system("geany Matrix_list");
	
	
	
}
