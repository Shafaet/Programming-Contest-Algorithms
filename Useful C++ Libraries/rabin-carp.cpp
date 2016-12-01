//Implementation of Rabin Carp String Matching Algorithm
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

//Returns the index of the first match
//Complexity O(n+m), this is unsafe because it doesn't check for collisons

i64 Hash(const string &s, int m, i64 B, i64 M){
    i64 h = 0 , power = 1;
    for(int i = m-1;i>=0;i--){
        h = h + (s[i] * power) % M;
        h = h % M;
        power = (power * B)%M;
    }
    return h;
}
int match(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    if(n < m)return -1;
    if(m == 0 or n == 0)
        return -1;
    
    i64 B = 347, M = 1000000000+7; 
    
    //Calculate B^(m-1)
    i64 power = 1;
    for(int i=1;i<=m-1;i++)
        power = (power * B) % M;
    
    //Find hash value of first m characters of text
    //Find hash value of pattern
    i64 hash_text = Hash(text, m, B, M);
    i64 hash_pattern = Hash(pattern, m, B, M);
    
    if(hash_text == hash_pattern){  //returns the index of the match
        return 0;
        //We should've checked the substrings character by character here as hash collision might happen
    }
        
    for(int i=m;i<n;i++){
        
        //Update Rolling Hash
        hash_text = (hash_text - (power * text[i-m]) % M) % M;
        hash_text = (hash_text + M) % M; //take care of M of negative value
        hash_text = (hash_text * B) % M;
        hash_text = (hash_text + text[i]) % M;
        
        if(hash_text==hash_pattern){
            return i - m + 1; //returns the index of the match
             //We should've checked the substrings character by character here as hash collision might happen
        }
    }
    return -1;
}


int main() {
    cout<<match("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba", "babaaa")<<endl;
    return 0;
}
