/*
 * POJ 2019
 * Sparse Table
 */
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
#define INF (1<<30)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define cclear(x,y) memset(x,y,sizeof(x));
#define eps 1e-9

#define SDi(x) scanf("%d",&x)
#define SDl(x) scanf("%lld",&x)
#define SDs(x) scanf("%s",x)

using namespace std;

template<class T> inline T gcd(T a,T b) {if(a<0)return 
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return 
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> bool inside(T a,T b,T c){ return (b>=a && b<=c);}
typedef long long i64;
typedef unsigned long long ui64;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int LG[501];


int P[501][501][9];



int A2[501][501];
void process2(int idx,int N)
  {
      int i, j;
   
  
      for (i = 0; i < N; i++)
          P[idx][i][0] = i;
        for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A2[idx][P[idx][i][j - 1]] > A2[idx][P[idx][i + (1 << (j - 1))][j - 1]])
                  P[idx][i][j] = P[idx][i][j - 1];
              else
                  P[idx][i][j] = P[idx][i + (1 << (j - 1))][j - 1];
}   

int query2(int idx,int i,int j)
{
	int log;
	if(LG[j-i+1]>0) log=LG[j-i+1];
	else
	{
		for (log = 0; 1 << log <=(j-i+1); log++);
		log--;
		LG[j-i+1]=log;
	}
	int k=log;
	if(A2[idx][P[idx][i][k]]>=A2[idx][P[idx][j-(1<<k)+1][k]])
	{
		return P[idx][i][k];
		
	}
	else return P[idx][j-(1<<k)+1][k];
	
}



int A[501][501];
int M[501][501][9];

void process(int idx,int N)
  {
      int i, j;
   
  
      for (i = 0; i < N; i++)
          M[idx][i][0] = i;
        for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[idx][M[idx][i][j - 1]] > A[idx][M[idx][i + (1 << (j - 1))][j - 1]])
                  M[idx][i][j] = M[idx][i][j - 1];
              else
                  M[idx][i][j] = M[idx][i + (1 << (j - 1))][j - 1];
}   

int query(int idx,int i,int j)
{
	int log;
	if(LG[j-i+1]>0) log=LG[j-i+1];
	else
	{
		for (log = 0; 1 << log <=(j-i+1); log++);
		log--;
		LG[j-i+1]=log;
	}
	int k=log;
	if(A[idx][M[idx][i][k]]>=A[idx][M[idx][j-(1<<k)+1][k]])
	{
		return M[idx][i][k];
		
	}
	else return M[idx][j-(1<<k)+1][k];
	
}


int main()
{
		//READ("in");
	
	
	
		int s;
		int n,q;
		scanf("%d%d%d",&n,&s,&q);
		rep(i,n)
		 rep(j,n)
		 {
			scanf("%d",&A[i][j]);
			A2[i][j]=-A[i][j];
		}
		
	
		 rep(i,n)
		 {
			 process(i,n);
			 process2(i,n);
		 }
	
		
		 while(q--)
		 {
			 int i,j;
			 
			 scanf("%d%d",&i,&j);
			 i--;
			 j--;
			 int mx=0;
			 int mn=1<<28;
			 for(int I=i;I<=i+s-1 && I<n;I++)
			 {
				 if(j+s-1<n)
				 {
					int ret=query(I,j,j+s-1);
					int ret2=query2(I,j,j+s-1);
				
					mx=max(A[I][ret],mx);
					mn=min(-A2[I][ret2],mn);
				}
				 
				
			 }
			
			// printf("%d %d\n",mx,mn);
			 printf("%d\n",mx-mn);
			 
		 }
		
		
		
	
	
	
	
}
