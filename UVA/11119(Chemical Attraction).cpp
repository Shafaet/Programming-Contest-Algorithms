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
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pmp make_pair
#define sz(s) ((int)(s.size()))


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

int man[202][202],woman[202][202];
	map<string,int>mp;
	string ulta[202];

void solve(vector<int>&mlist,vector<int>&wlist,int n)
{
	sort(all(mlist));
	sort(all(wlist));
	
	int Left[202]={0},Right[202]={0};
	mem(Left,-1);
	mem(Right,-1);
	int prop[202][202]={{0}};
		
	while(1)
	{
		int rem=0;
		vector<int>list[102];
		rep(i,mlist.size())
		{
			   if(Left[i]>=0) continue;
			   rem++;
			   int mx=0,choice=0;
			   rep(j,wlist.size())
			   {
				   if(prop[i][j]) continue;
				   int u=mlist[i];	
				   int v=wlist[j];
				   if(man[u][v]>mx){
					   
					   mx=man[u][v];
					   choice=j;
				   }
			   }

			   list[choice].pb(i);
			   prop[i][choice]=1;
			   
		}
		if(!rem) break;
		rep(i,wlist.size())
		{
			int mx=0;
			if(Right[i]!=-1)list[i].pb(Right[i]);
			rep(j,list[i].size())
			{
				
				int u=wlist[i];
				int v=mlist[list[i][j]];
				if(woman[u][v]>mx)
				{
					mx=woman[u][v];
					if(Right[i]!=-1) Left[Right[i]]=-1;
					Right[i]=list[i][j];
					Left[list[i][j]]=i;
				}
			}
		}

	}
	rep(i,mlist.size())
	{
		if(i) printf(" ");
		cout<<ulta[mlist[i]]+ulta[wlist[Left[i]]];
	}
	puts("");
	
}
int main()
{
	
	//READ("in");
	int n,kas=0;
	while(cin>>n and n)
	{
		
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			ulta[i]=s;
			mp[s]=i;
		}
		int m;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			string s;
			cin>>s;
			mp[s]=i+n;
			ulta[i+n]=s;
		}
		
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		   scanf("%d",&man[i][j+n]);
		   
		for(int i=1;i<=m;i++)
		  for(int j=1;j<=n;j++)
		   scanf("%d",&woman[i+n][j]);
		   
		int q,qu=0;
		++kas;
		while(cin>>q and q)
		{
			
			
			vector<int>vm,vw;
			for(int i=1;i<=q;i++)
			{
				string s;
				cin>>s;
				string s1,s2; 
				s1=s.substr(0,2);
				s2=s.substr(2,2);
				vm.pb(mp[s1]);
				vw.pb(mp[s2]);
				
			}
			printf("Scenario %d, Mixture %d:\n",kas,++qu);
			solve(vm,vw,n);
			puts("");
			
		}
	}
	
	
}


