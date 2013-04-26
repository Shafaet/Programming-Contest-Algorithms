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

vector<int>p;
int st[2502],en[2502],e,n,ans=1<<28;
class MagicMolecule {
	public:
	
	void call(i64 mask,int i,int k,int cost)
	{
		if(k<0) return;
		if(i==e){ans=min(ans,cost);return;}
		if(isOn(mask,st[i]) or isOn(mask,en[i]))call(mask,i+1,k,cost);
		else if(k>0)	call(on(mask,st[i]),i+1,k-1,cost+p[st[i]]),call(on(mask,en[i]),i+1,k-1,cost+p[en[i]]);
	}
	
	int maxMagicPower(vector <int> p, vector <string> w) {
		::p=p;
		n=SZ(w);
		
		int m = 0,tot=0;
		while(3*m<2*n) m++;
		rep(i,SZ(p)) tot+=p[i];
		int k=n-m;
		rep(i,n)rep(j,n)if(w[i][j]=='N' and i<j)st[e]=i,en[e++]=j;
			
		call(0,0,k,0);
		
		if(ans==1<<28) return -1;
		return tot-ans;
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
		cout << "Testing MagicMolecule (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366754049;
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
		MagicMolecule _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int magicPower[] = {1,2,3};
				string magicBond[] = {
					"NYY",
					"YNN",
					"YNN"};
				_expected = 4;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			
			case 1:
			{
				int magicPower[] = {1,1,1,1};
				string magicBond[] = {
				 "NNYY",
				 "NNYY",
				 "YYNN",
				 "YYNN"};
				_expected = -1;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			
			case 2:
			{
				int magicPower[] = {86,15,100,93,53,50};
				string magicBond[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"};
				_expected = 332;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 3:
			{
				int magicPower[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691};
				string magicBond[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"};
				_expected = 57179;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			/*case 4:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
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
