class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
            int n1 = s1.length();
        int n2 = s2.length();

        // Prefix LCS DP
        vector<vector<int>> pre(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    pre[i][j] = pre[i - 1][j - 1] + 1;
                } else {
                    pre[i][j] = max(pre[i - 1][j], pre[i][j - 1]);
                }
            }
        }

        // Suffix LCS DP
        vector<vector<int>> suf(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    suf[i][j] = suf[i + 1][j + 1] + 1;
                } else {
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
                }
            }
        }

        int lcs = pre[n1][n2];
        int ans = 0;

        // Try every insertion position
        for (int pos = 0; pos <= n1; ++pos) {
            for (int ch = 0; ch < 26; ++ch) {
                char c = 'a' + ch;
                bool ok = false;
                for (int j = 0; j < n2; ++j) {
                    if (s2[j] == c && pre[pos][j] + suf[pos][j + 1] == lcs) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
