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
    int DFS(Node* root,int & maxdiff){
        if(!root) return 1e8;
        int l = 1e8,r = 1e8;
        if(root->left) l = DFS(root->left,maxdiff);
        if(root->right) r = DFS(root->right,maxdiff);
        int val = root->data;
        if(l!=1e8) maxdiff  = max(maxdiff,val-l);
        if(r!=1e8) maxdiff  = max(maxdiff,val-r);
        int minchild = min(l,r);
        return min(val,minchild);
    }
    int maxDiff(Node* root) {
        // code here
        int maxdiff = INT_MIN;
        int l = 1e8,r = 1e8;
        l = DFS(root->left,maxdiff);
        r = DFS(root->right,maxdiff);
        if(l!=1e8) maxdiff  = max(maxdiff,root->data-l);
        if(r!=1e8) maxdiff  = max(maxdiff,root->data-r);
        return maxdiff;
    }
};
