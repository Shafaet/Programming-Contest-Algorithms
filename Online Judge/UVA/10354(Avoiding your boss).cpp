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



#define mx 300

int w[mx][mx];
int w2[mx][mx];

int main()
{	
	//READ("in");
	
	
	int n,e,bh,bo,yh,m;
	while(cin>>n>>e>>bh>>bo>>yh>>m)
	{
			repl(i,n)
			{
				repl(j,n)
				{
					w[i][j]=1<<28;
					w2[i][j]=1<<28;
				}
				w[i][i]=0;
				w2[i][i]=0;
			}
			repl(i,e)
			{
				int u,v,c;
				sdii(u,v);
				sdi(c);
				w[u][v]=w[v][u]=min(w[u][v],c);
				w2[u][v]=w2[v][u]=min(w2[u][v],c);
			}		
			repl(k,n)
				repl(i,n)
					repl(j,n)
						w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			
			int baad[102]={0};
			repl(k,n)
			{
				if(w[bh][k]+w[k][bo]==w[bh][bo])
				{
					baad[k]=1;

				}
			}
			
			
			
			repl(k,n)
				repl(i,n)
					repl(j,n)
						if(!baad[i] and !baad[j] and !baad[k]){
						
							w2[i][j]=min(w2[i][j],w2[i][k]+w2[k][j]);
						}
			if(w2[yh][m]==1<<28 or baad[yh] or baad[m]) puts("MISSION IMPOSSIBLE.");
			else
			cout<<w2[yh][m]<<endl;
	}
	return 0;
}
