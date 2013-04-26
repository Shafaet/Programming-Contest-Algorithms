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
#define pop __builtin_popcount
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


class PaperUnfolding {
	public:
	
	int call(string s)
	{
		string w;
		int n=SZ(s);
		if(!n) return 1;
		rep(i,n/2)
		{
			w+=s[i];
			if(s[i]==s[n-i-1]) return 0;
		}
		return call(w);
		     
	}
	string isValidUnfolding(vector <string> code) {
		string s;
		rep(i,SZ(code))
		s+=code[i];
		if(call(s)) return "YES";
		return "NO";
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
		cout << "Testing PaperUnfolding (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366343887;
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
		PaperUnfolding _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string code[] = {};
				_expected = "YES";
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}
			case 1:
			{
				string code[] = {"0"};
				_expected = "YES";
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}
			case 2:
			{
				string code[] = {"000"};
				_expected = "NO";
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}
			case 3:
			{
				string code[] = {"1000110"};
				_expected = "YES";
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}
			case 4:
			{
				string code[] = {"10001101100111001000110010011101100011011001110110",
				                 "00110010011101100011011001110010001100100111001000",
				                 "11011001110110001100100111001000110110011100100011",
				                 "00100111011000110110011101100011001001110010001101",
				                 "10011100100011001001110010001101100111011000110010",
				                 "01110"};
				_expected = "YES";
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}
			/*case 5:
			{
				string code[] = ;
				_expected = ;
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string code[] = ;
				_expected = ;
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string code[] = ;
				_expected = ;
				_received = _obj.isValidUnfolding(vector <string>(code, code+sizeof(code)/sizeof(string))); break;
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
