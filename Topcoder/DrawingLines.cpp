#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define Pop __builtin_popcount
#define SZ(x) (int)x.size()
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
using namespace std;
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
#define uu first
#define vv second


#define on(n,pos) n=(n | (1<<pos))
#define off(n,pos) n= n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

typedef long long i64;
typedef unsigned long long ui64;

struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){};
};
class DrawingLines {
	public:
	double countLineCrossings(int n, vector <int> s, vector <int> e) {
		
		int u[10002]={0},d[10002]={0};
		vector<node>v;
		double ans=0;
		int cross=0;
		int m=SZ(s);
		rep(i,m){v.pb(node(s[i],e[i]));u[s[i]]=1; d[e[i]]=1;}
		double b=n-m;
		ans=ans+(b*(b-1))/4.00;
		
		rep(i,m)
		{
				rep(j,m)cross+=(v[i].x<v[j].x and v[i].y>v[j].y);
			  
				double tl=0,tr=0,bl=0,br=0;
				repl(k,n)
				{
					tl+=(!u[k] and k<v[i].x);
					tr+=(!u[k] and k>v[i].x);
					bl+=(!d[k] and k<v[i].y);
					br+=(!d[k] and k>v[i].y);
				}
				double div=tl+tr;
				ans+=(tl*br/div) + (tr*bl/div);
		}
		
		return ans+cross;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing DrawingLines (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366662930;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DrawingLines _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			
			case 0:
			{
				int n = 3;
				int startDot[] = {2};
				int endDot[] = {3};
				_expected = 1.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int startDot[] = {1,4};
				int endDot[] = {3,1};
				_expected = 5.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			
			case 2:
			{
				int n = 4;
				int startDot[] = {4,1};
				int endDot[] = {4,1};
				_expected = 0.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 8;
				int startDot[] = {1,4,3,6,7};
				int endDot[] = {1,3,2,4,5};
				_expected = 7.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int startDot[] = ;
				int endDot[] = ;
				_expected = ;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int startDot[] = ;
				int endDot[] = ;
				_expected = ;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int startDot[] = ;
				int endDot[] = ;
				_expected = ;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
