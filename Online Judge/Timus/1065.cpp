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









#define MX 30002
vector<int>G[MX];

int mxdep=0,mxnode,dia=0,mxnode2;

void dfs(int par,int u,int dep)
{	
	if(dep>mxdep)
	{
		mxdep=dep;
		mxnode=u;
	}
	for(int i=0;i<(int)G[u].size();i++)
	{
		
		int v=G[u][i];
		if(v==par) continue;
		dfs(u,v,dep+1);
	}
	
}

void call(int par,int u,int dep,int *d)
{
	d[u]=dep;
	if(dep>dia)
	{
		mxnode2=u;
		dia=dep;
	}
	for(int i=0;i<(int)G[u].size();i++)
	{
		
		int v=G[u][i];
		if(v==par) continue;
		call(u,v,dep+1,d);
	}
	
}



int d1[MX],d2[MX];
int main()
{
	
	//READ("in");
	//WRITE("out");
	int n;
	
	
		SDi(n);
		mxdep=0;
		dia=0;
		
			for(int i=2;i<=n;i++)
			{
				
                
				int par;
				cin>>par;
				
				G[par].pb(i);
				G[i].pb(par);
				
			}
			
		dfs(-1,1,0);
		
		call(-1,mxnode,0,d1);
		call(-1,mxnode2,0,d2);
		
		int mn=1<<28;
		
		for(int i=1;i<=n;i++)	mn=min(mn,max(d1[i],d2[i]));
		
		int ff=0;
		for(int i=1;i<=n;i++)
		{
			if(max(d1[i],d2[i])==mn) 
			{
				if(ff) printf(" ");ff=1;
				cout<<i;
			}
		}
		puts("");
			
		
		
		
	
	
	
}
	

	


 

