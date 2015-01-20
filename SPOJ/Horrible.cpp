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

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)


#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)

using namespace std;




typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)





i64 a[100004];
struct info
{
	i64 add,sum;
	info(){add=0;sum=0;}
	info(i64 _sum,i64 _add)
	{
		add=_add;
		sum=_sum;
	}
}m[400000];

void update(int node,int b,int e,int i,int j,i64 val)
{
	if (i > e || j < b)		return;
	i64 diff=(e-b+1);
	if (b >= i && e <= j)
	{
		m[node].sum+=diff*val;
		m[node].add+=val;
		return;
		
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,j,val);
	update(Right,mid+1,e,i,j,val);
	m[node].sum=m[Left].sum+m[Right].sum+diff*m[node].add;
}
i64 query(int node,int b,int e,int i,int j,i64 carry)
{
	
	if (i > e || j < b)		return 0;
	if(b>=i and e<=j)    
	{
	
		return m[node].sum+carry*(e-b+1);	
	}
	
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    i64 p1 = query(Left, b,mid,  i, j,carry+m[node].add);
    i64 p2 = query(Right, mid+1, e, i, j,carry+m[node].add);
    
    return  p1+p2;
}
//vector<int>v[1000000];
int main()
{
	
	//READ("in");
	int t,kas=0;
	cin>>t;
	while(t--)
	{
		int n,q;
		sdii(n,q);
		
		mem(m,0);
		//	printf("Case %d:\n",++kas);
		repl(i,q)
		{
			int com;
			sdi(com);
			if(com==0)
				{
					int idx,idx2,v;
					sdii(idx,idx2);sdi(v);
					
					//idx++;
					//idx2++;
					update(1,1,n,idx,idx2,v);
					
				}
			if(com==1)
				{					
					int st,en;
					sdii(st,en);
					//st++;
					//en++;
					i64 get=query(1,1,n,st,en,0);
					printf("%lld\n",get);
				}
			
		}
				
		
	}


	return 0;
}


