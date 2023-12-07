#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int dp[501][501];
    bool isPalindrome(string str, int start, int end){
        while(start<=end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int func(string str, int s, int e){
        //cout << "Code enters with s: " << s << " and e : " << e << endl;
        if(s>e){
            dp[s][e] = INT_MAX;
            return INT_MAX;
        }
        if(dp[s][e]!=-1 && dp[s][e] != INT_MAX){
            return dp[s][e];
        }
        if(isPalindrome(str, s, e)){
            dp[s][e] = 0;
            return 0;
        }
        //cout << "Code enters 4" << endl;
        int splits = INT_MAX;
        for(int i = s; i<e; i++){
            int spt = 1 + func(str, s, i) + func(str, i+1, e);
            //cout << "spt = " << spt << endl;
            splits = min(splits, spt);
        }
        //cout << "Splits = " << splits << endl;
        dp[s][e] = splits;
        return dp[s][e];
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        memset(dp, -1, sizeof(dp));
        int ans = func(str, 0, n-1);
        printDP(n);
        return dp[0][n-1];
    }
    int palindrome2(string str){
        int n = str.length();
        memset(dp, -1, sizeof(dp));
        if(isPalindrome(str, 0, n-1)){
            return 0;
        }
        for(int i = 0; i< n; i++){
            for(int j = i; j< n; j++){
                if(isPalindrome(str, i, j)){
                    dp[i][j] = 0;
                }
                else{
                    for(int k = i; k< j; k++){
                        int spt = 1+ dp[i][k] + dp[k+1][j];
                    }
                }
            }
        }
    }
    void printDP(int n){
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
    string str;
    cin>>str;
    
    Solution ob;
    cout<<ob.palindromicPartition(str)<<"\n";
    return 0;
}