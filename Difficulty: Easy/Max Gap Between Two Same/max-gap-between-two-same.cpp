class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n=s.size();
        unordered_map<char,vector<int>>mpp;
        
        int maxi=-1;
        
        
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]].push_back(i);
            }
            else{
                int a=mpp[s[i]].back();
                maxi=max(maxi,i-a-1);
            }
        }
        
        
        return maxi;
        
    }
};