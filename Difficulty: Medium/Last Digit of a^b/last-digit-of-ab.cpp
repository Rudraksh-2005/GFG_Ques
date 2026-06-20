class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
         if (b == "0") return 1;

        int base = a.back() - '0';

        int exp = 0;
        for(char ch : b) {
            exp = (exp * 10 + (ch - '0')) % 4;
        }

        if(exp == 0) exp = 4;

        int res = 1;

        while(exp > 0) {
            if(exp & 1)
                res = (res * base) % 10;

            base = (base * base) % 10;
            exp >>= 1;
        }

        return res;
    }
};