class Solution {
  public:
//TABULATION (BOTTOM -UP) SOLUTION
    int maximumPath(vector<vector<int>>& mat) {
        
        // code here
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0)); 
        //base case:
        for(int i = 0;i<m;i++){    // - O(M)
            dp[n-1][i] = mat[n-1][i];
        }
        for(int i = n-2;i>=0;i--){ // - O(N*M)
            for(int j = 0;j<m;j++){
                int t0 = 0,t = dp[i+1][j],t1 = 0;
                if(j-1>=0) t0 = dp[i+1][j-1];
                if(j+1<m) t1 = dp[i+1][j+1];
                
                dp[i][j] = mat[i][j] + max({t0,t,t1});
                
            }
        }
        int ans = 0;
        for(int i = 0;i<m;i++) ans = max(ans,dp[0][i]); //-O(M)
        return ans;
    }
};
