class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        vector<int>val;
        
        for(int i=0;i<l.size();i++){
            int m=l[i];
            int n=r[i];
            for(int j=m;j<=n;j++){
                val.push_back(j);
            }
        }
        
        
        
        
        vector<int>ans;
        
        for(int i=0;i<rank.size();i++){
            ans.push_back(val[rank[i]-1]);
        }
        
        return ans;
    }
};