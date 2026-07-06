class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
      
        int n = a.size();
        int m = b.size();

        int i = 0, j = 0;

        long long sumA = 0;
        long long sumB = 0;
        long long ans = 0;

        while (i < n && j < m) {

            if (a[i] < b[j]) {
                sumA += a[i++];
            }
            else if (a[i] > b[j]) {
                sumB += b[j++];
            }
            else {
                ans += max(sumA, sumB) + a[i];

                sumA = 0;
                sumB = 0;

                i++;
                j++;
            }
        }

        while (i < n)
            sumA += a[i++];

        while (j < m)
            sumB += b[j++];

        ans += max(sumA, sumB);

        return ans;
        
    }
};