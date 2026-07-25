class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        
        
        int n=arr.size();
        int a=1;
        
        for(int i=0;i<n;){
            vector<int>sol;
            for(int j=i;j<min(i+a,n);j++){
                sol.push_back(arr[j]);
                
            }
            
            
            sort(sol.begin(),sol.end());
            ans.push_back(sol);
            i+=a;
            a*=2;
        }
        
        return ans;
        
        
    }
};
