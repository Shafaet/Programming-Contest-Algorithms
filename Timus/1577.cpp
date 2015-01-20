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
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define SZ(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<i64,i64>
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
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
 
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%lld: ",++ks);



#define mx 2002
string a,b;
int dp1[mx][mx];
int dp2[mx][mx];
int call(int i,int j)
{
	if(i<0) return j+1;
	if(j<0) return i+1;
	if(dp1[i][j]!=-1) return dp1[i][j];
	int ret=1<<28;
	if(a[i]==b[j]) ret=min(ret,1+call(i-1,j-1));
	
	ret=min(ret,1+call(i-1,j));
	ret=min(ret,1+call(i,j-1));
	return dp1[i][j]=ret;
}
int solve(int i,int j)
{
		if(i<0 or j<0) return 1;
		if(dp2[i][j]!=-1) return dp2[i][j];
		int ret=0;
		if(a[i]==b[j])
		{
			ret+=solve(i-1,j-1);
		}
		else
		{
			if(call(i,j)==call(i-1,j)+1) ret+=solve(i-1,j);
			if(call(i,j)==call(i,j-1)+1) ret+=solve(i,j-1);
			
				
		}
		ret%=1000000007;
		return dp2[i][j]=ret;
	
}
int main()
{	
	//READ("in");
	mem(dp1,-1);
	mem(dp2,-1);
	cin>>a>>b;
	
	cout<<solve(SZ(a)-1,SZ(b)-1)<<endl;
	return 0;
}
