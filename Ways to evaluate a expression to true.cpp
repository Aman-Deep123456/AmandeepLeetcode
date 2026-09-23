//
//  Ways to evaluate a expression to true.cpp
//  
//
//  Created by Amandeep on 23/09/26.
//

#define ll long long
int mod = 1000000007;

class Solution {
private:

    ll parser(string &s, int i, int j, bool isTrue,
              vector<vector<vector<ll>>> &dp) {

        if (i > j)
            return 0;

        if (i == j) {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        ll ways = 0;

        for (int idx = i + 1; idx <= j - 1; idx += 2) {

            ll lT = parser(s, i, idx - 1, true, dp);
            ll lF = parser(s, i, idx - 1, false, dp);

            ll RT = parser(s, idx + 1, j, true, dp);
            ll RF = parser(s, idx + 1, j, false, dp);

            if (s[idx] == '&') {

                if (isTrue) {
                    ways = (ways + (lT * RT) % mod) % mod;
                }
                else {
                    ways = (ways
                            + (lT * RF) % mod
                            + (lF * RT) % mod
                            + (lF * RF) % mod) % mod;
                }
            }

            else if (s[idx] == '|') {

                if (isTrue) {
                    ways = (ways
                            + (lT * RT) % mod
                            + (lF * RT) % mod
                            + (lT * RF) % mod) % mod;
                }
                else {
                    ways = (ways + (lF * RF) % mod) % mod;
                }
            }

            else { // XOR

                if (isTrue) {
                    ways = (ways
                            + (lF * RT) % mod
                            + (lT * RF) % mod) % mod;
                }
                else {
                    ways = (ways
                            + (lT * RT) % mod
                            + (lF * RF) % mod) % mod;
                }
            }
        }

        return dp[i][j][isTrue] = ways;
    }

public:

    int countTrue(string s) {

        int n = s.size();

        vector<vector<vector<ll>>> dp(
            n,
            vector<vector<ll>>(n, vector<ll>(2, -1))
        );

        return parser(s, 0, n - 1, true, dp);
    }
};
