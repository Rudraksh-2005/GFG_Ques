class Solution {
public:

    bool dfs(int node, vector<int>& state,
             vector<vector<int>>& adj,
             stack<int>& st) {

        state[node] = 1;  // currently visiting

        for (auto next : adj[node]) {

            // Cycle found
            if (state[next] == 1) {
                return true;
            }

            if (state[next] == 0) {
                if (dfs(next, state, adj, st)) {
                    return true;
                }
            }
        }

        state[node] = 2;  // completely processed
        st.push(node);

        return false;
    }


    string findOrder(vector<string>& words) {

        int n = words.size();

        vector<int> used(26, 0);

        // Mark used characters
        for (auto& word : words) {
            for (char ch : word) {
                used[ch - 'a'] = 1;
            }
        }

        vector<vector<int>> adj(26);

        // Build graph
        for (int i = 0; i < n - 1; i++) {

            string& s1 = words[i];
            string& s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            int j = 0;

            for (; j < len; j++) {

                if (s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);

                    break;
                }
            }

            // Invalid prefix case
            if (j == len && s1.size() > s2.size()) {
                return "";
            }
        }


        vector<int> state(26, 0);
        stack<int> st;

        // DFS + cycle detection
        for (int i = 0; i < 26; i++) {

            if (used[i] && state[i] == 0) {

                if (dfs(i, state, adj, st)) {
                    return "";
                }
            }
        }


        string ans = "";

        while (!st.empty()) {
            ans += char(st.top() + 'a');
            st.pop();
        }

        return ans;
    }
};