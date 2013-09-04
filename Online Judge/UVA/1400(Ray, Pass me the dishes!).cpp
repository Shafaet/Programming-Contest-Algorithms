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
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<i64,i64>
#define pmp make_pair


#define SDi(x) scanf("%d",&x)
#define SDii(x,y) scanf("%d%d",&x,&y)

#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E16;

#define MX 510000
int a[MX];
struct trio
{
	int l,r;
	i64 v;
	trio(int a,int b,i64 c)
	{
		l=a;
		r=b;
		v=c;
	}
	trio(){};
};
struct data
{
	int l,h;
	trio prefix,suffix,best;
	i64 sum;

	data(){}
	
}x[MX*3];

trio triomax(const trio &a,const trio &b)
{
	if(a.v>b.v) return a;
	else if(a.v<b.v) return b;
	else if(a.v==b.v)
	{
		if(a.l<b.l) return a;
		else if(a.l>b.l) return b;
		else if(a.l==b.l)
		{
			if(a.r<b.r) return a;
			return b;
		}
	}
}
trio update_prefix(const data &Left, const data &Right)
{
//	cout<<">>>>>"<<Left.l<<endl;
	trio temp=trio(Left.l,Right.prefix.r,Left.sum+Right.prefix.v);
		return triomax(temp,Left.prefix);
}
trio update_suffix(const data &Left, const data &Right)
{
	trio temp=trio(Left.suffix.l,Right.h,Right.sum+Left.suffix.v);
		return triomax(temp,Right.suffix);
	
}

void init(int node,int b,int e)
{
	if(b==e)
	{
		x[node].l=b;
		x[node].h=e;
		x[node].prefix=x[node].suffix=x[node].best=trio(b,e,a[b]);
		x[node].sum=a[b];
	}
	else
	{		
		int mid=(b+e)/2;
		int Left=(node*2);
		int Right=(node*2)+1;
		init(Left,b,mid);
		init(Right,mid+1,e);
			x[node].l=b;
		x[node].h=e;
		
		x[node].prefix=update_prefix(x[Left],x[Right]);
		x[node].suffix=update_suffix(x[Left],x[Right]);
		
		trio temp=trio(x[Left].suffix.l,x[Right].prefix.r,x[Left].suffix.v+x[Right].prefix.v);
		x[node].best=triomax(temp,triomax(x[Left].best,x[Right].best));
		x[node].sum=x[Right].sum+x[Left].sum;
		//cout<<b<<" "<<e<<" "<<x[node].prefix.l<<" "<<x[node].prefix.r<<" "<<x[node].prefix.v<<endl;
	}

}
i64 const inff=1e13;
data query(int node,int b,int e,int i,int j)
{
	data p1, p2;
	 if (i > e || j < b)
	 {
		 data temp;
		 temp.sum=inff;
		return temp;
	}
	
	 if(b>=i and e<=j)
     {
		 return x[node];		 
	 }
	int mid=(b+e)/2;
			
	int Left=(node*2);
	int Right=(node*2)+1;
    p1 = query(Left, b,mid,  i, j);
    p2 = query(Right, mid+1, e, i, j);
    if(p1.sum==inff) return p2;
    if(p2.sum==inff) return p1;
    
    data ret;
    ret.prefix=update_prefix(p1,p2);
    ret.suffix=update_suffix(p1,p2);
    
    trio temp=trio(p1.suffix.l,p2.prefix.r,p1.suffix.v+p2.prefix.v);
		
    ret.best=triomax(temp,triomax(p1.best,p2.best));
    ret.sum=p1.sum+p2.sum;
    //cout<<b<<" "<<e<<" "<<ret.prefix.v<<" "<<ret.prefix.l<<" "<<ret.prefix.r<<endl;
    return ret;
	
}
int main()
{
	//READ("in");
//	WRITE("out");
	
	int n,ks=0;
	while(SDi(n)==1)
	{
//		mem(x,0);
		printf("Case %d:\n",++ks);
		int q;
		SDi(q);
		repl(i,n)
		{
			SDi(a[i]);
		//	cout<<a[i]<<" ";
		}
		init(1,1,n);
		
		rep(i,q)
		{
			int lo,hi;
			SDii(lo,hi);
			data ret=query(1,1,n,lo,hi);

			printf("%d %d\n",ret.best.l,ret.best.r);
			
		}
	}
}
	
