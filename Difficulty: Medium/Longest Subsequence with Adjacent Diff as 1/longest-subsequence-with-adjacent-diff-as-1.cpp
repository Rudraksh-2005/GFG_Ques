class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int,int>m;
        int n = arr.size();
        int ans = 1;

        for(int i=0;i<n;i++){

            int pre = (m.count(arr[i]-1))?m[arr[i]-1]:0;
            int next = (m.count(arr[i]+1))?m[arr[i]+1]:0;
            m[arr[i]] = 1+max(pre,next);
            ans = max(ans,m[arr[i]]);
        }

        return ans;
    }
};