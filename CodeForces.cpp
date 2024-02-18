//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int mod = 1e9+7;
    int solve(int n, int r, vector<vector<int>>& dp){
		if((n < r) || (n < 0))
			return 0;
		if((n > 0 && r == 0) || (n == r))
			return 1;
		if(dp[n][r] != -1)
			return dp[n][r];
		int take = solve(n-1, r-1, dp);
		int notTake = solve(n-1, r, dp);
		dp[n][r] = (take + notTake)%mod;
		return dp[n][r];
    }
	int solveTab(int n, int r){
		//vector<vector<int>> dp(n+1, vector<int>(r+1, 0));
		vector<int> curr(r+1, 0);
		vector<int> prev(r+1, 0);

		// for(int i = 0; i<= n; i++){
		// 	dp[i][0] = 1;
		// 	if(i <= min(n, r))
		// 		dp[i][i] = 1; 
		// }
		int ans;

		for(int N = 1; N<= n; N++){
			cout << N << " : ";
			curr[0] = 1;
			prev[0] = 1;

			prev[N-1] = 1;
			curr[N] = 1;
			for(int R = 1; R <= r; R++){
				if(N >= R){
					cout << R << " ";
					int take = prev[R-1];
					int notTake = prev[R];
					curr[R] = (take + notTake)%mod;
				}
			}
			cout << endl;
			cout << "Prev: ";
			for(int i = 0; i<= r; i++)
				cout << prev[i] << " ";
			cout << endl;
			cout << "Curr: ";
			for(int i = 0; i<= r; i++)
				cout << curr[i] << " ";
			cout << endl;

			prev = curr;
			ans = curr[r];
		}
		return ans;
	}
    int nCr(int n, int r){
        // code here
		//vector<vector<int>> dp(n+1, vector<int> (r+1, -1));
        int ans = solveTab(n, r);
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, r;
		cin >> n >> r;
		Solution ob;
		int ans = ob.nCr(n, r);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends