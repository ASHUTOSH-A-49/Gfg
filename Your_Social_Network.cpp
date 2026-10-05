class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> G(n + 2, 0);
        for(int i = 2; i <= n + 1; i++){
            G[i] = arr[i - 2];
        }
        
        vector<vector<int>> ans;
        vector<int> vis(n + 2, 0);
        
        for(int i = 2; i <= n + 1; i++){
            int src = i;
            int cnt = 0;
            int child = i; 
            
            while(true) {
                if(src == 1 || vis[src] == child) {
                    break;
                }
                
                vis[src] = child;
                src = G[src];
                cnt++;
                
                if(src < i && src > 0) {
                    ans.push_back({i, src, cnt});
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};
