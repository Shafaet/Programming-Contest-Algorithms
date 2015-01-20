/*
 * UVA Live archive 4538 Here's a Product Which Will Make You Tensor
 * Math, matrices,gcd
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
int r,c;
vector<int>sav[522];
int mat[555][555];
int base[555][555],gc;

int numdiv[95526];
int istensor(int a,int b)
{
	
	gc=mat[0][0];
	int mngc=gc;
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			base[i][j]=mat[i][j];
			gc=__gcd(gc,base[i][j]);
			
			
		}
		
	}
	
	for(int i=0;i<a;i++)for(int j=0;j<b;j++)base[i][j]/=gc;
	
	int megagc=gc;
	for(int i=0;i+a-1<r;i+=a)
	{
		for(int j=0;j+b-1<c;j+=b)
		{
			int newgc=mat[i][j];
			for(int k=i;k<=i+a-1;k++)
			{
				for(int m=j;m<=j+b-1;m++)
				{
					newgc=__gcd(mat[k][m],newgc);
					megagc=__gcd(megagc,newgc);
					mngc=min(mngc,newgc);
			
				}
			
			}
			
			for(int k=i,bi=0;k<=i+a-1;k++,bi++)
			{
				for(int m=j,bj=0;m<=j+b-1;m++,bj++)
				{
					if(mat[k][m]/newgc!=base[bi][bj]){
						return 0;
					}
				}
			}
			
		}
	}
	return numdiv[megagc];
}

int main(){
	
	//READ("in");
	//WRITE("out2");
	numdiv[1]=1;
	for(int i=2;i<=65536;i++)
	{
		
		int c=0;
		int sq=sqrt(i);
		for(int j=1;j<=sq;j++)
		{
			if(i%j==0)
			{
				if(i<=500) sav[i].pb(j);				
				c++;
				if(i/j!=j ) {
					if(i<=500)sav[i].pb(i/j);
					c++;
				}
			}
		}
		numdiv[i]=c;
	}
		
	while(cin>>r>>c)
	{
		if(!r and !c) break;
		rep(i,r)
		{
			rep(j,c)
			{
				sdi(mat[i][j]);
			}
		}
		int ans=0;
		rep(i,sz(sav[r]))
		{
			rep(j,sz(sav[c]))
			{
				int a=sav[r][i];
				int b=sav[c][j];
				if(a*b==1) continue;
				if(a*b==r*c) continue;
	
				ans+=istensor(a,b);
			}
		}

		pfi(ans);
	}
	

	return 0;
}

