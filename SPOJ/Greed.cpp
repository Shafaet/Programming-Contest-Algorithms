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

//Hungarian start
const int MAXN=507;
int n1, n2;
const int INT_INF=1<<30;
int lx[MAXN], ly[MAXN], pre[MAXN];
bool ux[MAXN], uy[MAXN];
int cost[MAXN][MAXN];
bool dfs(int v) {
     ux[v] = 1;
     for (int i = 0; i < n2; i++) {
         if (!uy[i] && lx[v]+ly[i] == cost[v][i]) {
            uy[i] = 1;
            if (pre[i] == -1 || dfs(pre[i]) ) {
               pre[i] = v;
               return true;
            }
         }
     }
     return false;
}
 
int km() {
    int i, j, k;
    memset(ly,0,sizeof(ly));
    memset(pre,-1,sizeof(pre));
    for (i = 0; i < n1; i++)
        lx[i] = -INT_INF;
    for (i = 0; i < n1; i++)
        for (j = 0; j < n2; j++)
            if (lx[i] < cost[i][j]) lx[i] = cost[i][j];
    for (i = 0; i < n1; i++) {
        memset(ux,0,sizeof(ux));
        memset(uy,0,sizeof(uy));
        if(!dfs(i)) {
           int Min = INT_INF;
           for (j = 0; j < n1; j++) if (ux[j])
               for (k = 0; k < n2; k++)
                   if (!uy[k] && lx[j]+ly[k]-cost[j][k] < Min)
                      Min = lx[j]+ly[k]-cost[j][k];
           for (j = 0; j < n1; j++) if (ux[j]) lx[j] -= Min;
           for (j = 0; j < n2; j++) if (uy[j]) ly[j] += Min;
           i--;
        }
    }
    int ans = 0;
    for (i = 0; i < n2; i++)
        ans += cost[pre[i]][i];
    return ans;
}
//Hungarian Ends

#define MAXX 30000000 //Maximum number of input character
char *ipos, *opos, InpFile[MAXX], OutFile[MAXX], DIP[30];
inline int input_int(int flag = 0)
{
         while(*ipos <= 32) ++ipos;
         if ( flag ) return (*ipos++ - '0');
         int x = 0, neg = 0; char c;
         while( true )
         {
                  c = *ipos++; if(c == '-') neg = 1;
                  else
                  {
                           if(c <= 32) return neg ? -x : x;
                           x = (x << 1) + (x << 3) + c - '0';
                  }
         }
}
#define ii input_int()
inline void InitFASTIO()
{
         ipos = InpFile; opos = OutFile;
         fread_unlocked(InpFile, MAXX, 1, stdin);
}
 
inline void FlushFASTIO()
{
         fwrite_unlocked(OutFile, opos - OutFile, 1, stdout);
}

#define mx 1012
int mat[mx][mx];
int main()
{	
	//READ("in");
	//WRITE("out");
	InitFASTIO();
	int t;
	t=ii;
	while(t--)
	{
		
		int a[mx];
		int n;
		n=ii;
		repl(i,n)
			a[i]=ii;
		repl(i,n)
			repl(j,n)
			{

				if(i==j) mat[i][j]=0;
				else mat[i][j]=1<<28;
		
			}
		int e;
	    e=ii;
		rep(i,e)
		{
			int u,v;
			u=ii;
			v=ii;
			mat[u][v]=mat[v][u]=1;
		}
		
		repl(k,n)
			repl(i,n)
				repl(j,n)
					mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
					
		repl(i,n)
		{
			repl(j,n)
			{
				int x=mat[a[i]][j];
				cost[i-1][j-1]=-x;
			}
		}
		n1=n2=n;
		
		pfi(-km());
	}
	
	
	return 0;
}
