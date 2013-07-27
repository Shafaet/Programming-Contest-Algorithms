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
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);


#define mx 100002
typedef i64 T;
struct point
{
	    
		T x,y;
		int id;
		point(T x, T y) : x(x), y(y) {}
		point(T x, T y,int id) : x(x), y(y),id(id) {}
		point() : x(), y() {}

		bool operator < ( const point& p ) const 
		{
			if(x==p.x) return y<p.y;
			return x<p.x;
		}
		bool operator == ( const point& p ) const {return (x==p.x and y==p.y);}
		point operator - ( const point& p ) const {return point(x-p.x,y-p.y);} 
		point operator + ( const point& p ) const {return point(x+p.x,y+p.y);} 
		
};
struct line 
{	
		point p1,p2;
		i64 a,b,c;
		line(point _px,point _py)
		{
			p1=_px;	p2=_py;
			a = p1.y - p2.y;
			b = p2.x - p1.x;
			c = p1.x * p2.y - p2.x * p1.y;
		}
		line(){}
};
inline bool eq(double a, double b) { return fabs( a - b ) < eps; }
int triarea2(point a, point b, point c){
		return (a.x*b.y+b.x*c.y    +c.x*a.y-a.y*b.x    -b.y*c.x-c.y*a.x);
	}
bool isParallel( line L1, line L2) 
{
		int det = L1.a * L2.b - L1.b * L2.a;
		
		if(det==0) return true;
		return false;
}
bool issame(line L1,line L2)
{
	if(triarea2(L1.p1,L2.p1,L2.p2)==0 and triarea2(L1.p2,L2.p1,L2.p2)==0) return 1;
	return 0;
}

int main(){
	//READ("in");
	vector<line>v;
	int w,n;
	cin>>w>>n;
	rep(i,n)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		line temp=line(point(x1,y1),point(x2,y2));
		int flag=1;
		rep(j,sz(v))
		{
			if(issame(v[j],temp)) flag=0;
		}
		if(flag)
			v.pb(temp);
		
	}
	n=sz(v);
	int par=1;
	int tot=2*n;
	rep(i,n)
		rep(j,n)if(i!=j)if(isParallel(v[i],v[j])==0) par=0;
		
	if(par) tot=n+1;
	
	if(tot>=w){
		puts("0");
		return 0;
	}
	
	
	int m=1;
	while(1)
	{
		if(2*(n+m)>=w) break;
		m++;
	}
	pfi(m);
	
	return 0;
}

