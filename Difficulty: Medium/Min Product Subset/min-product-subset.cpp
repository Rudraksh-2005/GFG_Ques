class Solution {
  public:
      int minProd(vector<int>& arr) {
          int n = arr.size();

          int negCount = 0;
          int zeroCount = 0;
          int maxNeg = INT_MIN;
          int minPos = INT_MAX;

          long long prod = 1;

          for (int x : arr) {
              if (x == 0) {
                  zeroCount++;
                  continue;
              }

              if (x < 0) {
                  negCount++;
                  maxNeg = max(maxNeg, x);
              }

              if (x > 0) {
                  minPos = min(minPos, x);
              }

              prod *= x;
          }
          
          
          if (zeroCount == n)
              return 0;

          if (negCount == 0) {
              if (zeroCount > 0)
                  return 0;
              return minPos;
          }
          if (negCount % 2 == 0)
              prod /= maxNeg;

          return (int)prod;
      }
  };