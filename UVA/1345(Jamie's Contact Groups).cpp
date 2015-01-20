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
//double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
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
int fx[]={0,+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={0,-1,+1,+0,+0,+1,+1,-1,-1};




#define SET(p) memset(p, -1, sizeof(p))

#define MAX 2000

int deg[MAX], adj[MAX][MAX], cap[MAX][MAX], Cap[MAX][MAX], q[100000];
int dinic( int n,int s,int t ) {
	int prev[MAX], u, v, i, z, flow = 0, qh, qt, inc;
	while(1) {
		memset( prev, -1, sizeof( prev ) );
		qh = qt = 0;
		prev[s] = -2;
		q[qt++] = s;
		while( qt != qh && prev[t] == -1 ) {
			u = q[qh++];
			for(i = 0; i < deg[u]; i++) {
				v = adj[u][i];
				if( prev[v] == -1 && cap[u][v] ) {
					prev[v] = u;
					q[qt++] = v;
				}
			}
		}
		if(prev[t] == -1) break;
		for(z = 0; z < n; z++) if( prev[z] !=- 1 && cap[z][t] ) {	
			inc = cap[z][t];
			for( v = z, u = prev[v]; u >= 0; v = u, u=prev[v]) inc = min( inc, cap[u][v] );
			if( !inc ) continue;
			cap[z][t] -= inc;
			cap[t][z] += inc;
			for(v=z, u = prev[v]; u >= 0; v = u, u = prev[v]) {
				cap[u][v] -= inc;
				cap[v][u] += inc;
			}
			flow += inc;
		}
	}
	return flow;
}
bool visited[MAX];
void dfs( int u ) {
	visited[u] = true;
	for(int i = 0; i < deg[u]; i++) {
		int v = adj[u][i];
		if( !visited[v] && cap[u][v] && Cap[u][v] ) dfs(v);
	}
}


void assign(int u,int v,int ww,int ff) 
{
	 
	 if(ff)
	 {
		 adj[u][deg[u]++]=v;
		 adj[v][deg[v]++]=u;
	 }
	 cap[u][v]=ww;
	 cap[v][u]=0;
	 Cap[u][v]=ww;
	 Cap[v][u]=0;
	
}
vector<pii>edg;
int n,m;

char s[100000];
int main(){

	
	//READ("in");
	
	while(sdii(n,m)==2)
	{
		mem(deg,0);
		edg.clear();
		getchar();
		if(!n and !m) break;
		
		int src=0,sink=n+m+1;
		
		repl(u,n)
		{
			edg.pb(pii(src,u));
			
			gets(s);
			
			char *pch=strtok(s," ");
			int flag=0;
			while(pch)
			{
				if(flag)
				{
					int v=atoi(pch);
					
					edg.pb(pii(u,v+n+1));
				
				}
				flag=1;
				pch=strtok(NULL," ");
			}
		}
		
		
		int lo=1,hi=n+10,ans,ff=1;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2;
			
			
			 
			 rep(i,SZ(edg))
			 {
				 int u=edg[i].first;
				 int v=edg[i].second;
				 
				 assign(u,v,1,ff);
			 }
			 repl(u,m)
			 assign(u+n,sink,mid,ff);
			 ff=0;
			 int ret=dinic(n+m+2,src,sink);
			
			
			
			if(ret==n){ans=mid; hi=mid-1;}
			else lo=mid+1;
		}
		pfi(ans);
		
	}
	
	return 0;
}

