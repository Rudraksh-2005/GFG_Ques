class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
         int n = s.size();

        vector<int> first(26, -1);

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
        }

        for (int i = 0; i < n; i++) {

            for (int ch = 0; ch < (s[i] - 'a'); ch++) {

                if (first[ch] > i) {

                    char c1 = s[i];
                    char c2 = char(ch + 'a');

                    for (int j = 0; j < n; j++) {
                        if (s[j] == c1)
                            s[j] = c2;
                        else if (s[j] == c2)
                            s[j] = c1;
                    }

                    return s;
                }
            }
        }

        return s;
        
        
    }
};
