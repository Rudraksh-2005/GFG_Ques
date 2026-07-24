class Solution {
public:
    int help(Node* root, int &ans) {
        if (root == NULL)
            return 0;

        int left = help(root->left, ans);
        int right = help(root->right, ans);

        int curr = 1;

        if (root->left && root->left->data == root->data + 1)
            curr = max(curr, left + 1);

        if (root->right && root->right->data == root->data + 1)
            curr = max(curr, right + 1);

        ans = max(ans, curr);

        return curr;
    }

    int longestConsecutive(Node* root) {
        if (root == NULL)
            return -1;

        int ans = 0;
        help(root, ans);

        return (ans == 1) ? -1 : ans;
    }
};