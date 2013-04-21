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

#define mx 100012

vector<int>g[mx];
int e1,e2,mxdep=0;
void dfs(int from,int u,int dep,int flag)
{
	
	if(dep>mxdep)
	{
		mxdep=dep;
		if(flag==1)	e1=u;
		else e2=u;
	}
	rep(i,SZ(g[u]))
	{
		int v=g[u][i];
		if(v==from) continue;
		dfs(u,v,dep+1,flag);
	}
}

void call(int par,int u,int dep,int *d)
{
	d[u]=dep;
	rep(i,g[u].size())
	{
		int v=g[u][i];
		if(v==par) continue;
		call(u,v,dep+1,d);
	}
	
}
int d1[mx],d2[mx];
int far[mx],fd[mx];



int L[mx];
int P[mx][22];
int T[mx];
void dfs2(int from,int u,int dep)
{
	T[u]=from;
	L[u]=dep;
	rep(i,SZ(g[u]))
	{
		int v=g[u][i];
		if(v==from) continue;
		dfs2(u,v,dep+1);
	}
}

int kth(int u,int k)
{
	if(k==0) return u;
	int i=0;
	while((1<<i)<=k) i++;
	i--;
	//cout<<(1<<i)<<endl;
	return kth(P[u][i],k-(1<<i));
	
}

int lca_query(int N, int p, int q)
  {
      int tmp, log, i;
    
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


void lca_init(int N)
  {
      int i, j;
	  mem(P,-1); 
       for (i = 1; i <= N; i++)
          P[i][0] = T[i];
    
      for (j = 1; 1 << j < N; j++)
         for (i = 1; i <= N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
  

int main(){
	
//	READ("in");
	int n,q;
	cin>>n>>q;
	rep(i,n-1)
	{
		int u,v;
		sdii(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,1,0,1);
	mxdep=0;
	dfs(0,e1,0,2);
	
	
	call(0,e1,0,d1);
	call(0,e2,0,d2);
	
	repl(i,n)
	{
		int v,d;
		if(d1[i]>d2[i]){ v=e1;d=d1[i];}
		else {v=e2;d=d2[i];}
		far[i]=v;
		fd[i]=d;
		//cout<<i<<" "<<far[i]<<" "<<fd[i]<<endl;
	}
	dfs2(-1,1,0);
	lca_init(n);
	
	
	repl(lp,q)
	{
	   int u,d;
	   sdii(u,d);
	   int v=far[u];
	   int uv=fd[u];
	   int lca=lca_query(n,u,v);
	   
	   //cout<<u<<" "<<v<<" "<<lca<<" "<<uv<<endl;
	   if(uv<d) puts("0");
	   else if(L[u]-L[lca]<d)
	   {
		    int baki=d-(L[u]-L[lca]);
		    int lv=L[v]-L[lca];
		    int k=lv-baki;
		    int ans=kth(v,k);
			//cout<<u<<" "<<v<<" -> "<<uv<<" "<<k<<endl;	   
			cout<<ans<<endl;
	   }
	   else if(L[u]-L[lca]>=d)
	   {
		   int k=d;
		   int ans=kth(u,k);
		   cout<<ans<<endl;
	   }
	   
	}
	
	return 0;

}
