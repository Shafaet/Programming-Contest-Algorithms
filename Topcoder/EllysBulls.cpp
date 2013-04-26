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
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
#define uu first
#define vv second


#define on(n,pos) ((n) | (1<<(pos)))
#define off(n,pos)  ((n) & ~(1<<(pos)))
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

typedef long long i64;
typedef unsigned long long ui64;

vector<string>g;
vector<int>bul;
class EllysBulls {
	public:
	map<string,string>mp;
	map<string,int>freq;
	string tos(int x,int n)
	{
		string s=itoa(x);
		while(SZ(s)<n)s="0"+s;
		return s;
	}
	int match(string &a,string &b,int off)
	{
		int c=0;rep(i,SZ(a))c+=(a[i]==b[i+off]);return c;
	}
	void gen(int n)
	{
		int lim=power(10,n);
		for(int i=0;i<lim;i++)
		{
			string s=tos(i,n);
			string cat;
			rep(j,SZ(g))cat+=match(s,g[j],0)+'0';
			freq[cat]++;
			mp[cat]=s;
		}
	}
	string meet(int n,int m)
	{
		gen(n);
		int lim=power(10,m);
		string ans;
		for(int i=0;i<lim;i++)
		{
			
			string s=tos(i,m),w;
			int flag=1;
			rep(j,SZ(g))
			{
				int ret=match(s,g[j],n);
				if(bul[j]-ret<0){flag=0; break;}
				w+=(bul[j]-ret+'0');
			}
			if(flag==0) continue;
			if(mp.find(w)==mp.end()) continue;
			if(freq[w]>1 or ans!="")
			return "Ambiguity";
			ans=mp[w]+s;
			
		}
		if(ans=="") ans="Liar";
		return ans;
	}
	string getNumber(vector <string> g, vector <int> bul) {
		::g=g;
		::bul=bul;
		string s=g[0];
		int n=SZ(s)/2;
		int m=SZ(s)-n;
		return meet(n,m);
		return "";
		
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
		cout << "Testing EllysBulls (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366733717;
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
		EllysBulls _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			
			case 0:
			{
				string guesses[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
				int bulls[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
				_expected = "1337";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			
			case 1:
			{
				string guesses[] = {"0000", "1111", "2222"};
				int bulls[] = {2, 2, 2};
				_expected = "Liar";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 2:
			{
				string guesses[] = {"666666", "666677", "777777", "999999"};
				int bulls[] = {2, 3, 1, 0};
				_expected = "Ambiguity";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 3:
			{
				string guesses[] = {"000", "987", "654", "321", "100", "010"};
				int bulls[] = {2, 1, 0, 0, 1, 1};
				_expected = "007";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 4:
			{
				string guesses[] = {"28", "92", "70", "30", "67", "63", "06", "65",
				                    "11", "06", "88", "48", "09", "65", "48", "08"};
				int bulls[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = "54";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 5:
			{
				string guesses[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
				                    "4166623", "1166638", "2767693", "8650248", "2486509",
				                    "6138934", "4018642", "6236742", "2961643", "8407361",
				                    "2097376", "6575410", "6071777", "3569948", "2606380"};
				int bulls[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
				_expected = "4266642";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			/*case 6:
			{
				string guesses[] = ;
				int bulls[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string guesses[] = ;
				int bulls[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string guesses[] = ;
				int bulls[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
