/*
 *	Usage: fill the grid array using desired value. 
 * 		   Use the power function for get exponent in dim^3*log(n) complexity
 *         Find my solution of spoj sumsums in this repo for example usage.  
 */

i64 fixmod(i64 a,i64 m) //For handling mod of negative numbers
{
	return (a%m + m)%m;
}
struct matrix{
	#define dim 2
	#define i64 long long 
	int n,mod;
	i64 grid[dim][dim];
	matrix(int a,int b) {n=a,mod=b; mem(grid,0);}
	
	matrix operator * (const matrix &b) {
		matrix ret(n,mod);
		rep(i,n) rep(j,n) rep(k,n)
		{
			i64 a=fixmod(grid[i][k]*b.grid[k][j],mod);
			ret.grid[i][j]= fixmod(ret.grid[i][j]+ a,mod);
		}
		return ret;
	};
	
	void power(int p)
	{
		if(p<=1) return ;
		if(p%2){
			matrix temp(n,mod);
			rep(i,n) rep(j,n) rep(k,n) temp.grid[i][j]=grid[i][j];
			power(p-1);
			(*this)=(*this)*temp;
		}
		else { (*this)=(*this)*(*this); power(p/2); }
	}
	
	void print()
	{
		rep(i,n) { rep(j,n) cout<<grid[i][j]<<" "; puts(""); }
	}
	#undef dim
	#undef i64
	
};
