//Implementation of Rabin Carp String Matching Algorithm
#include <bits/stdc++.h>
using namespace std;

#define i64 long long

//Returns the index of the first match
//Complexity O(n+m), doesn't check for collisons
int strStr(const string &haystack, const string &needle) {
    int n=haystack.size();
    int m=needle.size();
    if(n<m)return -1;
    if(m==0 or n==0)return -1;
    
    i64 B=27, mod = 1000000000+7; //Base and mod, change if needed
    
    i64 hash = 0, hashneedle = 0, mult = 1;
    
    for(int i=m-1;i>=0;i--){
        hash = hash + (haystack[i]*mult)%mod;
        hashneedle = hashneedle + (needle[i]*mult)%mod;
        hashneedle %=mod;
        hash%=mod;
        if(i!=0)
            mult = (mult * B)%mod;
    }
    
    if(hash==hashneedle)
        return 0;
        
    for(int i=m;i<n;i++){
        hash = hash - (mult*haystack[i-m])%mod;
        hash%=mod;
        hash=hash+mod;
        hash%=mod;
        hash = hash * B;
        hash%=mod;
        hash = hash + haystack[i];
        hash%=mod;
        if(hash==hashneedle)
            return i-m+1;
    }
    return -1;
}


int main() {
    freopen("in", "r", stdin);
    cout<<strStr("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba", "babaaa")<<endl;
    
    return 0;
}
