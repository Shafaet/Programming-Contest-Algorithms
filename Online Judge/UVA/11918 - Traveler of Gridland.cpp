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
int fx[]={+0,+0,+1,-1,+1,+1,-1,-1};
int fy[]={+1,-1,+0,+0,+1,-1,+1,-1};
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define ison(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(ison(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);
#define DEBUG 0

#define mx 1002


struct node
{
	int x,y;
	i64 w;
	node(int x,int y,i64 w):x(x),y(y),w(w){}
	bool operator < ( const node& p ) const {      return w > p.w;   }
};

struct monster
{
        int x1,y1,x2,y2;
        monster(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
        monster(){}
}box[200];

set<int>setX,setY;
map<int,int>mpX,mpY;
int ultaX[mx],ultaY[mx];
void add(int x1,int y1,int x2,int y2)
{
	setX.insert(x1);
	setX.insert(x1-1);
	setX.insert(x1+1);
	
	setY.insert(y1);
	setY.insert(y1-1);
	setY.insert(y1+1);
	
	setX.insert(x2);
	setX.insert(x2-1);
	setX.insert(x2+1);
	
	setY.insert(y2);
	setY.insert(y2-1);
	setY.insert(y2+1);
}
int maxX=0,	maxY=0;

bool w[mx][mx];
void fill(int lox,int hix,int loy,int hiy)
{
    for(int i=lox;i<=hix;i++)
    {
        for(int j=loy;j<=hiy;j++)
        {
            w[i][j]=1;

        }
    }
}
i64 d[mx][mx];
i64 getcost(int x1,int y1,int x2,int y2)
{
	i64 ax=ultaX[x1];
	i64 ay=ultaY[y1];
	
	i64 bx=ultaX[x2];
	i64 by=ultaY[y2];
	return abs(ax-bx)+abs(ay-by);
}
i64 bfs(int sx,int sy,int dx,int dy)
{
	priority_queue<node>q;
	rep(i,maxX+2)
	rep(j,maxY+2)d[i][j]=1LL<<40LL;
	
	d[sx][sy]=0;
	q.push(node(sx,sy,0));
	while(!q.empty())
	{
		node top=q.top();q.pop();
		int x=top.x;
		int y=top.y;
		if(x==dx and y==dy) 	return d[dx][dy];
		rep(i,4)
		{
			int tx=top.x+fx[i];
			int ty=top.y+fy[i];
			if(tx>=0 and tx<maxX and ty>=0 and ty<maxY and w[tx][ty]==0)
			{
				i64 cost=getcost(x,y,tx,ty);
				if(d[x][y]+cost<d[tx][ty])
				{
					d[tx][ty]=d[x][y]+cost;
					q.push(node(tx,ty,d[tx][ty]));
				}
			}
		}
		
	}

	return -1;
	
}
int main(){
	
//	READ("in");
	int t,ks=0;
	cin>>t;
	while(t--)
	{
		int mon=0;
		setX.clear();
		setY.clear();
		mpX.clear();
		mpY.clear();
		mem(w,0);
		int sx,sy,dx,dy;
		sdii(sx,sy);
		sdii(dx,dy);
		add(sx,sy,dx,dy);
		int p,line,rect;
		sdi(p);
		sdi(line);
		sdi(rect);
		
		for(int i=0;i<p;i++)
		{
			int x1,y1;
			sdii(x1,y1);
			add(x1,y1,x1,y1);
			box[mon++]=monster(x1,y1,x1,y1);
		}
		
		for(int i=0;i<line;i++)
		{
			int x1,y1;
			int x2,y2;
			sdii(x1,y1);
			sdii(x2,y2);
			add(x1,y1,x2,y2);
			box[mon++]=monster(x1,y1,x2,y2);
		}
		
		
		for(int i=0;i<rect;i++)
		{
			int x1,y1;
			int x2,y2;
			sdii(x1,y1);
			sdii(x2,y2);
			add(x1,y1,x2,y2);
			box[mon++]=monster(x1,y1,x2,y2);
		}
		const int LOW = -1000000000;
		const int HI =  1000000000;
		
		maxX=0;	maxY=0;
		foreach(it,setX)
		{
			if(*it<LOW or *it>HI) continue;
			int val=*it;
			mpX[val]=maxX;
			ultaX[maxX]=val;
			maxX++;
		}
		foreach(it,setY)
		{
			if(*it<LOW or *it>HI) continue;
			int val=*it;
			mpY[val]=maxY;
			ultaY[maxY]=val;
			maxY++;
		}
		
		for(int i=0;i<mon;i++)
        {
                int x1=mpX[box[i].x1];
                int y1=mpY[box[i].y1];

                int x2=mpX[box[i].x2];
                int y2=mpY[box[i].y2];
                int lox=min(x1,x2);
                int hix=max(x1,x2);

                int loy=min(y1,y2);
                int hiy=max(y1,y2);
                fill(lox,hix,loy,hiy);
         }
        printf("Case %d: ",++ks);
		i64 ret=bfs(mpX[sx],mpY[sy],mpX[dx],mpY[dy]);
		if(ret==-1) puts("Impossible");
		else
		cout<<ret<<endl;
		
		
	}
	
	
	return 0;
}

