
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
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);



char w[27][27];
int n;
i64 dp[(1<<16)+12];
i64 call(int m)
{
	if(m==0) return 1;
	if(dp[m]!=-1) return dp[m];
	i64 ret=0;
	rep(i,n)if(isOn(m,i))
	{
		int flag=1;
		rep(j,n)
		{
			if(w[i][j]=='Y' and isOn(m,j)) flag=0;
		}
		if(flag)
		ret+=call(off(m,i));
	}
	return dp[m]=ret;
	
}

int main(){
	
	//READ("in");
	int t;
	sdi(t);
	while(t--)
	{
		mem(dp,-1);
		int m;
		sdi(m);
		n=m*2;
		rep(i,n)
		sds(w[i]);
		
		i64 ans=0;
		rep(mask,1<<n)
		{
			if(__builtin_popcount(mask)==m)
			{
				int flag=1;
				rep(i,n)if(isOn(mask,i))
				{
					rep(j,n)
					{
						if(w[i][j]=='Y' and !isOn(mask,j)) flag=0;
					}
				}
				if(!flag) continue;
				call(mask);
				
			}
		}
		
		rep(mask,1<<n)
		{
			if(__builtin_popcount(mask)==m and dp[mask]!=-1)
			{
				
				int comp=mask;
				rep(i,n)
				{
					if(isOn(mask,i)) comp=off(comp,i);
					else comp=on(comp,i);
				}
				if(dp[mask]!=-1 and dp[comp]!=-1)
				{
					ans+=dp[mask]*dp[comp];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

