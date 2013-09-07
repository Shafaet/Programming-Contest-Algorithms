/*
 * Timus 1553. Caves and Tunnels 
 * Heavy Light Decomposition
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
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<i64,i64>
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
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E16;
i64 const mxn = 110000+10;
vector<i64>g_in[mxn];
vector<i64>g[mxn];

i64 vis[mxn],par_chain[mxn],child_chain[mxn],first_chain[mxn];
i64 clr[mxn],a[mxn],L[mxn],mark_rec[mxn];
i64 T[mxn],P[mxn][23];


i64 lca_query(i64 N, i64 p, i64 q)
  {
      i64 tmp, log, i;
    
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
  
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return T[p];
  }


void lca_init(i64 N)
  {
      i64 i, j;
   
   mem(P,-1); 
  
      for (i = 1; i <= N; i++)
          P[i][0] = T[i];
    
      for (j = 1; 1 << j < N; j++)
         for (i = 1; i <= N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
  


void call(i64 u,i64 dep=0)
{
	L[u]=dep;
	for(i64 i=0;i<(i64)g_in[u].size();i++)
	{
		i64 v=g_in[u][i];
		if(!vis[v])
		{
			
			vis[v]=1;
			T[v]=u;
			
			g[u].pb(v);
			call(v,dep+1);
		}
		
	}
	
}


i64 heavy_light_decomp(i64 u)
{
	i64 mx=0,idx=-1,sum=0;
	for(i64 i=0;i<(i64)g[u].size();i++)
	{
		i64 v=g[u][i];
		i64 ret=heavy_light_decomp(v);
		if(ret>mx){mx=ret; idx=v;}
		sum+=ret;
		
	}
	if(idx!=-1) 
	{
		child_chain[u]=idx;
		par_chain[idx]=u;
	}
	return sum+1;
}


void get_chains(i64 n)
{
	i64 mark=0,chain_no=0;
	for(i64 i=1;i<=n;i++)
	{
		if(par_chain[i]==-1)
		{
			++chain_no;
			i64 node=i;
			while(node!=-1)
			{
				clr[node]=++mark;
				mark_rec[mark]=node;
				first_chain[node]=i;
				node=child_chain[node];
			}
			
		}
	}
	
}
#define mx 100002

i64 tree[mx*3];

void segtree_update(i64 node,i64 b,i64 e,i64 i,i64 add)
{
	if (i > e || i < b)		return;
	if(b==e)
	{
		
			tree[node]+=add;
		
		return;
	}
	i64 Left=node<<1;
	i64 Right=(node<<1)+1;
	i64 mid=(b+e)>>1;
	segtree_update(Left,b,mid,i,add);
	segtree_update(Right,mid+1,e,i,add);
	tree[node]=max(tree[Left],tree[Right]);
		
}

i64 segtree_query(i64 node,i64 b,i64 e,i64 i,i64 j)
{
	if (i > e || j < b)		return 0;
	
	if(b>=i and e<=j)    return tree[node];	
	

	i64 Left=node<<1;
	i64 Right=(node<<1)+1;
	i64 mid=(b+e)>>1;
    i64 p1 = segtree_query(Left, b,mid,  i, j);
    i64 p2 = segtree_query(Right, mid+1, e, i, j);
    
    return  max(p1,p2);
    
}
   
i64 Heavy_light_query(i64 n,i64 src,i64 des)
{
	
	i64 flg=0;
	i64 sum=0;
	while(first_chain[src]!=first_chain[des])
	{
		i64 r1=src;
		if(src==first_chain[src])	
		{
			if(flg==0)
			{
				i64 r2=src;
				sum=max(sum,segtree_query(1,1,n,clr[r2],clr[r1]));
			}
			flg=0;
			src=T[src];
		}
		
		else
		{
			flg=1;
			src=first_chain[src];
			i64 r2=src;
			sum=max(sum,segtree_query(1,1,n,clr[r2],clr[r1]));
		}
	}
	i64 r1=src;
	i64 r2=des;
	sum=max(sum,segtree_query(1,1,n,clr[r2],clr[r1]));
	
	return sum;
	
}



i64 QUERY(i64 n,i64 u,i64 v)
{
	i64 lca=lca_query(n,u,v);
	i64 ret1=Heavy_light_query(n,u,lca);
	i64 ret2=Heavy_light_query(n,v,lca);
	
	
	return max(ret1,ret2);
	
	
	
}
void UPDATE(i64 n,i64 u,i64 w)
{
	segtree_update(1,1,n,clr[u],w);
}


int main()
{
	//READ("in");
	
	
	
		int n;
		scanf("%d",&n);
				
		for(i64 i=1;i<=n;i++)
		{

			T[i]=-1;
			g_in[i].clear();
			g[i].clear();
			
			vis[i]=0;
			child_chain[i]=-1;
			par_chain[i]=-1;
		}
		for(i64 i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			

			g_in[u].pb(v);
			g_in[v].pb(u);
		
		}
		vis[1]=1;
		call(1);
		heavy_light_decomp(1);
		get_chains(n);
		lca_init(n);
		
		i64 q;
		cin>>q;
		while(q--)
		{
			char s[100];
			scanf("%s",s);
			if(s[0]=='I')
			{
				int u,w;
				SDi(u);
				SDi(w);
				
				UPDATE(n,u,w);
			}
			else
			{
				int u,v;
				SDi(u);
				SDi(v);
				i64 ans=QUERY(n,u,v);
				printf("%lld\n",ans);
			}
		}
	
}
	

	


 
