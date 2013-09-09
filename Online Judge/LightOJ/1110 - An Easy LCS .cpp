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
#define sdl(x) scanf("%lld",&x)
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
#define mx 202
string a,b;
int dp[mx][mx];
int call(int i,int j)
{
	if(i>=(int)a.size() or j>=(int)b.size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(a[i]==b[j]) 
	{
		return dp[i][j]=call(i+1,j+1)+1;
	}
	
	return dp[i][j]=max(call(i+1,j),call(i,j+1));
	
}
vector<int>sava[100],savb[100];

string out;
void print(int i,int j,int len)
{
	if(len==0) return;
	for(char ch='a';ch<='z';ch++)
	{
		int pi=lower_bound(all(sava[ch-'a']),i)-sava[ch-'a'].begin();
		if(pi!=(int)sava[ch-'a'].size())
		{
			int pj=lower_bound(all(savb[ch-'a']),j)-savb[ch-'a'].begin();
			if(pj!=(int)savb[ch-'a'].size())
			{
				pi=sava[ch-'a'][pi];
				pj=savb[ch-'a'][pj];
				if(call(pi+1,pj+1)==len-1)
				{
					out+=ch;
					print(pi+1,pj+1,len-1);
					break;
				}
			}
		}
	}	
	
}
int main() 
{ 
	//READ("in");
	int t,kas=0;
	cin>>t;
    while(t--)
    {
		mem(dp,-1);
		rep(i,100){
			sava[i].clear();
			savb[i].clear();
		}
		cin>>a>>b;
		
		rep(i,a.size())sava[a[i]-'a'].pb(i);
		rep(i,b.size())savb[b[i]-'a'].pb(i);
		out="";
		int ret=call(0,0);
		if(ret==0) out=":(";
		else
		print(0,0,ret);
		printf("Case %d: ",++kas);
		cout<<out<<endl;
	}

	return 0;	
}

 
 
