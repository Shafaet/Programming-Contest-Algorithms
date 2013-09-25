/*
 * LOJ 1095 Arrange the numbers
 * DP
 * Permutation with k non-fixed points
 * 
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
string toBin(int n){ string s; repv(i,32)s+=(isOn(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);



int sav[1002][1002];
i64 mod=1000000007;
i64 nCr(int n, int r)
{
    if(n==r) return sav[n][r] = 1;
    if(r==0) return sav[n][r] = 1;
    if(r==1) return sav[n][r] = n;
    if(sav[n][r]) return sav[n][r];
    return sav[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}


#define mx 1010

i64 dp[mx][mx];
i64 fact(i64 n)
{
	if(n==0) return 1;
	return (n*fact(n-1))%mod;
}

i64 f(int n,int k)//Permutation with k non-fixed points
{
	assert(n>=k);
	if(n<0 or k<0) return 0;
	if(k==0) return fact(n);
	if(dp[n][k]!=-1) return dp[n][k];
	i64 norm=n-k;
	i64 sp=k-1;
	i64 ret1=0,ret2=0,ans=0;
	ret1=norm*f(n-1,k-1);
	ret2=sp* ((f(n-1,k-1)  +f(n-2,k-2)  )%mod);
	ans=ret1+ret2;
	ans%=mod;
	return dp[n][k]=ans;
}


int main() {
		
	//READ("in");
	mem(dp,-1);
	int t,ks=0;
	sdi(t);
	while(t--)
	{
		int n,m,k;
		sdii(n,m);
		sdi(k);
		i64 ans=nCr(m,k)*f(n-k,m-k);
		ans%=mod;
		printf("Case %d: %lld\n",++ks,ans);
	}
	
}
