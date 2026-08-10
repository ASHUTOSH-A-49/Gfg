class Solution {
  public:
    int unvisitedLeaves(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> vis(k+1,0);
        for(int i:arr){
            if(i>k) continue;
            int mul = 1;
            if(vis[i]) continue;
            while(i*mul<=k){
                int res = i*mul;
                vis[res] = 1;
                mul++;
            }
        }
        int cnt = 0;
        for(int i = 1;i<=k;i++){
            
            if(vis[i]==0) cnt++;
        }
        return cnt;
    }
};
