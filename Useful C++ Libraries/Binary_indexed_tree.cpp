/*
 * Usage: Use update function to add x in index idx. 
 *        Use query function for cumulative sum from 1 to idx.
 */
#define MAX 100000
int tree[MAX];
int query(int idx) 
{
       int sum=0;
       while(idx>0)
       {
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;

}
void update(int idx, int x, int n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
       

}
