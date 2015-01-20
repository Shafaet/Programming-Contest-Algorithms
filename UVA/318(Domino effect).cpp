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



#define mx 503
int a[mx*mx],b[mx*mx],c[mx*mx];
int w[mx][mx];
int main()
{	
//	READ("in");
	int n,e,ks=0;
	while(sdii(n,e)==2)
	{
		
		if(!n and !e) break;
		repl(i,n)
			repl(j,n)
				if(i==j) w[i][j]=0;
				else w[i][j]=1<<28;
				
		rep(i,e)
		{
			sdii(a[i],b[i]);
			
			sdi(c[i]);
			w[a[i]][b[i]]=c[i];
			w[b[i]][a[i]]=c[i];
		}
		
		repl(k,n)
			repl(i,n)
				repl(j,n)
					w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
				
		double last=0;
		int x,y,at=0;
		rep(i,e)
		{
			int u=a[i];
			int v=b[i];
			int du=w[1][u];
			int dv=w[1][v];
			int uv=c[i];
			double t;
			if(min(du,dv)+uv<=max(du,dv))
			{
				
				t=min(du,dv)+uv;
				if(t>last)
				{
					at=1;
					last=t;
					if(du<=dv) x=v;
					else x=u;
				}
			}
			else
			{	
				
				t=min(du,dv)+abs(du-dv)+(uv-abs(du-dv))/2.00;
				if(t>last)
				{
					at=0;
					last=t;
					x=u; y=v;
				}
			}
			
			//cout<<u<<" "<<v<<" "<<t<<endl;
		}
		 printf("System #%d\n",++ks);
		 if(e==0)
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n");
        else
        {
			if(at==0)
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",last,x,y);
			else 
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n",last,x);
		}
		puts("");
	}
	return 0;
}
