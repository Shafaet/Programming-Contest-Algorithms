bool switch_sidebar;
bool switch_sidebar2;
bool switch_infobar; 

int const sidebar_edge_button = 1;
int const sidebar_vertex_button = 2;
int const sidebar_movenode_button = 3;
int const sidebar_addcost_button = 4;
int const sidebar_write_button = 5;
int const sidebar_clear_button = 6;
int const sidebar_read_button = 7;
int const sidebar_color_button = 8;
int const sidebar_level_button = 9;

int const sidebar2_unionfind_button = 1;
int const sidebar2_sssp_button = 2;
int const sidebar2_togglecost_button = 3;
int const sidebar2_minspanning_tree_button = 4;
int const sidebar2_sssp_dij_button = 5;
int const sidebar2_bipart_button = 6;
int const sidebar2_Eulerpath_button = 7;
int const sidebar2_term_button = 8;

int const sidebar2_spsp_button=10;
int const sidebar2_complete_button=11;
int const sidebar2_complement_button=12;
int const sidebar2_optimal_button=13;
int const sidebar2_ring_button=14;
int const sidebar2_wheel_button=15;
int const sidebar2_bell_button=16;
int const sidebar2_matlist_button=17;
int const sidebar2_warshall_button=18;

int const button_Close=1;
int const button_Copy=2;
int const button_Remove=3;
int const button_Credits=1;

int const bipart_move=1;
int const bipart_nomove=2;
bool mode_vertex;
bool mode_edge;
bool mode_movenode;
bool mode_addcost;
bool mode_write;
bool mode_read;
bool mode_color;
bool mode_level;
bool mode_complement;
bool mode_credits;



#define RESET_BAR_MODES mode_vertex=0; mode_edge=0,mode_movenode=0,mode_addcost=0,mode_write=0,mode_color=0,mode_level=0,mode_credits=0;

bool mode_union_find;
bool mode_sssp;
bool mode_minspanning_tree;
bool mode_sssp_dij;
bool mode_spsp;
bool mode_complete;
bool mode_ring;
bool mode_optimal;
bool mode_bipart;
bool mode_wheel;
bool mode_bell;
bool mode_union=0;
bool mode_eulerP=0;
bool mode_term=0;
#define RESET_PANEL_MODES mode_union_find=0,mode_sssp=0,mode_minspanning_tree=0,mode_sssp_dij=0,mode_spsp=0,mode_complete=0,mode_optimal=0,mode_complement=0,mode_ring=0,mode_bipart=0,mode_bell=0,mode_union=0,mode_eulerP=0,mode_term=0;



int signal_LMB,signal_RMB;
int signal_KEY;
#define RESET_signal_MOUSE signal_LMB=0,signal_RMB=0;

int mouse_on_Edge_button=0;
int mouse_on_Vertex_button=0;
int mouse_on_movenode_button=0;
int mouse_on_addcost_button=0;
int mouse_on_write_button=0;
int mouse_on_clear_button=0;
int mouse_on_read_button=0;
int mouse_on_color_button=0;
int mouse_on_level_button=0;
#define RESET_mouse_on mouse_on_Edge_button=0; mouse_on_Vertex_button=0,mouse_on_movenode_button=0,mouse_on_addcost_button=0,mouse_on_write_button=0,mouse_on_clear_button=0,mouse_on_read_button=0,mouse_on_color_button=0,mouse_on_level_button=0;;
#define COMMONS1 switch_sidebar2=OFF; switch_sidebar=OFF; RESET_BAR_MODES;
int select_1=0;
int select_2=0;
#define RESET_SELECTION select_1=0,select_2=0,freeze=0;
int select_for_move=0;
int select_for_color=0;
int select_for_level=0;
int select_to_align=0;
int select_for_wheel=0;
int select1_spsp=0;
int select2_spsp=0;
int Total_nodes=0;
int mouse_sensor_sidebar2=0;

//dfs_info
int Largest_union=0;
int looper=0;

///sssp info
int source_sssp;
int sssp_dis[30]={0};

int sssp_static=0;
int freeze=0;

int source_sssp_dij;
int sssp_dis_dij[30]={0};
int sssp_static_dij=0;

char CHAR_PRESSED=0;
string input_cost;
string new_file_name;
string new_level;
int show_cost=0;
int upd_bell[30]={0};
int enter_name_now=0;
#define TEST REP(i,3)printf("%d ",i); puts("");
int spanning_cost=0;
int Negative_cycle=1;
int mode_delete=0;
