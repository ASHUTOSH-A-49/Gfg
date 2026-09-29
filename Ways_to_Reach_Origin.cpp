class Solution {
  public:
  int MOD = 1e9+7;
  vector<vector<int>> dp;
  int solve(int i,int j,int &x,int&y){
      if(i>x || j>y) return 0;
      if(i==x && j==y) return 1;
      if(dp[i][j]!=-1) return dp[i][j];
      long long r = solve(i+1,j,x,y)%MOD;
      long long u = solve(i,j+1,x,y)%MOD;
      return dp[i][j] = (r+u)%MOD;
  }
    int ways(int x, int y) {
        // code here
        dp.assign(x+1,vector<int>(y+1,-1));
        return solve(0,0,x,y);
    }
};
