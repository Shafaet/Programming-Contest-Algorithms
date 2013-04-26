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


#define on(n,pos) (n | (1<<(pos)))
#define off(n,pos) n & ~(1<<pos)
#define ison(n,pos) (bool)(n & (1<<(pos)))


typedef long long i64;
typedef unsigned long long ui64;

int side[20][20][20];
i64 dp[18][(1<<18)+1];
class PolygonTraversal {
	public:
	int n;
	int cross(int mask,int a,int b)
	{
		if(a>b) swap(a,b);
		int p1=0,p2=0;
		repl(i,n)
		{
			if(ison(mask,i-1) and i!=a and i!=b)
			{				
				p1=p1 || (side[a][b][i]==0);
				p2=p2 || (side[a][b][i]==1);
				if(p1 and p2) return true;
			}
		}
		
		return false;
	}
	int p0;
	i64 call(int u,int mask)
	{		
		if(dp[u-1][mask]!=-1) return dp[u-1][mask];
		if(mask==((1<<n)-1))
		{			
			return dp[u-1][mask]=cross(mask,u,p0);
		}
		
		i64 ret=0;
		repl(i,n)
		{			
			if(!ison(mask,i-1) and cross(mask,u,i))
				ret+=call(i,on(mask,i-1));
		}
		return dp[u-1][mask]=ret;
	}
	long long count(int N, vector <int> points) {
		
		p0=points.front();
		mem(dp,-1);
		n=N;
		repl(i,N)
		{
			for(int j=i+1;j<=N;j++)
			{
				int x=i;
				while(1)
				{
					if(x!=i and x!=j)
						side[i][j][x]=1;
					if(x==j) break;
					x++;
					if(x>N)x=1;
				}
			}
		}
		int mask=0;
		rep(i,SZ(points))
		mask=on(mask,points[i]-1);
		return call(points.back(),mask);
		
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
		cout << "Testing PolygonTraversal (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366691542;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PolygonTraversal _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			
			
			case 0:
			{
				int N = 5;
				int points[] = {1, 3, 5};
				_expected = 1LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			
			case 1:
			{
				int N = 6;
				int points[] = {1, 4, 2};
				_expected = 1LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			
			
			case 2:
			{
				int N = 7;
				int points[] = {2, 4, 7};
				_expected = 2LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 7;
				int points[] = {1, 2, 3, 4, 6, 5};
				_expected = 0LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 18;
				int points[] = {1, 7, 18};
				_expected = 4374612736LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int points[] = ;
				_expected = LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int points[] = ;
				_expected = LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int points[] = ;
				_expected = LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
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
