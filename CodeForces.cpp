#include<bits/stdc++.h>
using namespace std;
int digit_sum(int n){
    int ans = 0;
    while(n!=0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x, k;
        cin >> x >> k;
        while(digit_sum(x) % k){
            x+=1;
        }
        cout << x << endl;
    }
    return 0;
}