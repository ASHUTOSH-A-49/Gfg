/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void getLeaf(Node * root,vector<int> & leaves){
      if(!root) return;
      queue<Node*> q;
      q.push(root);
      int level = 1;
      while(!q.empty()){
          int siz = q.size();
          for(int i = 0;i<siz;i++){
              Node * temp = q.front();
              q.pop();
              if(!temp->left && !temp->right) {
                //   cout<<temp->data<<" ";
                  leaves.push_back(level);
              }
              if(temp->left)q.push(temp->left);
              if(temp->right) q.push(temp->right);
          }
          level++;
      }
      
  }
    int getCount(Node *root, int k) {
        // code here
        vector<int> leaves;
        getLeaf(root,leaves);
        // sort(leaves.begin(),leaves.end());
        // cout<<endl;
        // for(int i:leaves) cout<<i<<" ";
        int res = 0;
        for(int i:leaves){
            if(k>=i){
                k-=i;
                res++;
            }
        }
        return res;
    }
};
