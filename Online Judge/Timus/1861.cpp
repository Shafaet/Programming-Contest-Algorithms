/*
 *  Shafaetsplanet.com
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

#define SZ(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
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


double _dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
int distsq(int x1,int y1,int x2,int y2){return sqr(x1-x2)+sqr(y1-y2);}
i64 toInt64(string s){i64 r=0;stream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}

vector< string > token( string a, string b ) {	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 	b.end(), *q ) ) q++;}return oot;}

//bool operator < ( const node& p ) const {      return w > p.w;   }

int fx[]={0,0,-1,+1,-1,-1,+1,+1};
int fy[]={-1,+1,0,0,-1,+1,-1,+1};

int Set(int N,int pos){ return N=N | (1<<pos); }
int Reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=Reset(N,pos);return N=Set(N,pos);}
void PBIT(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}





#define mx 1002

int F[1000002],i,j;
void f(const string &pattern)
{

  
  int m=pattern.size();
  
  F[0] = F[1] = 0; 
  
  for(i = 2; i <= m; i++) 
  {
	
    j = F[i - 1];
    while(1) 
    {
	
      if(pattern[j] == pattern[i - 1]) { 
		  
        F[i] = j + 1; break; 
      }
      
      if(j == 0) { F[i] = 0; break; }
      
      j = F[j];
    }
  }   
}

string text,pattern;
int kmp()
{
 
  int n=text.size();
  int m=pattern.size();
  f(pattern); 
    
  
  int cc=0;
  i = 0; 
         

  j = 0; 
  
  while(1) {
	  	
    if(j == n) break; 
    if(text[j] == pattern[i]) {
      i++; 
      j++; 
      
		  cc+=(i == m) ;
	  
    }
   
    else if(i > 0) i = F[i];
   
    else j++;
    
  }
  return cc;
}


int dp[mx][mx];
int call(int i,int j,int m,int n)
{
	 if(j == n) return 0;
	 
	 if(dp[i][j]!=-1) return dp[i][j];
	 if(text[j] == '?')
	 {
		 int ret1=0,ret2=0;
		 if(i>0) ret1=call(F[i],j,m,n);
		 else  ret1= call(i,j+1,m,n);
		 ret2=(i+1==m)+call(i+1,j+1,m,n);
	
		 return dp[i][j]=max(ret1,ret2);
	 }
	 else if(text[j] == pattern[i])
	 {
		 
		 int ret= (i+1==m)+call(i+1,j+1,m,n);
	
		 
		 return dp[i][j]=ret;
	 }
	 else if(i>0) return dp[i][j]=call(F[i],j,m,n);
	 else  return dp[i][j]=call(i,j+1,m,n);
	
}


char a[1000001],b[1000001];
int main()
{
		
	
	//READ("in");
	mem(dp,-1);
	//WRITE("out");

		scanf("%s%s",a,b);
		text=a;
		pattern=b;
		 f(pattern); 
		 
		 
		//for(int i=0;i<=SZ(pattern);i++)		cout<<i<<" -- "<<F[i]<<endl;
		int get=call(0,0,SZ(pattern),SZ(text));
		printf("%d\n",get);
		
		

	

}
    

	
	
	

