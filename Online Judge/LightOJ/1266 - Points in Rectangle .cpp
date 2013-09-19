/*
 *  Shafaetsplanet.com
 *  LightOJ 1266 - Points in Rectangle 
 *  2D-Binary Indexed Tree
 *  Operations: Add point in a grid, find number of points in a rectangle
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


int n=1022;
#define max_x 1026
#define max_y 1026

int tree[max_x+100][max_y+100];
void update(int x , int y , int val){
	while (x <= n)
	{
		int y1=y;
		while (y1 <= n)
		{
			tree[x][y1] += val;
			y1 += (y1 & -y1); 
		}
		x += (x & -x); 
	}
}

int find(int x,int y)
{
	if(x<=0 or y<=0) return 0;
	
	int ret=0;
	while(x>0)
	{		
		int y1=y;
		while(y1>0)
		{
			ret+=tree[x][y1];
			y1 -= (y1 & -y1);
		}
		
		x -= (x & -x);
	}
	return ret;
}

int getsum(int x1,int y1,int x2,int y2)
{
	return find(x2,y2)-find(x1-1,y2)-find(x2,y1-1)+find(x1-1,y1-1);
}
int main(){
//	READ("in");
	
	int t,kas=0;
	sdi(t);
	while(t--)
	{
		int q;
		
		
		mem(tree,0);
		cin>>q;
		//cout<<q<<endl;
		printf("Case %d:\n",++kas);
		while(q--)
		{
			int com;
			sdi(com);
			
			
			if(com==0)
			{
				int u,v;
				sdi(u);sdi(v);
				u++;
				v++;
			//	cout<<u<<" "<<v<<" "<<getsum(u,v,u,v)<<endl;
				update(u,v,-getsum(u,v,u,v));
				update(u,v,1);
			}
			else
			{
				int x1,y1,x2,y2;
				sdi(x1);sdi(y1);
				sdi(x2);sdi(y2);
				x1++; y1++;
				x2++; y2++;
				int ans=getsum(x1,y1,x2,y2);
				printf("%d\n",ans);
				
			}
		}
	
		
	}
	
}

