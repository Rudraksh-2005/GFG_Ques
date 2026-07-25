class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
           int n=mat.size(), m=mat[0].size();    
      
      vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
      for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
          pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];    
        }  
      }
      
      
      
      int ans=INT_MIN;
      for(int i=k; i<=n; i++){
        for(int j=k; j<=m; j++){
          int sum = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k];
          ans=max(ans, sum);
        }  
      }
      
      return ans;
    }
};