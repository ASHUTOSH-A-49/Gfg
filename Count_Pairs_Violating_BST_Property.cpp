/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

vector<int> countSmallerToRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    vector<int> seen;
    for (int i = n - 1; i >= 0; --i) {
        auto it = lower_bound(seen.begin(), seen.end(), nums[i]);
        result[i] = distance(seen.begin(), it);
        seen.insert(it, nums[i]);
    }

    return result;
}

void inorder(Node *root,vector<int> & ans){
    if(!root) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

class Solution {
  public:
    int pairsViolatingBST(Node *root) {
        // code here
        vector<int> inord;
        inorder(root,inord);
        vector<int> cnt = countSmallerToRight(inord);
        int ans = 0;
        for(int i:cnt){
            ans+=i;
        }
        return ans;
    }
};
