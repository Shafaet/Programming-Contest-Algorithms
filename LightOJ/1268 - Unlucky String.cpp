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
//double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef unsigned int i64;
typedef unsigned long long ui64;
double log(double N,double B){	return (log10l(N))/(log10l(B));	}
vector< string > token(char *a,char *b) {vector<string>v; char *p=strtok(a," "); while(p) {v.pb(p);p=strtok(NULL," ");} return v;}
vector<string>token(string a,char *b){char temp[100002]; strcpy(temp,a.c_str()); return token(temp,b);       }


//bool operator < ( const node& p ) const {      return w < p.w;   }
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int fx[]={0,+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={0,-1,+1,+0,+0,+1,+1,-1,-1};


#define on(n,pos) n=(n | (1<<(pos)))
#define off(n,pos) n= n & ~(1<<(pos))
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,4)s+=(isOn(n,i)+'0');return s;}

#define mx 60

int f[mx];

void failure(string pat)
{
	f[0]=0;
	f[1]=0;
	int m=pat.size();
	for(int i=2;i<=m;i++)
	{
		int j=f[i-1];
		while(1)
		{
			if(pat[j]==pat[i-1])
			{
				f[i]=j+1;
				break;
			}
			else if(j==0){f[i]=0; break;}
			else j=f[j];
		}
		
	}
}

int val[222]={0};
bool isval(char c)
{
	return val[c-'a'];
}
int m;
string pat;

i64 freq[mx][mx];
void precalc()
{
	mem(freq,0);
	for(int i=0;i<=m-1;i++)
	{
		for(char c='a';c<='z';c++)
		{
			if(!isval(c))continue;
			int j=i;
			while(1)
			{
				
				if(pat[j]==c){
					freq[i][j+1]++;
					break;
				}
				else if(j==0)
				{
					
					freq[i][0]++;	
					break;
				}
				else j=f[j];
			}
			
			
		}
		
	}
		
}



int call(int len,int state)
{
	if(state==m) return 0;
	if(len==0) return 1;
	
	int ret=0;
	for(int nst=0;nst<=m;nst++)
	{
		ret+=freq[state][nst]*call(len-1,nst);
	}
	return ret;
	
}


namespace matrix {
	#define size mx
	
	i64 mat[size][size],tmp[size][size],res[size][size];
	int n;
	
	void init(int _n){
		n=_n;
		mem(mat,0);
		mem(tmp,0);
		mem(res,0);
	}
	
	void mul(i64 r[][size],i64 a[][size],i64 b[][size])
	{
		rep(i,n)
		{
			rep(j,n)
			{
				i64 val=0;
				rep(t,n)
				{
					val+=a[i][t]*b[t][j];
				}
				tmp[i][j]=val;
			}
		}
		memcpy(r,tmp,n*size*sizeof(tmp[0][0]));
		
	}
	void mPow(i64 r[][size],i64 a[][size],int p)
	{
		if(p<0) return ;
		mem(r,0);
		rep(i,n) r[i][i]=1;
		while(p>0)
		{
			if(p&1)
				mul(r,r,a);
			mul(a,a,a);
			p>>=1;
		}
		
	}
	void pow(i64 p)
	{
		
		mPow(res,mat,p);
		memcpy(mat,res,n*size*sizeof(tmp[0][0]));
		
	}
	void fill()
	{
		memcpy(mat,freq,n*size*sizeof(freq[0][0]));
	}
	
	#undef size
};


int main()
{
	//READ("in");
	int t,ks=0;
	cin>>t;
	while(t--)
	{

			mem(val,0);
			int n;
			sdi(n);
			char s[100];
			sds(s);
			
			for(int i=0;s[i];i++) val[s[i]-'a']=1;
			
			cin>>pat;
			failure(pat);
			
			m=SZ(pat);
			
			precalc();
			
			
			//cout<<call(n,0)<<endl;
			
			matrix::init(m+1);
			matrix::fill();
			
			matrix::pow(n);
			
			//matrix::print(matrix::mat);
			
			i64 ans=0;
			for(int i=0;i<m;i++)
			{
				ans+=matrix::mat[0][i];
				
				
			}
			printf("Case %d: %u\n",++ks,ans);
			
			
			
			
		
	}
		
}

