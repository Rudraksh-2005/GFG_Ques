class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int cnt=0;
        int i=1;
        int s=1;
        
        while(p>=s){
            
            p-=(i*i);
            
            cnt++;
            i++;
            s=i*i;
            
        }
        
        return cnt;
    }
};
