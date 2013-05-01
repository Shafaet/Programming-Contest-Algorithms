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


#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second

using namespace std;


typedef long long i64;
typedef unsigned long long ui64;

vector<int>g[1000];
int vis[1000]={0};
string S;
int f[1000]={0},tot=0;
void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=1;f[S[u]-'a']++;	tot++;
	rep(i,g[u].size())
		dfs(g[u][i]);
	
}
class NewArenaPassword {
	public:
	int minChange(string s, int k) {
		
		S=s;
		int n=SZ(s),ans=0;
		if(n==k) return 0;
		rep(i,k)
			g[i].pb(n-k+i);
			
		
		rep(i,k)
		{
			if(vis[i]==0)
			{
				mem(f,0);tot=0;
				dfs(i);
				int maxi=0;
				for(char c='a';c<='z';c++)
				maxi=max(maxi,f[c-'a']);
				ans+=tot-maxi;
			}
		}
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
		cout << "Testing NewArenaPassword (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362611405;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		NewArenaPassword _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			
			case 0:
			{
				string oldPassword = "topcoderopen";
				int K = 5;
				_expected = 3;
				_received = _obj.minChange(oldPassword, K); break;
			}
			
			case 1:
			{
				string oldPassword = "puyopuyo";
				int K = 4;
				_expected = 0;
				_received = _obj.minChange(oldPassword, K); break;
			}
			case 2:
			{
				string oldPassword = "loool";
				int K = 3;
				_expected = 1;
				_received = _obj.minChange(oldPassword, K); break;
			}
			case 3:
			{
				string oldPassword = "arena";
				int K = 5;
				_expected = 0;
				_received = _obj.minChange(oldPassword, K); break;
			}
			
			case 4:
			{
				string oldPassword = "amavckdkz";
				int K = 7;
				_expected = 5;
				_received = _obj.minChange(oldPassword, K); break;
			}
			
			case 5:
			{
				string oldPassword = "panyapppppwnrppqjvjjneseppvptppipppmbkwdpjpspj";
				int K = 40;
				_expected = 27;
				_received = _obj.minChange(oldPassword, K); break;
			}
			/*case 6:
			{
				string oldPassword = ;
				int K = ;
				_expected = ;
				_received = _obj.minChange(oldPassword, K); break;
			}*/
			/*case 7:
			{
				string oldPassword = ;
				int K = ;
				_expected = ;
				_received = _obj.minChange(oldPassword, K); break;
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
