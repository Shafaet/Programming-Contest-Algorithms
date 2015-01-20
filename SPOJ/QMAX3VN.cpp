/*
 *  Shafaetsplanet.com
 *  SPOJ QMAX3VN
 *  Balance Binary Search Tree, Treap
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

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)



#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair


#define sdi(x) scanf("%d",&x)
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

i64 toInt64(string s){i64 r=0;istringstream sin(s);sin>>r;return r;}
double LOG(i64 N,i64 B){	return (log10l(N))/(log10l(B));	}
string itoa(i64 a){if(a==0) return "0";string ret;for(i64 i=a; i>0; i=i/10) ret.push_back((i%10)+48);reverse(all(ret));return ret;}

vector< string > token( string a, string b ) {
	const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string > 
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), 
	*e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(), 
	b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return w < p.w;   }

int fx[]={0,0,-1,+1,-1,-1,+1,+1};
int fy[]={-1,+1,0,0,-1,+1,-1,+1};

int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (N & (1<<pos));}
int toggle(int N,int pos){if(check(N,pos))return N=Reset(N,pos);return N=Set(N,pos);}
void PBIT(int N){	printf("("); for(int i=10;i>=0;i--)	{bool x=check(N,i);cout<<x;}	puts(")");}
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
typedef double dd;

#define INF (1<<30)
struct treap{
	
	struct node 
	{
		node *Left, *Right;
		int key, pri, sz,best;
	} *root, *dummy;
 
	treap() 
	{
		dummy = new node();
		dummy->Left = dummy->Right = dummy;
		dummy->pri = -1;
		dummy->sz = 0;
		dummy->best=-INF;
		root = dummy;
		srand(23524677);
	}
	
	int size() { return root->sz; }
 
	void update(node *n) 
	{ 
		n->best=max(n->key,max(n->Left->best,n->Right->best));
		n->sz = n->Left->sz + n->Right->sz + 1; 
	}
	
	
	node *rotate(node *A, node *B) {
		if (A->Left == B) {
		  A->Left = B->Right;
		  B->Right = A;
		} else {
		  A->Right = B->Left;
		  B->Left = A;
		}
		update(A);
		update(B);
		return B;
	}
	
	node *insert(node *root, node *newnode,int pos) {
			if (root == dummy) 	return newnode;
						
			if (root->Left->sz>=pos) {
				root->Left = insert(root->Left, newnode,pos);
				if (root->Left->pri > root->pri) root = rotate(root, root->Left);
			}
			else {
				root->Right = insert(root->Right, newnode,pos-root->Left->sz-1);
				if (root->Right->pri > root->pri) root = rotate(root, root->Right);
			}
			update(root);
			return root;
	}
	
	void insert(int key,int pos) {
		node *n = new node();
		n->Left = n->Right = dummy;
		n->key = key;
		n->pri = rand();
		n->best=key;
		n->sz = 1;
		root = insert(root, n,pos);
	}
	
	int query( int lo, int hi, int a, int b, node *x ) 
	{		
		 if( a > hi || b < lo || x == dummy ) return -INF;
		 
		 if(a>=lo and b<=hi) return x->best;
		  int ret = -INF;
		 ret = max( ret, query( lo, hi, a, a + x->Left->sz, x->Left ) );
         ret = max( ret, query( lo, hi, a + x->Left->sz + 1, b, x->Right ) );
         int cno=a+x->Left->sz;
         
         
         if(cno>=lo and cno<=hi)  {
			 
			 ret=max(ret,x->key);
		 }
		 else return ret;
         
         
         return ret;
		 
	}
	int query(int lo,int hi)
	{
		return query(lo,hi,1,root->sz,root);
	}
	
	
} T;

int main()
{	
	//READ("in");
	//WRITE("out");
	
	int n; scanf( "%d", &n );
 
    repl(i,n) {
        char tip[ 5 ]; scanf( "%s", tip );
        int a, b; scanf( "%d %d", &a, &b );
 
        if( tip[0] == 'A' )  T.insert( a, b-1 );
        else  printf( "%d\n", T.query( a, b ) );
    }
    return 0;
}



