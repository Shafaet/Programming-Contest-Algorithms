/*
 * APIO 10 Commandos
 * DP with Convex Hull optimization
 * Complexity: O(n)
 */ 
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
#include <utility>
#include <vector>
#include <assert.h>

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<(pos)))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<(pos)))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

#define MAX 1000002

struct line 
{
  long long m, b;
  line(long long x=0, long long y=0) { m=x; b=y; }
}lines[MAX];

bool bad(const line &x, const line &y, const line &z) {
	i64 p1=(y.m-z.m) * (y.b-x.b);
	i64 p2=(x.m-y.m) * (z.b-y.b);
	return  p1>=p2;
  
}
void addline(i64 m,i64 b,int startptr,int &endptr) 
{
	lines[endptr]=line(m,b);
	endptr++;
	while (endptr-startptr >= 3 && bad(lines[endptr-3], lines[endptr-2], lines[endptr-1])) 
	{
	
		lines[endptr-2] = lines[endptr-1];
		endptr--;
	}
}
int inp[MAX];
i64 s[MAX];
i64 A,B,C;
i64 dp[MAX];
int main() {
		
		//READ("in");
		//WRITE("out");
		ios_base::sync_with_stdio(false);
	
		int n;
		cin>>n;
		cin>>A>>B>>C;
		assert(n<=1000000);
		assert(A>=-5 and A<=-1);
		assert(abs(B)<=10000000);
		assert(abs(C)<=10000000);
		repl(i,n)
		{
			cin>>inp[i];
			assert(inp[i]<=100);
			assert(inp[i]>=1);
			s[i]=s[i-1]+inp[i];
			
		}
		
		int start=0,end=1;
		dp[0]=0;
		lines[0]=line(-2*A*s[0],   dp[0]-B*s[0]+A*s[0]*s[0]);
		
		
		repl(i,n)
		{
			dp[i]=-(1LL<<60);
			for(int j=start;j<end;j++)
			{
				i64 m=lines[j].m;
				i64 b=lines[j].b;
				i64 x=s[i];
				i64 indep=A*x*x+B*x+C;
				i64 val = m*x+b+indep;
				if(val>dp[i])
				{
					dp[i]=val;
					start=j;
				}
				else break; //We will only get worse value if we move right, so break
			}
			if(i<=n)	{
				
				i64 m=-2*A*s[i];
				i64 b=dp[i]-B*s[i]+A*s[i]*s[i];
				
				addline(m,b,start,end); //add next line
			}
			
		}
		cout<<dp[n]<<endl;
	
	return 0;
}
