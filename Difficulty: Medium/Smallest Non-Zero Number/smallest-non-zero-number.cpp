class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
           int a = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            a = (a + arr[i] + 1) / 2;
        }

        return a;
    }
};