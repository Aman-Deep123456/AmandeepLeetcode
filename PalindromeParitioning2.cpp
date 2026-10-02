class Solution {
     bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false ;
            i++;
            j--;
        }
        return true ; 
     }
     int func(int i, int n, string str, vector<int> &dp){
        if(i == n) return 0;
        int minCost = INT_MAX;
        if(dp[i]!= -1) return dp[i];
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, str)){
                int cost = 1 + func(j+1, n, str, dp);
                minCost = min(cost, minCost);
            }
        }
    return dp[i] = minCost; 
     }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return func(0, n, s, dp) -1;
    }
};