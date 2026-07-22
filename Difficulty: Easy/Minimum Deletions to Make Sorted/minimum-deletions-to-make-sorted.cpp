class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int> v;
v.push_back(arr[0]);
for (int i = 1; i<arr.size(); i++) {
if (arr[i] > v[v.size() - 1]) {
v.push_back(arr[i]);
continue;
}
int a = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
v[a] = arr[i];
}
return arr.size() - v.size();
    }
};