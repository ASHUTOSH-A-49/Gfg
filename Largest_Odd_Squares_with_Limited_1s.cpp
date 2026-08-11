class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pref[i][j] = mat[i - 1][j - 1] 
                           + pref[i - 1][j] 
                           + pref[i][j - 1] 
                           - pref[i - 1][j - 1];
            }
        }
        vector<int> fans;
        for(auto q:queries){
            int i = q[0],j = q[1];
            int max_radius = min({i, j, n - 1 - i, m - 1 - j});
            int l = 0,r = max_radius,ans = -1;
            while(l<=r){
                int mid = l+(r-l)/2;
                int r1 = i-mid,c1 = j-mid;   
                int r2 = i+mid+1, c2=j+mid+1;
                if(r1>=0 && c1>=0 && r2<=n && c2<=m){
                    int cnt1 = pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1]; 
                    if(cnt1<=k){
                        // cout<<cnt1<<endl;
                        ans = 2*mid+1;
                        l = mid+1;
                    }else r = mid-1;
                }else{
                    r = mid-1;
                }
            }
            fans.push_back(ans);
            
        }
        return fans;
    }
};
