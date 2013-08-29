/*
 * UVA 10304 Optimal BST
 * Knuth Optimization
 * O(n^2)
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

bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

#define mx 255
int s[mx],f[mx];
int cost(int a,int b)
{
	if(a>b) return 0;
	return s[b]-s[a-1];
}
int call(int a,int b)
{
	if(a>b) return 0;
	int ans=1<<28;
	for(int m=a;m<=b;m++)
	{
		int ret=call(a,m-1)+call(m+1,b)+cost(a,m-1)+cost(m+1,b);
		ans=min(ans,ret);
	}
	return ans;
}
int dp[mx][mx],mid[mx][mx];
int iter(int n)
{
	for(int s=1;s<=n;s++)
	{
		for(int a=1;a+s-1<=n;a++)
		{
			int b=a+s-1;
			if(a==b)
			{
				dp[a][b]=0;
				mid[a][b]=a;
				continue;
			}
			
			dp[a][b]=1<<28;
			for(int m=mid[a][b-1];m<=mid[a+1][b];m++)
			{
				int ret=dp[a][m-1]+dp[m+1][b]+cost(a,m-1)+cost(m+1,b);
				if(ret<dp[a][b])
				{
					mid[a][b]=m;
					dp[a][b]=ret;
				}
			}
			
		}
	}
	return dp[1][n];
}
int main() {
		
	//READ("in");
//	WRITE("out1");
	int n;
	while(cin>>n)
	{
		repl(i,n)cin>>f[i],s[i]=s[i-1]+f[i];
		cout<<iter(n)<<endl;
	}
	
	
}
