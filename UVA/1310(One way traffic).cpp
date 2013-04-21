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
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
#define sdl(x) scanf("%lld",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}

vector< string > token( string a, string b ) {
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}


int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
int isupper(char s) {if(s>='A' and s<='Z') return 1; return 0;}
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=reset(N,pos);return N=Set(N,pos);}
void pbit(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}
//bool operator < ( const node& p ) const {      return w < p.w;   }

#define mx 2002

int bridge[mx][mx];
vector<int>g[mx];
vector<int>dg[mx];
int d[mx],low[mx];
int t=0;
void dfs(int u,int from)
{
	++t;
	d[u]=low[u]=t;
	rep(i,g[u].size())
	{
		int v=g[u][i];
		if(v==from) continue;
		if(d[v]==0)
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>d[u])
			{
				bridge[u][v]=bridge[v][u]=1;
			
			}
		}
		else low[u]=min(low[u],d[v]);
	}
}
int dir[mx][mx],vis[mx];
void call(int u)
{
	rep(i,dg[u].size())
	{
		int v=dg[u][i];
		if(vis[v]) continue;
		vis[v]=1;
		dir[u][v]=1;
		call(v);
	}
}
int main()
{	
	//READ("in");
	int n,e;
	int mult=0;
	while(cin>>n>>e){
		if(mult) mult/=0;
		mult=1;
		vector<pii>bid;
		rep(i,e)
		{
			int u,v,c;
			sdii(u,v);
			sdi(c);
			g[u].pb(v);
			g[v].pb(u);
			
			dg[u].pb(v);
			if(c==2)
			{
				bid.pb(pii(u,v));
				dg[v].pb(u);
			}
		}
		dfs(1,0);
		repl(i,n)
		{
			if(!vis[i])
			{
				vis[i]=1;
				call(i);
			}
		}
		rep(i,bid.size())
		{
			int u=bid[i].first;
			int v=bid[i].second;
			if(bridge[u][v])
			{
				printf("%d %d 2\n",u,v);
			}
			else
			{
				if(dir[u][v]==0) swap(u,v);
				printf("%d %d 1\n",u,v);
			}
		}
	}
}
