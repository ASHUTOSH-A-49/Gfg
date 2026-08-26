class Solution {
  public:
//TABULATION (BOTTOM -UP) SOLUTION with space optimization
    int maximumPath(vector<vector<int>>& mat) {
        
        // code here
        int n = mat.size(),m = mat[0].size();
        vector<int> dp(m,0); 
        //base case:
        for(int i = 0;i<m;i++){    // - O(M)
        //base case
            dp[i] = mat[n-1][i];
        }
        int t0 = 0,t = dp[0],t1 = 0;
        if(m>1) t1 = dp[1];
        for(int i = n-2;i>=0;i--){ // - O(N*M)
            for(int j = 0;j<m;j++){
                dp[j] = mat[i][j] + max({t0,t,t1});
                if(j+1==m){
                    t0 = 0,t= dp[0];
                    if(m>1) t1 = dp[1];
                }else{
                    t0 = t;
                    t = t1;
                    (j+2<m) ?t1 = dp[j+2] : t1=0;
                    
                }
                
            }
        }
        int ans = 0;
        for(int i = 0;i<m;i++) ans = max(ans,dp[i]); //-O(M)
        return ans;
    }
};
