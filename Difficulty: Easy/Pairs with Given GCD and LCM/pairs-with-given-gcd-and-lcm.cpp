class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        if (y % x != 0)
                  return 0;

              int n = y / x;
              int cnt = 0;

              for (int i = 2; i * i <= n; i++) {
                  if (n % i == 0) {
                      cnt++;

                      while (n % i == 0) {
                          n /= i;
                      }
                  }
              }

              if (n > 1)
                  cnt++;

              return (1 << cnt);
    }
};