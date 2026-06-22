class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int l=0;
        int r=height.size()-1;
        
        int area=0;
        
        while(l+1<r){
            area=max(area,(r-l-1)*(min(height[l],height[r])));
            
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }

        }
        
        return area;
    }
};