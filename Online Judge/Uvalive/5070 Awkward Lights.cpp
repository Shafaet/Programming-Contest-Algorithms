/*
 *  Shafaetsplanet.com
 *  UVALIVE 5070
 *  Bitwise Gaussian Elimination O(n^2)
 *  Thanks to Stjepan Glavina
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
#define INF (1<<28)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
#define sdl(x) scanf("%lld",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
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


int isvowel(char s){s=tolower(s); if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')return 1; return 0;}
int isupper(char s) {if(s>='A' and s<='Z') return 1; return 0;}
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=reset(N,pos);return N=Set(N,pos);}
void pbit(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}
//bool operator < ( const node& p ) const {      return w < p.w;   }


#define mx 700
#define NN 700
 int mat[mx][mx];
   int gauss_s (int N,int M) 
    {
        for (int r = 0, c = 0; r < M && c < N; c++)
        {

            int idx = r;

            for (int i = r + 1; i < M; i++)
                if (((mat[i][c/32] >> (c%32)) & 1) > 0)
                    idx = i;

            if (((mat[idx][c/32] >> (c%32)) & 1) == 0)
                continue;

            for (int i = 0; i < N/32+1; i++)
                swap (mat [r][i], mat [idx][i]);
                
            for (int i = 0; i < M; i++)
            {
                if (i == r)
                    continue;

                int tmp = (mat[i][c/32] >> (c%32)) & 1;
                if (tmp == 0) continue;

                for (int j = 0; j < N/32+1; j++) 
                    mat [i][j] ^= mat[r][j];
            }
            
            r++;
        }
		
		
		for (int i = 0; i < M; i++)
        {
            bool zero = true;

            for (int j = 0; j < N; j++)
                  if (((mat[i][j/32]>>(j%32)) &1) > 0)
                                              
                                              
                    zero = false;

             if (zero && ((mat[i][N/32]>>(N%32))&1) > 0) 
            {

                return 0; 
            }
        }

       return 1;
 }



int w[mx][mx];
#define setmat(r,c) mat[r][c/32] |= 1<<(c%32)
#define unset(r,c) mat[r][c/32] &= ~(1<<(c%32))
int main()
{
    //READ("in");
    int r,c,d;
    while(sdii(c,r)==2)
    {
		mem(mat,0);
        sdi(d);
            if(!c and !r and !d) break;
            mem(mat,0);
            rep(i,r)
              rep(j,c)
                sdi(w[i][j]);

            rep(i,r)
                rep(j,c)
                 rep(i2,r)
                    rep(j2,c)
                    {
                        if(abs(i-i2)+abs(j-j2)==d or abs(i-i2)+abs(j-j2)==0)
                        {
                            int u=i*c+j;
                            int v=i2*c+j2;
                            setmat(u,v);
                            
               
                        }
                    }
            rep(i,r)
                rep(j,c)
                {
                     int u=i*c+j;
                     if(w[i][j]==1) setmat(u,r*c);
                     else unset(u,r*c);
                     
                }
            int ret=gauss_s(r*c,r*c);
            pfi(ret);



    }
}


