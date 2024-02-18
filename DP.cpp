#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum = 0;
    int solve(vector<int>& arr, int n, int i, int s){
        if(i >= n || s == 0)
            return 0;
        int take = 2*arr[i] + solve(arr, n, i+1, s - 2*arr[i]);
        int noTake = solve(arr, n, i+1, s);

        if(abs(s - take) <= abs(sum - noTake))
            return take;
        return noTake; 
    }
    int minSubsetSumDifference(vector<int>& arr, int n){
        // Write your code here.
        for(int i = 0; i< n; i++){
            sum += arr[i];
        }
        int ans = solve(arr, n, 0, sum);
        return abs(sum - ans);
    }
};

int main(){
    Solution ob;
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> nums1(n, -1);
        vector<int> nums2(n, -1);
        for(int i = 0; i< n; i++){
            cin >> nums1[i] >> nums2[i]; 
        }
        int ans = ob.minSwap(nums1, nums2);
        cout << "Ans: " << ans;
    }
}