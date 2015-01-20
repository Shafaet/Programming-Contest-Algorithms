/*
 * 12092 - Paint the Roads
 * ACM-ICPC Dhaka Site Regional Contests :: 2006 - Dhaka
 * Min-cost max flow
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

#define mx 202

int source,sink;
vector<int>g[mx];
int cap[mx][mx];
int cost[mx][mx];
void init(int node,int _source,int _sink)
{
	rep(i,node+2)g[i].clear();
	source=_source;	sink=_sink;
}
void add(int u,int v,int _cap,int _cost)
{
	g[u].pb(v);	g[v].pb(u);
	cap[u][v]=_cap;	cap[v][u]=0;
	cost[u][v]=_cost;	cost[v][u]=-_cost;
}
struct node
{
	int u,w;
	node(int u,int w):u(u),w(w){};
	bool operator < ( const node& p ) const {      return w > p.w;   }
};
int dis[mx],par[mx];
int ssp()
{
	mem(dis,63);
	mem(par,-1);
	priority_queue<node>q;
	q.push(node(source,0));
	dis[source]=0;
	while(!q.empty())
	{
		node top=q.top(); q.pop();
		int u=top.u;
		if(u==sink) return dis[u];
		rep(i,sz(g[u]))
		{			
			int v=g[u][i];
			int w=cost[u][v];
			if(cap[u][v] and dis[u]+w<dis[v])
			{
				
				dis[v]=dis[u]+w;
				par[v]=u;
				q.push(node(v,dis[v]));
			}
		}
	}
	
	return -1;
}
int mcmf(int &flowcost)
{
	int flow=0;
	flowcost=0;
	while(ssp()!=-1)
	{
		
		int u,bottle_neck=inf;
		for(int v=sink;v!=source;v=u)
		{
			u=par[v];
			bottle_neck=min(bottle_neck,cap[u][v]);
		}
		for(int v=sink;v!=source;v=u)
		{
			u=par[v];
		
			cap[u][v]-=bottle_neck;
			cap[v][u]+=bottle_neck;
		}
		
		flow+=bottle_neck;
		flowcost+=bottle_neck*dis[sink];
		
	}
	return flow;
}
int main() 
{
	//READ("in");	
	int t;
	sdi(t);
	while(t--)
	{
		int n,e,k;
		sdii(n,e); sdi(k);
		init(n*2+2,0,n*2+1);
		repl(i,e)
		{
			int u,v,cost;
			sdii(u,v);
			u++;v++;
			sdi(cost);
			add(u,v+n,1,cost);
		}
		repl(i,n)
		{
			
			add(source,i,k,0);
			add(i+n,sink,k,0);
		}
		int cost;
		int flow=mcmf(cost);
		if(flow!=n*k) cost=-1;
		pfi(cost);
		//cout<<flow<<" "<<cost<<endl;
	}
	
}
