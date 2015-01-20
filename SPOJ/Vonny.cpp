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
#define on(n,pos) n=(n | (1<<pos))
#define off(n,pos) n= n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
 
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%lld: ",++ks);


#define xx first
#define yy second
#define mx 9

struct info
{
	int x1,y1,x2,y2;
	info(int a,int b,int c,int d)
	{
		x1=a;
		y1=b;
		x2=c;
		y2=d;
		
	}
	info(){}
	
};
int board[mx][mx];
vector<pii>dom;
int row=7,col=8;
int dr[]={1,0};
int dc[]={0,1};
vector<info>loc[mx][mx];
int fil[mx][mx];
void print()
{
	
	rep(i,row)
	{
		rep(j,col)
		{
			cout<<fil[i][j]<<" ";
		}
		puts("");
	}
	puts("");
}
i64 call(int idx)
{
	if(idx==SZ(dom)) {
		return 1;
	}
	
	int x=dom[idx].xx;
	int y=dom[idx].yy;
	
	i64 ret=0;
	rep(i,SZ(loc[x][y]))
	{
		int x1=loc[x][y][i].x1;
		int y1=loc[x][y][i].y1;
		int x2=loc[x][y][i].x2;
		int y2=loc[x][y][i].y2;
		if(!fil[x1][y1] and !fil[x2][y2])
		{
			fil[x1][y1]=idx+1;
			fil[x2][y2]=idx+1;
			ret+=call(idx+1);
			fil[x1][y1]=0;
			fil[x2][y2]=0;
		}
	}
	return ret;
}
int main()
{	
	//READ("in");
	
	
	for(int i=0;i<=6;i++)
		for(int j=i;j<=6;j++)
		{			
			dom.pb(pii(i,j));
		}
		
			
		
	
	int t;
	sdi(t);
	while(t--)
	{
		rep(i,mx)
			rep(j,mx)loc[i][j].clear();
		
		
		
		rep(i,7)
			rep(j,8)
			{
				sdi(board[i][j]);
				board[i+1][j]=-1;
				board[i][j+1]=-1;
			}
		
		rep(i,row)
			rep(j,col)
			{
				rep(k,2)
				{
					int ti=i+dr[k];
					int tj=j+dc[k];
					int x=board[i][j];
					int y=board[ti][tj];
					if(y!=-1)
					{
						int a=x,b=y;
						if(a>b) swap(a,b);
						loc[a][b].pb(info(i,j,ti,tj));
					}
				}
			}
		i64 ret=call(0);
		printf("%lld\n",ret);
	}
	
	return 0;
}
