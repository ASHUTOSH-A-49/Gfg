/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inord(Node *root,int k,int & ans){
        if(root==NULL) return;
        inord(root->left,k,ans);
        ans = min(ans,abs(k-root->data));
        inord(root->right,k,ans);
        
    }
    int minDiff(Node *root, int k) {
        // code here
        int ans = INT_MAX;
        inord(root,k,ans);
        return ans;
    }
};
