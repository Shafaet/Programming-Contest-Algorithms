/*
 * UVA 12424
 * Heavy Light Decomposition + BIT 
 * BUET Inter-University Programming Contest
 */ 
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pmp make_pair
#define sz(s) ((int)(s.size()))


using namespace std;
template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E16;

#define mxn 100002
int ChainLdr[mxn];
int Par[mxn];
int Level[mxn];
int Chain[mxn];
int Pos[mxn];
int SubT[mxn];

vector<int>g[mxn];

int dfs(int from,int u,int dep)
{
	Par[u]=from;
	SubT[u]=1;
	Level[u]=dep;
	for(int i=0;i<(int)g[u].size();i++)
	{
		int v=g[u][i];
		if(v==from) continue;
		SubT[u]+=dfs(u,v,dep+1);
	}
	return SubT[u];
	
}

int nC=0,nP=0;
void HeavyLight(int u,int k,int isLight)
{
	
	if(isLight)
	{
		k=++nC;
		ChainLdr[k]=u;
	}
	
	Chain[u]=k;
	Pos[u]=++nP;
	int maxi=-1;
	for(int i=0;i<(int)g[u].size();i++)
	{
		int v=g[u][i];
		if(Par[u]==v) continue;
		if( maxi==-1 ) maxi = v;
        else if( SubT[v] > SubT[maxi] ) maxi = v;
	}
	if( maxi==-1 ) return;
    HeavyLight( maxi,k,false );
    for(int i=0;i<(int)g[u].size();i++)
	{
		int v=g[u][i];
		if(Par[u]==v) continue;
		if(maxi==v) continue;
		HeavyLight(v,0,true);
	}
}

int LCA(int u,int v)
{	
	while(Chain[u]!=Chain[v]){		
		if(Level[ChainLdr[Chain[u]]]<Level[ChainLdr[Chain[v]]])	{
			v = Par[ChainLdr[Chain[v]]];
		}
		else{
			u = Par[ChainLdr[Chain[u]]];
		}
	}
	if( Level[u] < Level[v] ) return u;
    else return v;
}

int BIT[12][mxn+7];
int n;
void Update(int color, int i,int v )
{
    while( i<=n ){
		BIT[color][i] += v;
        i += i & -i;
    }
}
 
int Find( int color,int i ){
	
    int s = 0;
    while( i ){
        s += BIT[color][i];
        i -= i & -i;
    }
    return s;
}

int sum[12]={0};
int ans=-100;
int mxc=0;
void getsum(int u,int v,int sign=1)
{
	for(int clr=1;clr<=mxc;clr++)
	{
		int get=Find(clr,v)-Find(clr,u-1);
		sum[clr]+=get*sign;
	}
}
void Climb(int s,int t)
{
	
	while(Chain[s]!=Chain[t])
	{
		int u=Pos[ChainLdr[Chain[t]]];
		int v=Pos[t];
		getsum(u,v);
		t=Par[ChainLdr[Chain[t]]];
	}
	
	int u=Pos[s];
	int v=Pos[t];
	getsum(u,v);
}

int initcolor[mxn];
int main()
{
	//READ("in");
	int q,t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&q);
		
		nP = 0;
		nC = 0;
        memset( BIT,0,sizeof(BIT));
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			scanf("%d",&initcolor[i]);
		}
		
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,1,0);
		HeavyLight( 1,0,true );
		
		
		for(int i=1;i<=n;i++)
		{
			mxc=max(mxc,initcolor[i]);
			Update(initcolor[i],Pos[i],1);
		}
		
		while(q--)
		{
			int com;
			scanf("%d",&com);
			mem(sum,0);
			if(com==1)
			{
				
				int u,v;
				scanf("%d%d",&u,&v);
				int lca=LCA(u,v);
				ans=-100;
				Climb(lca,u);
				Climb(lca,v);
				getsum(Pos[lca],Pos[lca],-1);
				for(int i=1;i<=mxc;i++)
				ans=max(ans,sum[i]);
					
				printf("%d\n",ans);
			}
			else
			{
				int u,c;	
				scanf("%d%d",&u,&c);
				mxc=max(mxc,c);
				getsum(Pos[u],Pos[u]);
				
				for(int i=1;i<=mxc;i++)
				if(sum[i]==1)
				{
					Update(i,Pos[u],-1);
					Update(c,Pos[u],+1);
					break;
				}
			}
			
			
		}
	}
}

