class Solution {
  public:
    int findans(int index,vector<int>& h, vector<int>& l, int n,int visited,vector<vector<int>>&dp)
  {
      if(index >= n) return 0;
      
      if(dp[index][visited] !=0) return dp[index][visited];
      int a = 0,b = 0,c=0;
      
      b = l[index] + findans(index+1,h,l,n,1,dp); 
      if(index==0 || visited== 0)
      c = h[index] + findans(index+1,h,l,n,1,dp); 
      
      a = 0 + findans(index + 1,h,l,n,0,dp); 
      return dp[index][visited] = max({a,b,c});

  }
    int maxTask(vector<int>& h, vector<int>& l) {
        
        
        int n = l.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
       
       int visited =0;
        return findans(0,h,l,n,visited,dp);
        
    }
};