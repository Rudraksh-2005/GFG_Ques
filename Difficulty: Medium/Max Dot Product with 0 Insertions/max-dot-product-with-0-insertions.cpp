class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
         int n = a.size(), m = b.size();

        const int NEG = -1e9;

        vector<int> dp(m + 1, NEG);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            vector<int> ndp = dp;

            for (int j = 1; j <= min(i, m); j++) {

                ndp[j] = max(ndp[j], dp[j]);

                if (dp[j - 1] != NEG) {
                    ndp[j] = max(ndp[j],
                                 dp[j - 1] + a[i - 1] * b[j - 1]);
                }
            }

            dp = ndp;
        }

        return dp[m];
    }
    
};
