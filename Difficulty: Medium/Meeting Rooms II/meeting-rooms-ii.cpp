class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        
        map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            mpp[start[i]]++;
            mpp[end[i]]--;
        }
        
        int ans=0;
        int room=0;
        
        for(auto it:mpp){
            ans+=it.second;
            room=(max(room,ans));
        }
        
        return room;
    }
};
