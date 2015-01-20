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
#define pii pair<int,int>
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
double dist3d(double x1,double y1,double z1,double x2,double y2,double z2){	return sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));}
struct point
{
	double x,y,z;
	point(double a,double b,double c)
	{
		x=a;
		y=b;
		z=c;
	}
};
double get(double x1,double y1,double z1,double x2,double y2,double z2,double x3,double y3,double z3,double t)
{
	point p1=point (x1+t*(x2-x1),y1+t*(y2-y1),z1+t*(z2-z1));
	
	return dist3d(p1.x,p1.y,p1.z,x3,y3,z3);
	
}
int main()
{	
	//READ("in");
	int t,kas=0;
	cin>>t;
	while(t--)
	{
		double x1,x2,x3,y1,y2,y3,z1,z2,z3;
		scanf("%lf%lf%lf",&x1,&y1,&z1);
		scanf("%lf%lf%lf",&x2,&y2,&z2);
		scanf("%lf%lf%lf",&x3,&y3,&z3);
		
		
		
		double lo=0,hi=1,ret1,ret2;
		int d = 64;
		while(d--) {
			double lt = (2 * lo + hi) / 3;
			double rt = (lo + 2 * hi) / 3;
			ret1=get(x1,y1,z1,x2,y2,z2,x3,y3,z3,lt);
			ret2=get(x1,y1,z1,x2,y2,z2,x3,y3,z3,rt);
			if(ret1>ret2) lo=lt;
			else hi=rt;
		}
		
		printf("Case %d: %.10lf\n",++kas,ret1);
	}
	
	
	return 0;
}
