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
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){	return (log10l(N))/(log10l(B));	}
vector< string > token(char *a,char *b) {vector<string>v; char *p=strtok(a," "); while(p) {v.pb(p);p=strtok(NULL," ");} return v;}
vector<string>token(string a,char *b){char temp[100002]; strcpy(temp,a.c_str()); return token(temp,b);       }
#define on(n,pos) n=(n | (1<<pos))
#define off(n,pos) n= n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int fx[]={0,+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={0,-1,+1,+0,+0,+1,+1,-1,-1};

#define mx  100010


int start_kothae[mx];
int treeMIN[mx*3];

void update_MIN(int node,int b,int e,int idx)
{
	if(idx<b or idx>e) return;
	if(b==e)
	{
		treeMIN[node]=start_kothae[b];
		//cout<<b<<" "<<e<<" == "<<treeMAX[node]<<endl;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	
	update_MIN(Left,b,mid,idx);
	update_MIN(Right,mid+1,e,idx);
	treeMIN[node]=min(treeMIN[Left],treeMIN[Right]);
}


int query_MIN(int node,int b,int e,int i,int j)
{
	
	if (i > e || j < b)	return 1<<28;
	if (b >= i && e <= j){
		
		 return treeMIN[node];
	 }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query_MIN(Left,b,mid,i,j);
	int p2=query_MIN(Right,mid+1,e,i,j);
	return min(p1,p2);
}



int end_kothae[mx];
int treeMAX[mx*3];

void update_MAX(int node,int b,int e,int idx)
{
	if(idx<b or idx>e) return;
	if(b==e)
	{
		treeMAX[node]=end_kothae[b];
		//cout<<b<<" "<<e<<" == "<<treeMAX[node]<<endl;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	
	update_MAX(Left,b,mid,idx);
	update_MAX(Right,mid+1,e,idx);
	treeMAX[node]=max(treeMAX[Left],treeMAX[Right]);
}
int query_MAX(int node,int b,int e,int i,int j)
{
	
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j){
		
		 return treeMAX[node];
	 }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query_MAX(Left,b,mid,i,j);
	int p2=query_MAX(Right,mid+1,e,i,j);
	return max(p1,p2);
}

struct node
{
	char c;
	int p;
	node(char _c,int _p)
	{
		c=_c;
		p=_p;
	}
};
int main(){
	//READ("in");
	mem(treeMIN,63);
	string s;
	cin>>s;
	
	int n=SZ(s);
	
	stack<node>st;
	
	
	for(int i=0;i<n;i++)
	{
		if(isupper(s[i]))
		{
			st.push(node(s[i],i));
		}
		else
		{
			
			if(SZ(st) and st.top().c==toupper(s[i]))
			{
				node top=st.top(); st.pop();
				end_kothae[top.p+1]=i+1;
				start_kothae[i+1]=top.p+1;
				update_MAX(1,1,n,top.p+1);
				update_MIN(1,1,n,i+1);
			}
			else
			{
				start_kothae[i+1]=-1;update_MIN(1,1,n,i+1);
				while(SZ(st))
				{
					node top=st.top(); st.pop();	
					end_kothae[top.p+1]=n+5;
					update_MAX(1,1,n,top.p+1);
				}
			}
		}
		
	}
	while(SZ(st))
				{
					node top=st.top(); st.pop();	
					end_kothae[top.p+1]=n+5;
					update_MAX(1,1,n,top.p+1);
				}
	
	
	int q;
	sdi(q);
	string out;
	while(q--)
	{
		int lo,hi;
		sdii(lo,hi);
		
		int getMAX=query_MAX(1,1,n,lo,hi);
		int getMIN=query_MIN(1,1,n,lo,hi);
		if(getMIN>=lo and getMAX<=hi) out+='1'; 
		else out+='0';
	
	}
	cout<<out<<endl;
	
	
	return 0;
}

