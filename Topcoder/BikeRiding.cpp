//http://community.topcoder.com/stat?c=problem_statement&pm=6763
//SRM 545 div2 level 3

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
#define sz(x) (int)x.size()
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

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
#define on(n,pos) ((n) | (1LL<<(pos)))
#define off(n,pos)  ((n) & ~(1LL<<(pos)))
#define isOn(n,pos) (bool)(n & (1LL<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

typedef long long i64;
typedef unsigned long long ui64;
#define mx 55
vector<string>w;
vector<int>g[55],r[55],out,dag[55];




int vis[mx],color[mx];
void dfs(int u)
{
	
	if(!vis[u])
	{
		vis[u]=1;
		for(int i=0;i<(int)g[u].size();i++)
			dfs(g[u][i]);
		out.pb(u);
	}
}
int cmp[mx];

void scc(int u,int mark)
{
	cmp[mark]++;
	color[u]=mark;
	for(int i=0;i<(int)r[u].size();i++)
	{
		int v=r[u][i];
		if(!vis[v])
		{
			vis[v]=1;
			scc(v,mark);
		}
		
	}
	
}
i64 dp[55],dp2[55];
int n,lim;
int MAXVAL= 1000000000;
int des;
int cango(int u)
{
	if(u==des) return 1;
	if(dp2[u]!=-1) return dp2[u];
	int ans=0;
	rep(i,sz(dag[u]))
	{
		int v=dag[u][i];
		ans|=cango(v);
		
	}
	return dp2[u]=ans;
}
i64 call(int u)
{
	if(dp[u]!=-1) return dp[u];
	if(cmp[u]>1 and cango(u)) return dp[u]=MAXVAL+1;
	
	if(u==des) return 1;
	i64 ans=0;
	rep(i,sz(dag[u]))
	{
		int v=dag[u][i];
		ans+=call(v);
		if(ans>MAXVAL) ans=MAXVAL+1;
	}
	return dp[u]=ans;
}

class BikeRiding {
	public:
	int countRoutes(vector <string> w, vector <int> st, int en, int lim) {
		::lim=lim;
		::w=w;
		n=sz(w);
		MAXVAL=min(MAXVAL,lim);
		mem(dp,-1);
		mem(dp2,-1);
		
		rep(i,n)
		{
			rep(j,n)
			{
				if(w[i][j]=='1' and i!=j)
				{
					int u=i;
					int v=j;
					g[u].pb(v);
					r[v].pb(u);
					
				}
			}
		}
		
		
		int ass=0;
		rep(i,n)dfs(i);
		mem(vis,0);
		reverse(all(out));
		rep(i,n)
		{
			int u=out[i];
			if(!vis[u])
			{
				vis[u]=1;
				++ass;
				scc(u,ass);
			}
		}
		rep(i,n) if(w[i][i]=='1') cmp[color[i]]++;
		rep(u,n)
		{
			rep(i,sz(g[u]))
			{
					int v=g[u][i];
					if(color[v]==color[u]) continue;
					dag[color[u]].pb(color[v]);
			}
		}
		
				
		des=color[en];
		i64 ans=0;
		rep(i,sz(st))
		{
			int u=color[st[i]];
			if(cango(u))
			ans+=call(u);
		}
		
		if(ans>MAXVAL) ans=-1;
		
		return ans;
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
		cout << "Testing BikeRiding (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1380335394;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BikeRiding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string paths[] = {"011" ,"001", "000"};
				int startPoints[] = {0,1};
				int endPoint = 2;
				int n = 5;
				_expected = 3;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}
			case 1:
			{
				string paths[] = {"01000",
				                  "00100",
				                  "00010",
				                  "01001",
				                  "00000"};
				int startPoints[] = {0};
				int endPoint = 4;
				int n = 10;
				_expected = -1;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}
			case 2:
			{
				string paths[] = {"000111000000000","000111000000000","000111000000000",
				                  "000000111000000","000000111000000","000000111000000",
				                  "000000000111000","000000000111000","000000000111000",
				                  "000000000000111","000000000000111","000000000000111",
				                  "000000000000001","000000000000001","000000000000000"};
				int startPoints[] = {0,1,2};
				int endPoint = 14;
				int n = 1000;
				_expected = 243;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}
			case 3:
			{
				string paths[] = {"010", "100", "001"};
				int startPoints[] = {0};
				int endPoint = 2;
				int n = 10;
				_expected = 0;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}
			case 4:
			{
				string paths[] = {"00001000001101110101100000101011000000100010010010", "00100000000000000000000000000000000000000000100000", "00010000001000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000", "01000101011010100001001100011010100000000000000010", "00000001000000000000001010000000000000100010100000", "01011100010100110111111000011110010000010000000101", "00100000001000000001000100000000000000000000000000", "10101111001101001110001001010011110101110100110110", "00000000000000000000000000000000000000000000000000", "00000000010000000000000000000000000000000000000000", "00111101010010000000001000111100110000010000100011", "00000101000000000010001100010000000000000001000000", "00010001011000100010100100010000000000000000000000", "00000000000000000001001000000000000000000010000000", "00010000000000000000000000000000000000100000000000", "10000110010110010111011011111101010001110000010101", "00000001001001000000110010101001110000010001110111", "01000000001000000001000100000000000000000010000000", "00000000000000010000000000000000000000000000000000", "00110101001010110010000000000000000000000010100000", "01101100010011100011001000011010110000000001000010", "01000000001000000001000100000000000000000000100000", "01010000000000000001000000000000000000000000000000", "00000001001000110010001100000000000000000011000000", "10001110001101000000010010001101110001010010010001", "01001100001010000001000010001000110000110011100011", "00000001011000000000000010000000000000000010000000", "00000100001011010000101010000000000000000000000000", "00001100001001100000100100111010010100000010000001", "01110101010011110001100100000000100000000010100000", "01001000001010010010001100010110010100110001110011", "01100000001010000010100010001000000000000000000000", "01000000000001000011001100001000100000010000100001", "11001110100011001100100111100111100111101111111111", "00000000001000110000100000000000000000000000100000", "10001110100110001111100011011111010101110101010110", "11101011000110100110110010101111100000110011110111", "00000000000000000000000000000000000000000000100000", "00000000000010000010101000010010000000000000100000", "11000110101110001010001101111100010111010100110111", "00001100011101001101010001101111100101000000010101", "00010000011000010000000000000000000000100000100000", "00100001001000000001000000000000000000000000000000", "00000000000000000000000000000000000000000000000000", "00111101000111000000010100011100010100010001000010", "10001111101100101101110100010111000011011101010101", "01111000000011010001110010110110010100110000100001", "01100100010010000001100010001010100100010011000001", "01100101000011000000100010000000000000000010100000"};
				int startPoints[] = {8, 6, 47, 21, 39, 30, 27, 24, 22, 2};
				int endPoint = 10;
				int n = 31982602;
				_expected = 31982602;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}
			/*case 5:
			{
				string paths[] = ;
				int startPoints[] = ;
				int endPoint = ;
				int n = ;
				_expected = ;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}*/
			/*case 6:
			{
				string paths[] = ;
				int startPoints[] = ;
				int endPoint = ;
				int n = ;
				_expected = ;
				_received = _obj.countRoutes(vector <string>(paths, paths+sizeof(paths)/sizeof(string)), vector <int>(startPoints, startPoints+sizeof(startPoints)/sizeof(int)), endPoint, n); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
