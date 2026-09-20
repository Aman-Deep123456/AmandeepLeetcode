//
//  minCostToCutaStick.cpp
//  
//
//  Created by Amandeep on 20/09/26.
//
class Solution {
      private :
    int noOfCuts(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
         if(i > j) return 0;
         if(dp[i][j] != -1 ) return dp[i][j];
         int mini = INT_MAX;
         for(int ind = i; ind<=j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + noOfCuts(i, ind-1, cuts, dp) + noOfCuts(ind+1, j, cuts, dp);
            mini = min(mini, cost);
         }
         return dp[i][j] =  mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(c+1, vector<int>(c+1,-1));
        return noOfCuts(1, c, cuts, dp);
    }
};
