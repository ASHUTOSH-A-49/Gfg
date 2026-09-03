class Solution {
  public:
  int dp[1000001][2];
  int solve(int idx, vector<int> & arr,int & n,int prev){
      if(idx==n-1){
          int take = abs(1-prev);
          int keep = abs(arr[idx]-prev);
          return max(keep,take);
      }
      int choice = (prev==1) ? 1: 0;
      if(dp[idx][choice]!=-1) return dp[idx][choice];
      int take = solve(idx+1,arr,n,1);
      int keep = solve(idx+1,arr,n,arr[idx]);
      int take1 = abs(prev-1)+ take;
      int keep1 = abs(prev-arr[idx])+keep;
      if(prev==-1) return max(take,keep);
      
      return dp[idx][choice]=max(take1,keep1);
      
  }
    int maxDiffSum(vector<int>& arr) {
        // code here
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        if(n==1) return 0;
        return solve(0,arr,n,-1);
        
    }
};
