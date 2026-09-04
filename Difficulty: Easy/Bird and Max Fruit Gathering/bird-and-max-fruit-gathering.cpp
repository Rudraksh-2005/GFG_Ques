class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
       
       int n = arr.size();
       int i = 0, j = 0;
       long long res = -1;
       long long sum = 0;

       while (m--)
           sum += arr[j++];
       j--;

       res = sum;

       while (i < arr.size()) {
           sum += (arr[(++j) % n] - arr[i++]);
           res = max(res, sum);
       }

       return res;
        
    }
};