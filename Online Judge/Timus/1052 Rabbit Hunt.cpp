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
#define SZ(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<i64,i64>
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
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
 
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%lld: ",++ks);

struct point 
{
	i64 x,y,id;
	point(i64 x,i64 y):x(x),y(y){}
	point(i64 x,i64 y,i64 id):x(x),y(y),id(id){}
	point(){}
	bool operator < ( const point& p ) const {      
		if(x==p.x) return y<p.y;
		return x<p.x;
	}
	bool operator == ( const point& p ) const {      
		return (x==p.x and y==p.y);
	}
};
point p0; //Origin of comparision
point slope(const point &a,const point &b)
{
    return point(b.y-a.y,b.x-a.x);
}
bool cmp(point a,point b) 
{
	return (b.x-p0.x)*(a.y-p0.y)-(a.x-p0.x)*(b.y-p0.y)<0;
}
point reduce(point p)
{
	if(p.x==0) return point(0,1);
	if(p.y==0) return point(1,0);
	i64 g=__gcd(p.x,p.y);
	p.x/=g;
	p.y/=g;
	return point(p.x,p.y);
	
}
int maxColinearPoints(vector<point>v)
{
	int n=SZ(v);
	int ret=0;
    for(int i=0;i<n;i++)
    {
            point origin=v[i];
            vector< point>tmp;
            int maxi=0;
            for(int j=0;j<n;j++)if(i!=j)
                 tmp.pb(reduce(slope(v[j],origin)));
            sort(all(tmp));
			int c=0;
            rep(j,SZ(tmp))
            {
				if(!j or tmp[j]==tmp[j-1]) c++;
				else c=1;
				maxi=max(maxi,c);
			}
            ret=max(ret,maxi+1);

   }
        return ret;
}
#define mx 10002

int main()
{	
//	READ("in");
	//WRITE("out");
	int n;
	cin>>n;
	vector<point>v;
	rep(i,n)
	{
		int x,y;
		sdii(x,y);
		v.pb(point(x,y));
		
	}
	cout<<maxColinearPoints(v)<<endl;
	return 0;
}
