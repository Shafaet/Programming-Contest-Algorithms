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

#define mx 102


int cost[mx],pre[mx]={0},abse[mx]={0};
int newpre[mx]={0},newabs[mx]={0};
struct node
{
	int m,w;
	node(int m,int w):m(m),w(w){}
	node(){}
	bool operator < ( const node& p ) const {      return w > p.w;   }
};
int d[(1<<20)+11];
int bfs(int n,int p)
{
	int src=(1<<n)-1;
	priority_queue<node>q;
	mem(d,63);
	d[src]=0;
	q.push(node(src,0));
	
	while(!q.empty())
	{
		node top=q.top(); q.pop();
		if(top.m==0) break;
		int m=top.m;
		rep(i,p)
		{
			if( (m & pre[i])==pre[i])
			{
				if( (~m & abse[i])==abse[i])
				{
					int nm=m;
					nm=nm | newpre[i];
					nm=nm & newabs[i];
					int w=cost[i];
					if(d[m]+w<d[nm])
					{
						d[nm]=d[m]+w;
						q.push(node(nm,d[nm]));
					}
				}
				
			}
			
		}
	}
	return d[0];
}
int main(){
	
	READ("in");
	int n,p,ks=0;
	while(sdii(n,p)==2)
	{
		if(!n and !p) break;
		
		
		mem(pre,0);
		mem(abse,0);
		mem(newpre,0);
		mem(newabs,0);
		
		rep(i,p)
		{
			pre[i]=0;
			abse[i]=0;
			newpre[i]=0;
			newabs[i]=0;
			sdi(cost[i]);
			string s;
			cin>>s;
			rep(j,SZ(s))
			{
				if(s[j]=='+') pre[i]=on(pre[i],j);
				if(s[j]=='-') abse[i]=on(abse[i],j);
			}
			cin>>s;
			
			rep(j,SZ(s))
			{
				if(s[j]=='+') newpre[i]=on(newpre[i],j);
				if(s[j]=='-') newabs[i]=on(newabs[i],j);
			}
			newabs[i]=~newabs[i];
			
		}
		int ret=bfs(n,p);
		printf("Product %d\n",++ks);
		if(ret==INF) puts("Bugs cannot be fixed.");
		else {
			printf("Fastest sequence takes %d seconds.\n",ret);
			
		}
		puts("");
	}
	return 0;
}

