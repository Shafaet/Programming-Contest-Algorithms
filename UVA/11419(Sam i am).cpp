/*
 *  Shafaetsplanet.com
 *  Bipartite matching, konig theorem with path printing
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

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)


#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define SDs(x) scanf("%s",x)
#define uu first
#define vv second

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}

vector< string > token( string a, string b ) {
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return dist > p.dist;   }

int fx[]={0,0,-1,+1,-1,-1,+1,+1};
int fy[]={-1,+1,0,0,-1,+1,-1,+1};

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=Reset(N,pos);return N=Set(N,pos);}
void PBIT(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}





bool mat[1003][1003];

#define mx 2002
vector<int>g[mx];
bool vis[mx];
int Left[mx],Right[mx];
bool dfs(int u) {
	if(vis[u]) return false;
	vis[u] = true;
	int v;
	for(int i=0;i<(int)g[u].size();i++)
	{
		v = g[u][i];
		if(Right[v]==-1) 
		{
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(int i=0;i<(int)g[u].size();i++)
	{
		v = g[u][i];
		if(dfs(Right[v])) 
		{
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}
 


int match(int n) {
	int ret = 0;
	
	mem(Left,-1); 
	mem(Right,-1);
	while(1)
	{
		bool done = true; mem(vis,0);
		for(int i=1;i<=n;i++)
		{
			if(Left[i]==-1 && dfs(i)) 		done = false;
		}
		if(done==true) break;
	}
	for(int i=1;i<=n;i++)
	if(Left[i]!=-1) ret++;
	return ret;
}

void konig(int u,bool side)
{

	if(!side)
	{
		rep(i,g[u].size())
		{
			int v=g[u][i];
			if(vis[v]) continue;
			if(Left[u]==v) continue;
			vis[v]=1;
			konig(v,!side);
		}
	}
	else
	{
		int v=Right[u];
		if(vis[v]) return;
		vis[v]=1;
		konig(v,!side);
	}
	
}




#define MAXX 10000000
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

inline void InitFASTIO()
{
         ipos = InpFile; opos = OutFile;
         fread_unlocked(InpFile, MAXX, 1, stdin);
}
 

//End of FAST I/O

int main()
{
	READ("in");
	int r,c;
	InitFASTIO();
	while(1)
	{
		
		r=input_int();
		c=input_int();
		int q;
		q=input_int();
		
		if(!r and !c and !q) break;
		mem(mat,0);
		
		bool visR[1002]={0},visC[2002]={0};
		int idL[1002],idR[1002];
		
		int ln=0,rn=0;
		rep(i,q)
		{
			int u,v;
			u=input_int();
			v=input_int();
			
			mat[u][v]=1;

			if(!visR[u]){
				visR[u]=1;
				ln++;
				idL[ln]=u;
			}
			if(!visC[v]){
				visC[v]=1;
				rn++;
				idR[rn]=v;
			}
		}
		for(int i=1;i<=ln+rn+2;i++)
		g[i].clear();
		
		repl(i,ln)
		{
			repl(j,rn)
			{
				if(mat[idL[i]][idR[j]])
				{
					g[i].pb(j+ln);
					g[j+ln].pb(i);
				}
			}
		}
		int ret=match(ln);
		
		mem(vis,0);
		printf("%d",ret);
		
		
		for(int i=1;i<=ln;i++)	{
			if(Left[i]==-1 and !vis[i])	{
				vis[i]=1;
				konig(i,0);
			}
		}
		
		for(int i=1;i<=ln;i++)
		{
			if(vis[i]==0) {
				printf(" r%d",idL[i]);
			}
		}
		
		for(int i=1;i<=rn;i++)
		{
			if(vis[i+ln]==1) {
				printf(" c%d",idR[i]);
			}
		}
		puts("");
	}
	
}

