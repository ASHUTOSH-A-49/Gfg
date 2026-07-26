/*
Definition for Node
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

void travers(Node * root,int cnt,int & maxcnt){
    if(!root){
        return;
    }
    cnt++;
    maxcnt = max(maxcnt,cnt);
    travers(root->left,cnt,maxcnt);
    travers(root->right,cnt,maxcnt);
}

class Solution {
  public:
    int height(Node* root) {
        // code here
        int maxcnt = 0,cnt = 0;
        travers(root,cnt,maxcnt);
        return maxcnt-1;
    }
};
