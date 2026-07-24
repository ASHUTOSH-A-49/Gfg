/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  int ans = 0;
    int maxPath(Node* root) {
        if (!root) return 0;
        int left = 0, right = 0;
        if (root->left) {
            int left_path = maxPath(root->left);
            if (root->left->data-root->data == 1) left = left_path;
        }
        if (root->right) {
            int right_path = maxPath(root->right);
            if (root->right->data-root->data == 1) right = right_path;
        }
        int curr = max(left, right) + 1;
        ans = max(ans, curr);
        return curr;
    }
    int longestConsecutive(Node* root) {
        // code here
        if (!root) return -1;
        ans = 0;
        maxPath(root);
        if (ans<2) return -1;
        return ans;
    }
};
