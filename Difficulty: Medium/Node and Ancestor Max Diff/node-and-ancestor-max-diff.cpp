/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int ans;

    int dfs(Node* node) {
        if (node == nullptr) {
            return INT_MAX;
        }

        int leftMin = dfs(node->left);
        int rightMin = dfs(node->right);

        if (node->left != nullptr) {
            ans = max(ans, node->data - leftMin);
        }

        if (node->right != nullptr) {
            ans = max(ans, node->data - rightMin);
        }

        return min(node->data, min(leftMin, rightMin));
    }

    int maxDiff(Node* root) {
        ans = INT_MIN;

        dfs(root);

        return ans;
        // code here
        
    }
};