/*
 *  Shafaetsplanet.com
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

#define SZ(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
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
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){	return (log10l(N))/(log10l(B));	}
vector< string > token(char *a,char *b) {vector<string>v; char *p=strtok(a," "); while(p) {v.pb(p);p=strtok(NULL," ");} return v;}
vector<string>token(string a,char *b){char temp[100002]; strcpy(temp,a.c_str()); return token(temp,b);       }
#define on(n,pos) n=(n | (1<<pos))
#define off(n,pos) n= n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int fx[]={+1,+0,-1,+0};
int fy[]={+0,+1,+0,-1};

#define mx 202
int a[mx],c;
vector<int>g[mx];
int dp[mx][mx];
int call(int u,int idx)
{
	if(idx==c+1) return 0;
	if(dp[u][idx]!=-1) return dp[u][idx];
	int ret=(u!=a[idx])+call(u,idx+1);
	rep(i,SZ(g[u]))
	{
		int v=g[u][i];
		ret=min(ret,(v!=a[idx])+call(v,idx+1));
	}
	return dp[u][idx]=ret;
	
}
int main(){
	//READ("in");
	int t;
	cin>>t;
	while(t--)
	{
		mem(dp,-1);
		int n,e;
		c=0;
		sdii(n,e);
		rep(i,n+3)g[i].clear();
		
		//repl(i,n)g[i].pb(i)
		rep(i,e)
		{
			int u,v;
			sdii(u,v);
			g[u].pb(v);
			g[v].pb(u);
		}
		sdi(c);
		repl(i,c)
		sdi(a[i]);
		
		int ans=1<<29;
		repl(i,n)
		{
			int ret=(i!=a[1])+call(i,2);
			ans=min(ans,ret);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}


