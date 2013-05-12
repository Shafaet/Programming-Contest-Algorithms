/*
Shafaet
University of Dhaka
Shafaetsplanet.com

Generates a weighted tree with n node

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
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
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
 
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%d: ",++ks);


#define mx 1002


struct edg
{
	int u,v;
	edg(int u,int v):u(u),v(v){}
};
int pr[mx];
int find(int r)
{
	if(pr[r]==r) return r;
	return pr[r]=find(pr[r]);
}
void add(edg x)
{
	if(find(x.u)!=find(x.v))
		pr[find(x.u)]=find(x.v);
}
int rnd(int n){return rand()%n+1;}

int weight()
{
	int x=rand()%100;
	int p=rand()%10;
	if(p>6) x*=-1;
	return x;
}
edg getedge(int n)
{
	int u=rnd(n);
	int v=rnd(n);
	while(v==u)v=rnd(n);
	return edg(u,v);
}

bool tkn[mx][mx];
void gentree(int n)
{	
	cout<<n<<endl;
	bool vis[mx]={0};
	mem(tkn,0);
	repl(i,n)pr[i]=i;
	repl(i,n-1)
	{
		edg get=getedge(n);
		if(i==1)
		{
			add(get);
			tkn[get.u][get.v]=1;
			vis[get.u]=1;
			vis[get.v]=1;
		}
		else 
		{
			while(tkn[get.u][get.v] or find(get.u)==find(get.v) or (!vis[get.u] and !vis[get.v]))
			{
				get=getedge(n);
			}
			vis[get.u]=1;
			vis[get.v]=1;
			add(get);
			tkn[get.u][get.v]=1;
		}
		int u=get.u;
		int v=get.v;
		int w=weight();
		printf("%d %d %d\n",u,v,w);
	}
}
int main()
{	
	srand(111); 
	gentree(10);
	return 0;
	
}


