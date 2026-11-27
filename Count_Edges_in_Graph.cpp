class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        // code here
        map<pair<int,int>,int> mp;
        int n = adj.size(),cnt = 0;
        for(int i = 0;i<n;i++){
            for(auto j:adj[i]){
                if(mp.count({j,i})>0) continue;
                cnt++;
                mp[{i,j}]++;
            }
        }
        return cnt;
    }
};
