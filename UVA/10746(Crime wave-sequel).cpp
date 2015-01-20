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

#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)

#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define SDi(x) scanf("%d",&x)
#define SDii(x,y) scanf("%d%d",&x,&y)

#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

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
const i64 INF64 = (i64)1E16;

double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}

i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}

vector< string > token( string a, string b ) {
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return dist > p.dist;   }


vector<int>G[100];
vector<double>C[100];
#define MX 200

#define door(n) (n+tot)
int w[100][100];
double cost[100][100];

double totcost=0;
int flow(int source,int sink)
{
	double vis[MX];
	int par[MX];
	
	
	cclear(vis,63);
	rep(i,85) vis[i]=INF;
	cclear(par,-1);
	queue<int>q;
	vis[source]=0;
	q.push(source);
	int reach=0;
	
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		
		rep(i,G[u].size())
		{
			int v=G[u][i];
			if(w[u][v] and vis[u]+cost[u][v]+eps<vis[v])
			{
				
				
				vis[v]=vis[u]+cost[u][v];
				//cout<<u<<">>"<<v<<" "<<endl;
				q.push(v);
				par[v]=u;
				if(v==sink) {reach=1;}
				
			}
			
		}
	}
	
	if(!reach) 
	{
		//puts("END FOREVER");
		return -1;
	}
	int u=sink,pre=-1;
	//cout<<">>>"<<vis[sink]<<endl;
	while(1)
	{
		if(pre!=-1 and u!=-1)
		{
	
		//	cout<<u<<" "<<pre<<endl;
			totcost+=cost[u][pre];
			cost[u][pre]*=-1;
			cost[pre][u]*=-1;
			w[u][pre]--;
			w[pre][u]++;
		}
		if(par[u]==-1) break;
		
		pre=u;
		u=par[u];
		
	}
	//puts("-----");
	return 1;
}
int main()
{
	//READ("in");
	int n,m;
	while(SDii(n,m) and n and m)
	{
		
		mem(w,0);
		totcost=0;
		int tot=n+m;
		rep(i,tot+10)G[i].clear();
		mem(cost,0);
		
		for(int u=1;u<=n;u++)
		{
			G[u].pb(door(u));
			G[door(u)].pb(u);
			
			w[u][door(u)]=0;
			w[door(u)][u]=1;	
			for(int v=n+1;v<=tot;v++)
			{
				double dis;
				cin>>dis;
				w[door(v)][v]=1;
				w[v][door(v)]=0;
				
				w[door(u)][v]=0;
				w[v][door(u)]=1;
				
				
				G[v].pb(door(v));
				G[door(v)].pb(v);
				
				G[door(u)].pb(v);
				G[v].pb(door(u));
				
				cost[door(u)][v]=dis;
				cost[v][door(u)]=dis;
			}
			
			
		}
		int source=0,sink=tot*2+1;
		for(int u=1;u<=n;u++)
		{
			
			w[u][source]=1;
		    
		    G[u].pb(source);
			//cout<<"sink::"<<u<<">>"<<source<<endl;
			
		}
		for(int v=n+1;v<=tot;v++)
		{
		    
		    w[sink][door(v)]=1;
		    
		    G[sink].pb(door(v));	
			//cout<<"source::"<<sink<<">>"<<v<<endl;
		}
		double ans=0;
		int s=0;
		while(1)
		{
			int ret=flow(sink,source); //cout<<ret<<" tot "<<totcost<<endl;
			s++;
		     if(ret==-1) break;
		     if(s==n) break;
		}
		ans=totcost/n;
		printf("%.2lf\n",ans+eps);
		
		
		
	}
	
	
}







	


 
