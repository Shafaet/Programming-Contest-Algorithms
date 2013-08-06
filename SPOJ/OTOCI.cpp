//Heavy Light Decomposition+Union Find

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
#define INT_MAX 2147483647
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
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
int fx[]={0,0,1,-1};
int fy[]={-1,1,0,0};
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

#define mxn 300002

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
		if(g[u][i]==from) continue;
		SubT[u]+=dfs(u,g[u][i],dep+1);
	}
	return SubT[u];
	
}
int nC=0,nP=0;
void HeavyLight(int u,int k,int isLight)
{
	if(isLight)	k=++nC,ChainLdr[k]=u;
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
		if(Level[ChainLdr[Chain[u]]]<Level[ChainLdr[Chain[v]]])	v = Par[ChainLdr[Chain[v]]];
		else u = Par[ChainLdr[Chain[u]]];
	}
	if( Level[u] < Level[v] ) return u;
    else return v;
}

int BIT[mxn+10];
int n;
void BitUpdate(int i,int v )
{
    while( i<=n ){
		BIT[i] += v;
        i += i & -i;
    }
}
int BitFind(int i ){
	
    int s = 0;
    while( i ){
        s += BIT[i];
        i -= i & -i;
    }
    return s;
}
int bitsum(int u,int v)
{
	return BitFind(v)-BitFind(u-1);
}

int treesum(int s,int t)
{
	int sum=0;
	while(Chain[s]!=Chain[t])
	{
		int u=Pos[ChainLdr[Chain[t]]];
		int v=Pos[t];
		
		sum+=bitsum(u,v);
		t=Par[ChainLdr[Chain[t]]];
	}
	
	int u=Pos[s];
	int v=Pos[t];
	sum+=bitsum(u,v);
	return sum;
}
int query(int u,int v)
{
	
	int lca=LCA(u,v);
	
	return treesum(lca,u)+treesum(lca,v)-bitsum(Pos[lca],Pos[lca]);
}
void update(int u,int val)
{
	u=Pos[u];
	int sum=bitsum(u,u);
	BitUpdate(u,-sum);
	BitUpdate(u,val);
}
void build()
{
	nP=0;
	nC=0;
	for(int i=1;i<=n;i++)
		if(SubT[i]==0)
		{			
			dfs(0,i,0);
			HeavyLight( i,0,true );
		}
}

int a[mxn];
int type[mxn];
int par1[mxn],par2[mxn];

int pr[mxn];
int find(int r)
{
	return (pr[r]==r)?r:pr[r]=find(pr[r]);
}
int main(){
	
	//READ("otoci/otoci.in.7");
	//WRITE("otoci/myout");
	sdi(n);
	repl(i,n){sdi(a[i]);pr[i]=i;}
	
	int e;
	sdi(e);
	int pf=0;
	repl(i,e)
	{
		char s[12];
		sds(s);
		if(s[0]=='e')
		{
			pf++;
			type[i]=1;
			int a,b;
			sdii(a,b);
			par1[i]=a;
			par2[i]=b;
		}
		if(s[0]=='b')
		{
			pf++;
			type[i]=2;
			int a,b;
			sdii(a,b);
			par1[i]=a;
			par2[i]=b;
			if(find(a)==find(b))continue;
			pr[find(a)]=find(b);
			g[a].pb(b);
			g[b].pb(a);
			
		}
		if(s[0]=='p')
		{
			type[i]=3;
			sdi(par1[i]);
			sdi(par2[i]);
		}
	}

	
	build();
	
	for(int i=1;i<=n;i++)
	{
		pr[i]=i;
		update(i,a[i]);
	}
	

	
	for(int i=1;i<=e;i++)
	{
		
		if(type[i]==1)
		{
			int u=par1[i];
			int v=par2[i];
			
			if(find(u)!=find(v)) puts("impossible");
			else{
				
				 pfi(query(u,v));
			 }
		}
		if(type[i]==2)
		{
			int u=par1[i];
			int v=par2[i];
			if(find(u)==find(v))puts("no");
			else
			{
				puts("yes");
				pr[find(u)]=find(v);
			}
		}
		if(type[i]==3)
		{
			int u=par1[i];
			int x=par2[i];
			update(u,x);
		}
	}
	
	
	return 0;
}

