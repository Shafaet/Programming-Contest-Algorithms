/*
 *  Shafaetsplanet.com
 *  2D Segment Tree
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
#define SDs(x) scanf("%s",x)
#define uu first
#define vv second

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

int fx[]={0,0,-1,+1,-1,-1,+1,+1};
int fy[]={-1,+1,0,0,-1,+1,-1,+1};

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=Reset(N,pos);return N=Set(N,pos);}
void PBIT(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}


int mat[503][503];
struct data
{	
	int tree2d[503*3];
	int tree2dmin[503*3];
};
data tree[503*3];

int max_x,max_y;

void init2d(int par,int node,int y1,int y2,int x1,int x2)
{
	if(y1==y2)
	{
		tree[par].tree2d[node]=mat[y1][x1];
		tree[par].tree2dmin[node]=mat[y1][x1];
		return;
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(y1+y2)/2;
	init2d(par,Left,y1,mid,x1,x2);
	init2d(par,Right,mid+1,y2,x1,x2);
	tree[par].tree2d[node]=max(tree[par].tree2d[Left],tree[par].tree2d[Right]);
	tree[par].tree2dmin[node]=min(tree[par].tree2dmin[Left],tree[par].tree2dmin[Right]);
}
void init2d2(int par,int node,int y1,int y2,int x1,int x2)
{
	if(y1==y2)
	{
		tree[par].tree2d[node]=max(tree[par*2].tree2d[node],tree[par*2+1].tree2d[node]);
		tree[par].tree2dmin[node]=min(tree[par*2].tree2dmin[node],tree[par*2+1].tree2dmin[node]);
		return;
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(y1+y2)/2;
	init2d2(par,Left,y1,mid,x1,x2);
	init2d2(par,Right,mid+1,y2,x1,x2);
	tree[par].tree2d[node]=max(tree[par].tree2d[Left],tree[par].tree2d[Right]);
	tree[par].tree2dmin[node]=min(tree[par].tree2dmin[Left],tree[par].tree2dmin[Right]);
}
void init(int node,int x1,int x2)
{
	if(x1==x2)
	{
		init2d(node,1,1,max_y,x1,x2);
		
		return;
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(x1+x2)/2;
	init(Left,x1,mid);
	init(Right,mid+1,x2);
	init2d2(node,1,1,max_y,x1,x2);
	
	
}

pii query2d(int par,int node,int b,int e,int x1,int x2,int y1,int y2)
{
	if(b>y2 or e<y1) return pii(-1,1<<28);
	if(b>=y1 and e<=y2)
	{
		return pii(tree[par].tree2d[node],tree[par].tree2dmin[node]);
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(b+e)/2;
	pii p1=query2d(par,Left,b,mid,x1,x2,y1,y2);
	pii p2=query2d(par,Right,mid+1,e,x1,x2,y1,y2);
	return pii(max(p1.first,p2.first),min(p1.second,p2.second));
}
pii query(int node,int b,int e,int x1,int x2,int y1,int y2)
{
	
	if(b>x2 or e<x1) return pii(-1,1<<28);
	if(b>=x1 and e<=x2)
	{
	        
			return query2d(node,1,1,max_y,x1,x2,y1,y2);
		
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(b+e)/2;
	
	pii p1=query(Left,b,mid,x1,x2,y1,y2);
	pii p2=query(Right,mid+1,e,x1,x2,y1,y2);
	return pii(max(p1.first,p2.first),min(p1.second,p2.second));
	
}
void update2d(int par,int node,int b,int e,int x,int y,int val)
{
	
	if(b>y or e<y) return;
	
	if(b==e)
	{
		tree[par].tree2d[node]=val;
		tree[par].tree2dmin[node]=val;
		return;
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(b+e)/2;
	update2d(par,Left,b,mid,x,y,val);
	update2d(par,Right,mid+1,e,x,y,val);
	
	tree[par].tree2d[node]=max(tree[par].tree2d[Left],tree[par].tree2d[Right]);
	
	tree[par].tree2dmin[node]=min(tree[par].tree2dmin[Left],tree[par].tree2dmin[Right]);
}
void update(int node,int b,int e,int x,int y,int val)
{

	if(b>x or e<x) return;
	
	if(b==e)
	{
		
		update2d(node,1,1,max_y,x,y,val);
		return;
	}
	int Left=node*2;
	int Right=Left+1;
	int mid=(b+e)/2;
	update(Left,b,mid,x,y,val);
	update(Right,mid+1,e,x,y,val);
	 init2d2(node,1,1,max_y,b,e);
}



int main(){
	//READ("in");

	cin>>max_y>>max_x;
	repl(i,max_y) repl(j,max_x)sdi(mat[i][j]);
	init(1,1,max_x);
	
	int q;
	sdi(q);
	while(q--)
	{
		char s[3];
		scanf("%s",s);
		if(s[0]=='q')
		{
			int u1,v1,u2,v2,x1,x2,y1,y2;
			sdi(u1);sdi(v1);
			sdi(u2);sdi(v2);
			x1=v1; y1=u1;
			x2=v2; y2=u2;
			if(y2<y1) swap(y2,y1);
			pii ret=query(1,1,max_x,x1,x2,y1,y2);
			printf("%d %d\n",ret.first,ret.second);
			
		}
		else
		{
			int u1,v1,val,x1,y1;
			sdi(u1);sdi(v1);
			sdi(val);
			x1=v1; y1=u1;
			update(1,1,max_x,x1,y1,val);
		}
	}
}

