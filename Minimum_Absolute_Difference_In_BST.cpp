class Solution {
  public:
    void solve(Node * root,vector<int> & arr){
        if(!root) return;
        solve(root->left,arr);
        arr.push_back(root->data);
        solve(root->right,arr);
        
    }
    int absDiff(Node *root) {
        // code here
        vector<int> arr;
                solve(root, arr);
                int minDiff = INT_MAX; 
                for (int i = 1; i < arr.size(); i++) {
                    minDiff = min(minDiff, arr[i] - arr[i-1]);
                }

                return minDiff;
    }
};
