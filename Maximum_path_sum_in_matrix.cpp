class Solution {
  public:
  int dp[501][501];
    int solve(int i,int j,int n,int m,vector<vector<int>>& g){
        if(j==m || j<0) return 0;
        if(i==n-1) return g[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int t0 = solve(i+1,j-1,n,m,g);
        int t = solve(i+1,j,n,m,g);
        int t1 = solve(i+1,j+1,n,m,g);
        
        return dp[i][j] = g[i][j]+max({t0,t,t1});
    }
    int maximumPath(vector<vector<int>>& mat) {
        
        // code here
        memset(dp,-1,sizeof(dp));
        int n = mat.size(),m = mat[0].size();
        int ans = 0;
        for(int i = 0;i<m;i++) ans = max(ans,solve(0,i,n,m,mat));
        return ans;
    }
};
