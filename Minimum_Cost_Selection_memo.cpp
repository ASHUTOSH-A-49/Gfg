class Solution {
    public:
    int dp[100001][4];
    int solve(int n,int i,vector<vector<int>>& g,int prev)
    {
        if(i==n-1){
            //base case
            if(prev==0){
                return min(g[i][1],g[i][2]);
            }else if (prev==1){
                return min(g[i][0],g[i][2]);

            }else if(prev==2)
            return min(g[i][0],g[i][1]);

            return min({g[i][0],g[i][1],g[i][2]});
        }
        if(dp[i][prev]!=-1) return dp[i][prev];
        int t0,t1,t2;
        t0= g[i][0]+ solve(n,i+1,g,0);
        t1= g[i][1] + solve(n,i+1,g,1);
        t2= g[i][2] + solve(n,i+1,g,2);
        if(prev==0){
            return dp[i][0]=min(t1,t2);
        }else if (prev==1){
            return dp[i][1]=min(t0,t2);
        }else if(prev==2){
            return dp[i][2]=min(t0,t1);
        }

        return dp[i][3]=min({t0,t1,t2});

    }
      int minCost(vector<vector<int>>& mat) {
          // code here
          memset(dp,-1,sizeof(dp));
          int n=mat.size();
          return solve(n,0,mat,3);
      }
  };
