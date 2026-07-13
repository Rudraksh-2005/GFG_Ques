class Solution {
  public:
     long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int minOperations(vector<int> &b){
        int n = b.size();
        vector<bool> visited(n + 1, false);
        long long ans = 1;
        long long MOD = 1e9 + 7;
    
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int cycle_length = 0;
                int curr = i;
                
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr - 1]; // 1 based 
                    cycle_length++;
                }
                
                long long g = gcd(ans, cycle_length);
                ans = (ans / g) * cycle_length; 
            }
        }
        
        return ans % MOD;
    }
};