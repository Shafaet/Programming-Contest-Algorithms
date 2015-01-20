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
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E16;

double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return
r;}

double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(long long a){if(a==0) return "0";string ret;for(long long i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(ret.begin(),ret.end());return ret;}

vector< string > token( string a, string b )
{
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(),
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
int isupper(char s) {if(s>='A' and s<='Z') return 1; return 0;}
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}

//bool operator < ( const node& p ) const {      return dist > p.dist;   }

int SET(int N,int pos){	return N=N | (1<<pos);}
int RESET(int N,int pos){	return N= N & ~(1<<pos);}
int check(int N,int pos){	return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=RESET(N,pos);return N=SET(N,pos);}
void PRINTBIT(int N){	printf("("); for(int i=6;i>=1;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}



#define MX 100003

int T[MX],D[MX],P[MX][30],min_dis[MX][30];
int max_dis[MX][30];
int L[MX];
int MNN;
void init(int N)
{
	mem(P,-1);


       for (int i = 1; i <= N; i++)
       {
          P[i][0] = T[i];
          max_dis[i][0]=D[i];
          min_dis[i][0]=D[i];
	  }

    for (int j = 1; 1 << j < N; j++)
         for (int i = 1; i <= N; i++)
         {
			 if (P[i][j - 1] != -1)
			 {
				 max_dis[i][j]=max(max_dis[i][j-1],max_dis[P[i][j-1]][j-1]);
				 min_dis[i][j]=min(min_dis[i][j-1],min_dis[P[i][j-1]][j-1]);
                 P[i][j] = P[P[i][j - 1]][j - 1];

			 }
		 }
		 
}
vector<pii>G[MX];
void call(int pre,int u,int dep)
{
	L[u]=dep;
	rep(i,G[u].size())
	{
		if(G[u][i].first!=pre)
		{
			T[G[u][i].first]=u;
			D[G[u][i].first]=G[u][i].second;
			call(u,G[u][i].first,dep+1);
		}
	}

}

int MXX=0;
int query(int N,int p,int q)
{
	int log, i;
	if (L[p] < L[q])
          swap(p,q);
    for (log = 1; 1 << log <= L[p]; log++);
      log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
          {
			  MXX=max(MXX,max_dis[p][i]);
			  MNN=min(MNN,min_dis[p][i]);
              p = P[p][i];


		  }

      if (p == q)
          return p;

  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
          {

               MXX=max(MXX,max_dis[p][i]);
               MXX=max(MXX,max_dis[q][i]);
               MNN=min(MNN,min_dis[p][i]);
               MNN=min(MNN,min_dis[q][i]);
              p = P[p][i];
               q = P[q][i];

		  }
     MXX=max(MXX,D[p]);
     MXX=max(MXX,D[q]);
     MNN=min(MNN,D[p]);
     MNN=min(MNN,D[q]);
      return T[p];


}
int main()
{
	//READ("in");
	//WRITE("out");
	int t,kas=0;
	cin>>t;
	while(t--)
	{
		int n;
		SDi(n);
		repl(i,n)G[i].clear();

		rep(i,n-1)
		{
			int u,v,w;
			SDii(u,v);SDi(w);
			G[u].pb(pii(v,w));
			G[v].pb(pii(u,w));
			//T[v]=u;
			//D[v]=w;



		}
		call(-1,1,1);
		init(n);
		int Q;
		cin>>Q;
		printf("Case %d:\n",++kas);
		rep(i,Q)
		{
			int x,y;
			MXX=0;
			MNN=1<<30;
			SDii(x,y);
			if(x==y) puts("0 0");
			else
			{
				query(n,x,y);

				printf("%d %d\n",MNN,MXX);
			}




		}



	}



}
