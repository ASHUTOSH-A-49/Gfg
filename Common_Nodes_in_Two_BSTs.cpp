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
  void inord(Node * r,map<int,int> & mp){
      if(r==NULL) return;
      inord(r->left,mp);
      int d= r->data;
      mp[d]++;
      inord(r->right,mp);
      
  }
    vector<int> findCommon(Node* r1, Node* r2) {
        // code here
        map<int,int> mp1,mp2;
        vector<int> ans;
        inord(r1,mp1);
        inord(r2,mp2);
        for(auto & p:mp1){
            int i = p.first;
            if(mp2.count(i)>0) ans.push_back(i);
        }
        return ans;
    }
};
