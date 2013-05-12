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

#define repl(i,n) for(int i=1; i<=(int)n; i++)

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define FOR(i,a,b) for(i64 i=(i64)a;i<=(i64)b;i++)


#define SZ(x) (i64)x.size()
#define sz SZ
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<i64,i64>
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
vector< string > token( string a, string b ) {	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;}
#define on(n,pos) (n | (1<<(pos)))
#define off(n,pos) (n & ~(1<<(pos)))
#define isOn(n,pos) (bool)(n & (1<<(pos)))

//bool operator < ( const node& p ) const {      return w < p.w;   }
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


#define mx 210000

int w[102][102],r,c;
int num[102][102];
bool flag[102][102];
char mat[102][102];
int T;
void parse()
{
        rep(i,r)
            rep(j,c)
            {

                if(mat[i][j]=='N') w[i+1][j+1]=0;
                if(mat[i][j]=='E') w[i+1][j+1]=1;
                if(mat[i][j]=='S') w[i+1][j+1]=2;
                if(mat[i][j]=='W') w[i+1][j+1]=3;

            }

}
struct node
{
        int x,y,mask,mod;
        node(int x,int y,int mask,int mod):x(x),y(y),mask(mask),mod(mod){}
};
int d[102][102][(1<<8)+2][6];
int dx[]={-1,+0,+1,+0};
int dy[]={+0,+1,+0,-1};
int bfs()
{

    mem(d,63);
    queue<node>q;
    q.push(node(1,1,0,w[1][1]));

    d[1][1][0][w[1][1]]=0;
    int ans=1<<28;
    while(!q.empty())
    {
        node top=q.front(); q.pop();

        if(top.x==r and top.y==c and top.mask==(1<<T)-1)
        {
            ans=min(ans,d[top.x][top.y][top.mask][top.mod]);

        }
        int init=w[top.x][top.y];

        int k=(init+d[top.x][top.y][top.mask][top.mod])%4;
        int tx=top.x+dx[k];
        int ty=top.y+dy[k];
        int tmask=top.mask;
        int tmod=(top.mod+1)%4;;

        if(flag[tx][ty])
            tmask=on(tmask,num[tx][ty]);


        if(tx>=1 and tx<=r and ty>=1 and ty<=c)
        {
            if(d[top.x][top.y][top.mask][top.mod]+1<d[tx][ty][tmask][tmod])
            {

                d[tx][ty][tmask][tmod]=d[top.x][top.y][top.mask][top.mod]+1;
                q.push(node(tx,ty,tmask,tmod));
            }
        }
        tx=top.x;
        ty=top.y;
        tmask=top.mask;
        tmod=(top.mod+1)%4;
        if(d[top.x][top.y][top.mask][top.mod]+1<d[tx][ty][tmask][tmod])
        {

                d[tx][ty][tmask][tmod]=d[top.x][top.y][top.mask][top.mod]+1;
                q.push(node(tx,ty,tmask,tmod));
        }


    }
    return ans;
}
int main()
{
        //READ("in.txt");
        while(cin>>r>>c)
        {
                if(!r and !c) break;
                mem(flag,0);

                rep(i,r)
                    sds(mat[i]);
                cin>>T;
                rep(i,T)
                {
                    int x,y;
                    sdii(x,y);
                    num[x][y]=i;
                    flag[x][y]=1;
                }
                parse();
                int ret=bfs();
                printf("%d\n",ret);
        }

}
