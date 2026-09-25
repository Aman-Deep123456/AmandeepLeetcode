//
//    Code  Testcase Testcase  Test Result 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum.cpp
//  
//
//  Created by Amandeep on 17/09/26.
//

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> best(n, INF);
      unordered_map<int, int> mp;

        mp[0] = -1;

        int prefix = 0;
        int ans = INF;
        int minLen = INF;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            if (mp.count(prefix - target)) {
                int j = mp[prefix - target];
                int len = i - j;

                if (j >= 0 && best[j] != INF)
                    ans = min(ans, len + best[j]);

                minLen = min(minLen, len);
            }

            best[i] = minLen;

            mp[prefix] = i;
        }

        return ans == INF ? -1 : ans;
    }
};
