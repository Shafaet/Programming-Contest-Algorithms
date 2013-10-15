/*
	Author: Shafaet
	Spoj SNAKYNUM
	Matrix Expo
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
typedef  long long i64;
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
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);








#define size 26

    i64 mat[size][size], tmp[size][size], res[size][size];
    i64 MOD;
    int n;
    void init(int _n, i64 _MOD) 
    {
		n = _n;
		MOD = _MOD;
		
		mem(mat, 0);
		mem(tmp, 0);
		mem(res, 0);
    } 
    void mul(i64 r[][size], i64 a[][size], i64 b[][size]) 
    {
		rep(i, n) rep(j, n) 
		{
			i64 val = 0;
			rep(t, n) 
			{
				val += 1LL * a[i][t] * b[t][j];
				if(val>=MOD)val%=MOD;
			}
			tmp[i][j] = val;
			
		}
		memcpy(r, tmp, n * size * sizeof(tmp[0][0]));
    }
    void mPow(i64 r[][size], i64 a[][size], int p) {
	if (p < 0)
	    return;
	mem(r, 0);
	rep(i, n) r[i][i] = 1;
	while (p > 0) {
	    if (p & 1)
		mul(r, r, a);
	    mul(a, a, a);
	    p >>= 1;
	}
    }
    void pow(int p) {
		mPow(res, mat, p);
		memcpy(mat, res, n * size * sizeof(tmp[0][0]));
    }
	



struct duo
{
	int pre,sign;
	duo(int a,int b){
		pre=a;
		sign=b;
	}
	duo(){}
}T[550];
int ulta[52][52];

int main() {
	//READ("in");
	//WRITE("out");
	
	
	
	
		int dim=0;
		for(int pre=0;pre<=9;pre++)
		{
			int sign=1;
			T[dim]=duo(pre,sign);
			ulta[pre][sign]=dim;
			dim++;
		}
		for(int pre=0;pre<=9;pre++)
		{
			int sign=0;
			T[dim]=duo(pre,sign);
			ulta[pre][sign]=dim;
			dim++;
		}
		
		
		
	int sav[]={285,276,259,235,205,170,131,89,45,0,0,36,72,107,140,170,196,217,232,240};
	
	int t;
	sdi(t);
	while(t--)
	{
		int len;
		sdi(len);
		int mod;
		sdi(mod);
		init(23,mod);
		
		dim=20;
		
		for(int pre=0;pre<=9;pre++)
		{
			int sign=1;
			int row=ulta[pre][sign];
			for(int i=pre+1;i<=9;i++)
			{
				int col=ulta[i][!sign];
				mat[row][col]=1;
			}
		}
		
		
		for(int pre=0;pre<=9;pre++)
		{
			int sign=0;
			int row=ulta[pre][sign];
			for(int i=pre-1;i>=0;i--)
			{
				int col=ulta[i][!sign];
				mat[row][col]=1;
			}
			
		}
		
		int krow=dim++;
		
		int col1=ulta[0][1];
		int col2=ulta[9][0];
		mat[krow][col1]=1;
		mat[krow][col2]=1;
		
		int grow=dim++;
		int gprev=dim++;
		
		mat[grow][grow]=1;
		mat[grow][krow]=1;
		mat[gprev][grow]=1;
				
		pow(len-1);
		i64 ans=0;
		ans=0;
		
		for(int col=0;col<dim;col++)
		{
			i64 cval=mat[grow][col],barval;
			if(col<20)barval=sav[col];
			
			else if(col==20) barval=81;
			else if(col==21) barval=10;
			else if(col==22) barval=0;
			
			ans+=cval*barval;
			if(ans>=mod)
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
