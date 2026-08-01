class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
          vector<long long> diff(n + 1, 0);

        for (int i = 0; i < a.size(); i++) {

            diff[a[i]] += k[i];

            if (b[i] + 1 < n)
                diff[b[i] + 1] -= k[i];
        }

        long long current = 0;
        long long maximum = 0;

        for (int i = 0; i < n; i++) {

            current += diff[i];

            maximum = max(maximum, current);
        }

        return (int)maximum;
    }
};