class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
          int ans=0;
      sort(arr.begin(), arr.end());
      
      int n=arr.size();
      for(int i=0; i<n; i++){
        int li = lower_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin();
        if((li-1-i) > 0) ans+=(li-1-i);
      }
      
      return ans;
    }
};