class Solution {
  public:
  
   int mode=1e9+7;
    int svc(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
      if(j==s2.size()) return 1;
      if(i==s1.size()) return 0;
      
      if(dp[i][j] != -1) return dp[i][j];
      
      int t=0, nt=0;
      if(s1[i] == s2[j]) t=svc(i+1, j+1, s1, s2, dp);
      
      nt=svc(i+1, j, s1, s2, dp);
      
      
      return dp[i][j]=(t+nt)%mode;
    }
    
    
    int countWays(string &s1, string &s2){
      int n1=s1.size();
      int n2=s2.size();
      
      vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
      
      return svc(0, 0, s1, s2, dp);
    }
};
