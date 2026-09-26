class Solution {
  public:
    vector<int> dp;
    int c1,c2,c3,a1,a2,a3;
    
    int solve(int ar){
        if(ar<=0){
            return 0;
        }
        if(dp[ar]!=-1) return dp[ar];
        int s = c1 + solve(ar-a1);
        int m = c2 + solve(ar-a2);
        int l = c3 + solve(ar-a3);
        return dp[ar] = min({s,m,l});
        
    }
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        dp.assign(x+1,-1);
        c1 = cs;c2 = cm;c3 = cl;
        a1 = s;a2 = m;a3 = l;
        return solve(x);
    }
};
