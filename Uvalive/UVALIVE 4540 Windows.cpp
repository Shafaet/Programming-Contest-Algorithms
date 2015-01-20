/*
 * UVALIVE 4540 Windows
 * Grid Compression
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
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
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
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define ison(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(ison(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

struct rect{
	int x1,y1;
	int x2,y2;
	rect(int a,int b)
	{
		x1=a;y1=b;
	}
	rect(int a,int b,int c,int d)
	{
		x1=a;y1=b;
		x2=c;y2=d;
	}
	rect(){}
};
int w[1002][1002];
void fill(int lox,int loy,int hix,int hiy,int id)
{
	for(int i=lox;i<=hix;i++)
	{
		for(int j=loy;j<=hiy;j++)
		{
			w[i][j]=id;
		}
	}
}
int main(){
	
	//READ("in");
	
	int n,ks=0;
	while(cin>>n and n)
	{
		mem(w,0);
		vector<rect>box,Q;
		set<int>setX,setY;
		map<int,int>mapX,mapY;
		rep(i,n)
		{
			int x1,y1;
			cin>>x1>>y1;
			int w,h;
			cin>>w>>h;
			int x2=x1+h-1;
			int y2=y1+w-1;
			box.pb(rect(x1,y1,x2,y2));
			setX.insert(x1);
			setX.insert(x2);
			
			setY.insert(y1);
			setY.insert(y2);
			
		}
		
		int q;
		sdi(q);
		rep(i,q)
		{
			int x1,y1;
			cin>>x1>>y1;
			setX.insert(x1);
			setY.insert(y1);
			Q.pb(rect(x1,y1));
			
		}
		int maxX=0,maxY=0;
		foreach(it,setX)
		{
			mapX[*it]=++maxX;
		}
		
		foreach(it,setY)
		{
			mapY[*it]=++maxY;
		}
		rep(i,n)
		{
			int x1=box[i].x1;
			int y1=box[i].y1;
			int x2=box[i].x2;
			int y2=box[i].y2;
			x1=mapX[x1];y1=mapY[y1];
			x2=mapX[x2];y2=mapY[y2];
			int lox=min(x1,x2);
			int loy=min(y1,y2);
			int hix=max(x1,x2);
			int hiy=max(y1,y2);
			fill(lox,loy,hix,hiy,i+1);
			
			
		}
		printf("Desktop %d:\n",++ks);
		rep(i,q)
		{
			int x1=Q[i].x1;
			int y1=Q[i].y1;
			x1=mapX[x1];y1=mapY[y1];
			if(w[x1][y1]) printf("window %d\n",w[x1][y1]);
			else puts("background");
			
		}
		
		
	}
	return 0;
}

