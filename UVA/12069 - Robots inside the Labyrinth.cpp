/*
 * 
 * 12069 - Robots inside the Labyrinth
 * Grid Compression,graph,bfs
 * ACM ICPC Dhaka Regional 2004-05
 * 
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
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<(pos)))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<(pos)))
string toBin(int n){ string s; repv(i,32)s+=(isOn(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);


struct node
{
        int x1,y1,x2,y2;
        node(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
        node(){}
}vec[100];
int const mx =300;
bool w[mx][mx];
int numx,numy;
char vis[mx][mx][4];

int fx[]={+0,+0,-1,+1};
int fy[]={-1,+1,+0,+0};

struct info
{
    int x,y,d;
    info(int _x,int _y,int _d)
    {
        x=_x;
        y=_y;
        d=_d;
    }
    info(){}
};
int bfs(int sx,int sy,int dx,int dy)
{
    mem(vis,63);
    queue<info>q;
    for(int k=0;k<4;k++)
    {
        vis[sx][sy][k]=0;
        q.push(info(sx,sy,k));
    }
    int ans=1<<28;
    while(!q.empty())
    {
        info top=q.front(); q.pop();
        int x=top.x;
        int y=top.y;
        int d=top.d;
        if(x==dx and y==dy)
        {
			ans=min(ans,(int)vis[x][y][d]);
            
        }
        rep(k,4)
        {
            int tx=top.x+fx[k];
            int ty=top.y+fy[k];
            int td=k;
            int cost=0;
            if(td!=d) cost++;
            if(tx>=1 and tx<=numx and ty>=1 and ty<=numy and w[tx][ty]==0)
            {
                if(vis[x][y][d]+cost<vis[tx][ty][td])
                {

                    vis[tx][ty][td]=vis[x][y][d]+cost;
                    q.push(info(tx,ty,td));
                }
            }
        }
    }
    return ans;
}

void fill(int lox,int hix,int loy,int hiy,int num)
{
    for(int i=lox;i<=hix;i++)
    {
        for(int j=loy;j<=hiy;j++)
        {
            w[i][j]=num;

        }
    }
}
#define pushX(x)setX.insert(x);
#define pushY(y)setY.insert(y);
int main() {
	//READ("in");	WRITE("out2");
	double ST=clock();
	
	int t,ks=0;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		mem(w,0);
		set<int>setX,setY;
        map<int,int>mpX,mpY;
		
		repl(i,n)
		{
				int x1,y1,x2,y2;
                sdii(x1,y1);
                sdii(x2,y2);
                pushX(x1); pushX(x2);    pushY(y1); pushY(y2);
                vec[i]=node(x1,y1,x2,y2);
		}
		
		int q;
        cin>>q;
        node query[1000]; 
         
         repl(i,q)
         {
				int x1,y1,x2,y2;
                sdii(x1,y1);
                sdii(x2,y2);
                //push X's
                
                setX.insert(x1);
                setX.insert(x2);

                //push Y's
                setY.insert(y1);
                setY.insert(y2);
                query[i]=node(x1,y1,x2,y2);
		 }
		
		numx=0,numy=0;
        foreach(it,setX)
        {
                int x=*it;
                numx+=2;
                mpX[x]=numx;
        }
        foreach(it,setY)
        {
                int y=*it;
                numy+=2;
                mpY[y]=numy;

        }
        numx++;
        numy++;
        for(int i=1;i<=n;i++)
        {
                int x1=mpX[vec[i].x1];
                int y1=mpY[vec[i].y1];

                int x2=mpX[vec[i].x2];
                int y2=mpY[vec[i].y2];
                int lox=min(x1,x2);
                int hix=max(x1,x2);

                int loy=min(y1,y2);
                int hiy=max(y1,y2);
                fill(lox,hix,loy,hiy,i);
         }
		
         printf("Labyrinth #%d\n",++ks);
         repl(i,q)
         {
			 int sx=query[i].x1;
			 int sy=query[i].y1;
			 int dx=query[i].x2;
			 int dy=query[i].y2;
			 
			 int ret=bfs(mpX[sx],mpY[sy],mpX[dx],mpY[dy]);
			 if(ret==1<<28) puts("Impossible.");
			 else      pfi(ret);
		 }
         
	}
	cerr<<(clock()-ST)/CLOCKS_PER_SEC<<endl;
}
