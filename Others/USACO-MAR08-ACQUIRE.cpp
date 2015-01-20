/*
 * USACO MAR08 Land Acquisition(ACQUIRE)
 * DP with convex hull optimization
 * http://wcipeg.com/wiki/Convex_hull_trick
 * http://cerberus.delos.com:790/TESTDATA/MAR08.acquire.htm
 * SPOJ ACQUIRE
 
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
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
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
typedef  long long i64;
typedef unsigned long long ui64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);

#define MAX 100002
struct rect { long long w, h; }plots[MAX];
struct line 
{
  long long m, b;
  line(long long x=0, long long y=0) { m=x; b=y; }
}lines[MAX];


bool cmp(const rect &a,const rect &b)
{
	//width increasing
	//height decreasing
	if(a.w==b.w)
	return a.h>b.h;
	return a.w<b.w;
}

bool bad(const line &x, const line &y, const line &z) {
	i64 p1=(y.m-z.m) * (y.b-x.b);
	i64 p2=(x.m-y.m) * (z.b-y.b);
	//if p1 is on right, y no longer needed
	return  p1>=p2;
  
}
void addline(i64 m,i64 b,int startptr,int &endptr) // 0 based
{
	lines[endptr]=line(m,b);
			endptr++;
			while (endptr-startptr >= 3 && bad(lines[endptr-3], lines[endptr-2], lines[endptr-1])) //check if we can eliminate second last line
			{
				lines[endptr-2] = lines[endptr-1];
				endptr--;
			}
}
i64 dp[MAX];
int main() {
	//READ("acquire/acquire.10.in");
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(i,n)
	{
		cin>>plots[i].w>>plots[i].h;
	}
	sort(plots,plots+n,cmp);
	//dp=b;
	//plots.h=m
	//plots.w=x
	//minimize y=mx+b
	
	
	int c=0;
	rep(i,n)
	{
		plots[c]=plots[i];
		while (c && plots[c].w >= plots[c-1].w and  plots[c].h >= plots[c-1].h) //If one box can be put into other, remove it
		{
			     plots[c-1] = plots[c];
				 c--;
		}
		c++;
	}
	n=c;
	
	//Segments which are left to the current points are not needed to search
	//So we can use two pointers instead in bsearch
	int start=0,end=1;
	dp[0]=0;
	lines[0]=line(plots[0].h,dp[0]);
	rep(i,n)
	{
		dp[i+1]=1LL<<60LL;
		for(int j=start;j<end;j++)
		{
			i64 val = lines[j].m * plots[i].w + lines[j].b;
			if(val<dp[i+1])
			{
				dp[i+1]=val;
				start=j;
			}
			else break; //We will only get worse value if we move right, so break
		}
		if(i<n-1)	addline(plots[i+1].h,dp[i+1],start,end); //add next line
	}
	cout<<dp[n]<<endl;
	return 0;
}
