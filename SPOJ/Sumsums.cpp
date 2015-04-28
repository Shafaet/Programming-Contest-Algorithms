//Programming Contest Template
//Shafaet Ashraf 
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
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1LL<<(pos)))
#define off(n,pos)  n & ~(1LL<<pos)
#define ison(n,pos) (bool)(n & (1LL<<(pos)))
string toBin(int n){ string s; repv(i,10)s+=(ison(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);


#define MAX 50000+2

i64 fixmod(i64 a,i64 m)
{
	return (a%m + m)%m;
}
struct matrix{
	#define dim 2
	#define i64 long long 
	int n,mod;
	i64 grid[dim][dim];
	matrix(int a,int b) {n=a,mod=b; mem(grid,0);}
	
	matrix operator * (const matrix &b) {
		matrix ret(n,mod);
		rep(i,n) rep(j,n) rep(k,n)
		{
			i64 a=fixmod(grid[i][k]*b.grid[k][j],mod);
			ret.grid[i][j]= fixmod(ret.grid[i][j]+ a,mod);
		}
		return ret;
	};
	
	void power(int p)
	{
		if(p<=1) return ;
		if(p%2){
			matrix temp(n,mod);
			rep(i,n) rep(j,n) rep(k,n) temp.grid[i][j]=grid[i][j];
			power(p-1);
			(*this)=(*this)*temp;
		}
		else { (*this)=(*this)*(*this); power(p/2); }
	}
	
	void print()
	{
		rep(i,n) { rep(j,n) cout<<grid[i][j]<<" "; puts(""); }
	}
	#undef dim
	#undef i64
	
};
i64 a[MAX];
int main() {   
  //READ("in");
  i64 mod=98765431;
  matrix m=matrix(2,mod);
  int n,p;
  cin>>n>>p;
  m.grid[0][0]=-1;
  m.grid[0][1]=1;
  m.grid[1][0]=0;
  m.grid[1][1]=n-1;
  
  m.power(p);
  //m.print();
  i64 sum=0;
  for(int i=1;i<=n;i++)
  {
	  cin>>a[i];
	  a[i]=a[i]%mod;
	  sum+=a[i];
	  sum%=mod;
  }
  
  for(int i=1;i<=n;i++)
  {
	  i64 ans=(a[i]*m.grid[0][0])%mod + (sum*m.grid[0][1])%mod;
	  ans=(ans%mod+mod)%mod;
	  cout<<ans<<endl;
  }
  return 0;
}
