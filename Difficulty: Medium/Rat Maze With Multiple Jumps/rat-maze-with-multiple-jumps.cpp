class Solution {
  public:
    bool solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&ans,int n){
        if(i==n-1 && j==n-1){
            ans[i][j]=1;
            return true;
        }
        
        if(i>=n || j>=n || mat[i][j]==0){
            return false;
        }
        
        ans[i][j]=1;
        int jump=mat[i][j];
        
        for(int k=1;k<=jump;k++){
            if(solve(i,j+k,mat,ans,n))return true;
            if(solve(i+k,j,mat,ans,n))return true;
        }
        
        mat[i][j]=0;
        ans[i][j]=0;
        
        return false;
    }
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        if(solve(0,0,mat,ans,n)){
            return ans;
            
        }
        
        return {{-1}};
    }
};