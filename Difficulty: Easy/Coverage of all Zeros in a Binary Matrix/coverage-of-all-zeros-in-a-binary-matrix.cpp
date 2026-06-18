class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
           int r = mat.size();

        int c = mat[0].size();

        int totalCoverage = 0;

 

        int dRow[] = {-1, 1, 0, 0};

        int dCol[] = {0, 0, -1, 1};

 

        for (int i = 0; i < r; i++) 

            for (int j = 0; j < c; j++) 

                if (mat[i][j] == 0) {


                    for (int d = 0; d < 4; d++) {

                        int ni = i + dRow[d];

                        int nj = j + dCol[d];

 


                        while (ni >= 0 && ni < r && nj >= 0 && nj < c){

                            if (mat[ni][nj] == 1) {

                                totalCoverage++;

                                break; 
                            }

                            ni += dRow[d];

                            nj += dCol[d];

                        }

                    }

                

                }

        

        

        return totalCoverage;
        
        
    }
};
