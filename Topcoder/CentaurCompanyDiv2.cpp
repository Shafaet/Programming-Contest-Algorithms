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

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
#define on(n,pos) ((n) | (1LL<<(pos)))
#define off(n,pos)  ((n) & ~(1LL<<(pos)))
#define isOn(n,pos) (bool)(n & (1LL<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

typedef long long i64;
typedef unsigned long long ui64;

#define mx 102
vector<int>g[mx];
i64 dp[55][5];
i64 call(int par,int u,int wroot)
{
	if(dp[u][wroot]!=-1) return dp[u][wroot];
	i64 ret=wroot;
	if(wroot==0)
	{
		
		ret+=call(par,u,1);
		rep(i,SZ(g[u]))
		{
			int v=g[u][i];
			if(v==par) continue;
			ret+=call(u,v,0);
		}
	}
	else
	{		
		rep(i,SZ(g[u]))
		{
			int v=g[u][i];
			if(v==par) continue;
			ret*=(1+call(u,v,1));
		}
	}
	return dp[u][wroot]=ret;
}
class CentaurCompanyDiv2 {
	public:
	long long count(vector <int> a, vector <int> b) {
		mem(dp,-1);
			rep(i,SZ(a))
			{
				g[a[i]].pb(b[i]);
				g[b[i]].pb(a[i]);
			}
			return call(0,1,0)+1;
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
		cout << "Testing CentaurCompanyDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1370394740;
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
		CentaurCompanyDiv2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			
			case 0:
			{
				int a[] = {1};
				int b[] = {2};
				_expected = 4LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			
			case 1:
			{
				int a[] = {2,2};
				int b[] = {1,3};
				_expected = 7LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			
			case 2:
			{
				int a[] = {1,2,3,4,5,6,7,8,9};
				int b[] = {2,3,4,5,6,7,8,9,10};
				_expected = 56LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int b[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
				_expected = 1125899906842675LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {10, 7, 2, 5, 6, 2, 4, 9, 7};
				int b[] = {8, 10, 10, 4, 1, 6, 2, 2, 3};
				_expected = 144LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
