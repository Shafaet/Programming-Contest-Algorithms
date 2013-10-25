#define inf 999999
#define INF 999999
#define eps 1e-8
#define REP(i,n) for(int i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
#define ON true
#define OFF false
#define font_small GLUT_BITMAP_HELVETICA_10
#define font_large GLUT_BITMAP_HELVETICA_18
#define font_medium GLUT_BITMAP_HELVETICA_12
#define COLOR_RED glColor3f(255.0f, 0.0f, 0.0f)
#define COLOR_BLACK glColor3f(0.0f, 0.0f, 0.0f)
#define COLOR_WHITE glColor3f(1.0f, 1.0f, 1.0f)
#define COLOR_YELLOW glColor3f(255.0f, 110.0f, 0.0f)
#define COLOR_BLUE glColor3f(75.0/256.0, 175/256.0, 255/256.0)
#define COLOR_GREEN glColor3f(0.0/256.0, 239/256.0, 7/256.0)
#define COLOR_BROWN glColor3f(118.0/256.0, 34/256.0, 21/256.0)
#define COLOR_BLUE glColor3f(75.0/256.0, 175/256.0, 255/256.0)
#define COLOR_GREEN glColor3f(0.0/256.0, 239/256.0, 7/256.0)
#define COLOR_BROWN glColor3f(118.0/256.0, 34/256.0, 21/256.0)
#define COLOR_DBLUE glColor3f(35.0/256.0, 25/256.0, 87/256.0)
#define COLOR_PINK glColor3f(235.0/256.0, 41/256.0, 173/256.0)
#define COLOR_ORANGE1 glColor3f(220.0/256.0, 120/256.0, 8/256.0)
#define COLOR_ORANGE glColor3f(255.0/256.0, 124/256.0, 0/256.0)
#define COLOR_BROWN2 glColor3f(186.0/256.0, 156/256.0, 123/256.0)
#define COLOR_PINK2 glColor3f(240.0/256.0, 195/256.0, 194/256.0)
#define COLOR_MORE1 glColor3f(192.0/256.0, 171/256.0, 63/256.0)
#define COLOR_MORE2 glColor3f(184.0/256.0, 191/256.0, 68/256.0)
#define COLOR_MORE3 glColor3f(132.0/256.0, 40/256.0, 151/256.0)
#define BLACK -5
#define WHITE 1
#define RED 2
#define YELLOW 3
#define BLUE 4
#define GREEN 5
#define BROWN 6
#define DBLUE 7
#define PINK 8
#define ORANGE1 9
#define BROWN2 10
#define PINK2 11
#define MORE1 12
#define MORE2 13
#define MORE3 14
#define default_radius 7
#define ENTER_KEY 13
#define BACKSPACE_KEY 8
#define VALID_KEYS (CHAR_PRESSED>='0' && CHAR_PRESSED<='9') || CHAR_PRESSED==ENTER_KEY || CHAR_PRESSED==BACKSPACE_KEY
#define SWAPBUFFER glutSwapBuffers();
#define REDISPLAY glutPostRedisplay();

#define CONDITION_SIDEBAR2 struct_MOUSEAT.x>((switch_sidebar2==ON)? const_margin_sidebar2:WIDTH-15)&& !select_for_move && !select_for_color && !freeze
#define CONDITION_SIDEBAR1 struct_MOUSEAT.x<((switch_sidebar==ON)? const_margin_sidebar:15) && !select_for_move && !select_for_color && !freeze

#define VALID_LEVEL_KEY (inside('a',CHAR_PRESSED,'z') || inside('A',CHAR_PRESSED,'Z') || inside('0',CHAR_PRESSED,'9'))
#define FASTER 1
#define SLOWER 2
#define pb push_back
#define ppb pop_back
#define VALID_AREA_FOR_NODE struct_MOUSEAT.y>48 && struct_MOUSEAT.y <670 && struct_MOUSEAT.x<870 && struct_MOUSEAT.x>30
