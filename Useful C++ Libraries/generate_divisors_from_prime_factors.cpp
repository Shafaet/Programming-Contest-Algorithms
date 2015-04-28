//This function generates all the divisors of a number from its prime factors.
//p is list of prime factors of n
//e is the list of powers
//m is length of p and e
//(n = p_1^e_1 * p_2^e_2 * p_3^e_3 * ... * p_m^e_m)
//complexity O(no of divisors)
void iterate_divisors(int *p,int *e,int m)
{
	int cnt = 1, divisors[10000]; divisors[0] = 1; 
	m=3;
	for (int i = 0; i < m; i++){
			int hi = cnt;
			int lo=0;
			for (int j = 0; j < e[i]; j++)
			{
				int tmp=cnt;
				for (int k = lo; k<hi; k++){ 
					divisors[cnt++] = p[i] * divisors[k];
				}
				lo=tmp;		hi=cnt; 
			}
	}
	sort(divisors,divisors+cnt);
    rep(i,cnt)cout<<" "<<divisors[i];
    puts("");
    cout<<cnt<<endl;
		
}
