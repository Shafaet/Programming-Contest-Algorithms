class current_mouse
{
	public:
	int x,y;
		
};
current_mouse struct_MOUSEAT;

struct SQBUTTONS
{
	int upX,upY,downX,downY,id;
		
};

list<SQBUTTONS>list_sidebar_buttons;
list<SQBUTTONS>list_sidebar2_buttons;
list<SQBUTTONS>list_close_button;
list<SQBUTTONS>list_credits_button;
list<SQBUTTONS>list_files_button;
list<SQBUTTONS>list_colorbox_buttons;
list<SQBUTTONS>list_bipart_buttons;

list<int>list_connected_components[30];
list<int>list_edges[30];
int adj_matrix[100][100];
map<int,pair<int,int> >map_coordinate;
map<int,string>map_level;
vector<int>vect_path;

struct mst_min
{
	int u,v;
	int w;
	bool operator < ( const mst_min &b) const
	{
	return w<b.w;
	} 
};
vector<mst_min>mst_min_vect;
priority_queue<mst_min>mstmin_Q;


struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};
map<int,int>map_color;
map<int,int>clr;

list<int>list_bipart_nodes;

void clear_all()
{
	int i,j;
	map_coordinate.clear();
	for(i=0;i<30;i++)
	{
	 list_edges[i].clear();
	 list_connected_components[i].clear();
	}
	map_color.clear();
	map_level.clear();
		Total_nodes=0;
	for(i=0;i<100;i++) for(j=0;j<100;j++) adj_matrix[i][j]=0;
}

struct edges_mst{int x,y;};
vector<edges_mst>vect_mst;
vector<int>vect_eulerP;
