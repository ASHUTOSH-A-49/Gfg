class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        vector<int> ans(n,0);
        for(int i :updates){
            ans[i-1]++;
        }
        int sum = 0;
        // for(int i:ans) cout<<i<<" ";
        // cout<<endl;
        for(int i = 0;i<n;i++){
            int orig = ans[i];
            ans[i]+=sum;
            sum+=orig;
        }
        return ans;
    }
};
