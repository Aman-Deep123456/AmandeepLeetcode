class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, 0);
        for(int ind = n-1; ind>=0; ind--){
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            int len = 0;
            for(int j=ind; j<min(ind+k,n); j++){
              len++;
              maxi = max(maxi, arr[j]);
              int sum = len*maxi + dp[j+1];
              maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }
        return dp[0];
    }
};