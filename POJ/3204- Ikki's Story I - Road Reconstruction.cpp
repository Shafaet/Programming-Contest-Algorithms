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
//#define INF (1061109567)
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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

#define MAXN 600
#define MAXE 100002

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], next[MAXE], to[MAXE];
int from[MAXE];
inline void init(int _src, int _snk, int _n) {
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	mem(fin,-1);
	
}

inline void add(int u, int v, int _cap) {
	from[nEdge]=u,to[nEdge] = v, cap[nEdge] += _cap;
	next[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge]=v,to[nEdge] = u, cap[nEdge] += 0;
	next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
	mem(pre,-1);
	int i, u, v;
	mem(dist,-1);
	dist[src]=0;
	queue<int>q;
	q.push(src);
	
	while(!q.empty()) {
		
		u = q.front();q.pop();
		
		for(i=fin[u]; i>=0; i=next[i]) {
			
			v = to[i];
			if(cap[i] && dist[v]==-1) {
				dist[v] = dist[u]+1;
				q.push(v);
				pre[v]=i;  
			}
		}
	}
	
	return dist[snk]!=-1;
}
void augment()
{
	int u=snk,mn=1<<28;
	while(u!=src)
	{
		int edg=pre[u];
		mn=min(mn,cap[edg]);
		u=from[edg];
	}
	
	u=snk;
	while(u!=src)
	{
		int edg=pre[u];
		cap[edg]-=mn;
		cap[edg^1]-=mn;
		
		u=from[edg];
	}
	
}


int main() {
	//READ("in");
	//WRITE("out.txt");
	int n,e;
	cin>>n>>e;
		init(1,n,n);
		rep(i,e)
		{
			int u,v,w;
			
			sdii(u,v);
			sdi(w);
			u++;
			v++;
			add(u,v,w);
		}
		while(bfs())augment();
		int ans=0;
		rep(i,nEdge)
		{
			if(i%2) continue;
			if(!cap[i])
			{
				cap[i]++;
				ans+=bfs();
				cap[i]--;
			}
		}
		
		printf("%d\n",ans);
	
	return 0;
}


