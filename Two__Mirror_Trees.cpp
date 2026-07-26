/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        if(!a && !b) return true;
        if(!a && b || a && !b) return false;
        return(areMirror(a->left,b->right) && areMirror(a->right,b->left));
        if(a->data==b->data) return true;
        return false;
    }
};
