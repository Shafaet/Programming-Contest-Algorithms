/*
 * Find number of unique LCS
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
#define INT_MAX 2147483647
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
int fx[]={0,0,1,-1};
int fy[]={-1,1,0,0};
bool eq(double a,double b){return fabs(a-b)<eps;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

#define mx 1002
string a,b;
int dp[1002][1002];
int call(int i,int j)
{
	
	if(i==sz(a) or j==sz(b))return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	
	if(a[i]==b[j]) {	
		return dp[i][j]=call(i+1,j+1)+1;
	}
	else return dp[i][j]=max(call(i+1,j),call(i,j+1));
}
int nexta[mx][30],nextb[mx][30],mod=1000007;
int sav[1002][1002];
int count(int i,int j)
{
	if(i>=sz(a) or j>=sz(b)) return 1;
	if(sav[i][j]!=-1) return sav[i][j];
	int lc=call(i,j);
	
	if(lc==0) return sav[i][j]=1;
	
	int ans=0;
	rep(k,26)
	{
		int x=nexta[i][k];
		int y=nextb[j][k];
		
		if(call(x,y)==lc)
		{
			
			ans+=count(x+1,y+1);
			ans%=mod;
		}
	}
	return sav[i][j]=ans;
}

int main()
{
	//READ("in");
	int t,ks=0;
	sdi(t);
	while(t--)
	{
		mem(dp,-1);
		mem(sav,-1);
		cin>>a>>b;
		
		mem(nexta,-1);
		mem(nextb,-1);
		
		int last[33];
		rep(i,26)last[i]=sz(a);
		repv(i,sz(a))
		{
			int x=a[i]-'a';
			last[x]=i;
			rep(j,26)
				nexta[i][j]=last[j];
		}
		rep(i,26)last[i]=sz(b);
		
		repv(i,sz(b))
		{
			int x=b[i]-'a';
			last[x]=i;
			rep(j,26)
				nextb[i][j]=last[j];
		}
		pks;
		pfi(count(0,0));
		
	}
		
}

