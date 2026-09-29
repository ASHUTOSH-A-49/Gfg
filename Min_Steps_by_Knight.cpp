class Solution {
  public:
    int solve(vector<int> & knightPos, vector<int> & targetPos, int & n){
            int kx = knightPos[0] - 1, ky = knightPos[1] - 1;
            int tx = targetPos[0] - 1, ty = targetPos[1] - 1;
            if (kx == tx && ky == ty) return 0;

            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int,int>> q;

            q.push({kx, ky});
            vis[kx][ky] = true;
            int lev = 0;
            while(!q.empty()){
                int curr = q.size();

                for(int i = 0; i < curr; i++) {
                    auto [x, y] = q.front();
                    q.pop();

                    if(x == tx && y == ty) return lev;

                    // 1
                    if(x+2<=n-1 && y+1<=n-1 && !vis[x+2][y+1]) {
                        q.push({x+2,y+1});
                        vis[x+2][y+1] = true;
                    }
                    // 2
                    if(x+2<=n-1 && y-1>=0 && !vis[x+2][y-1]) {
                        q.push({x+2,y-1});
                        vis[x+2][y-1] = true;
                    }
                    // 3
                    if(x-2>=0 && y+1<=n-1 && !vis[x-2][y+1]) {
                        q.push({x-2,y+1});
                        vis[x-2][y+1] = true;
                    }
                    // 4
                    if(x-2>=0 && y-1>=0 && !vis[x-2][y-1]) {
                        q.push({x-2,y-1});
                        vis[x-2][y-1] = true;
                    }
                    // 5
                    if(x+1<=n-1 && y+2<=n-1 && !vis[x+1][y+2]) {
                        q.push({x+1,y+2});
                        vis[x+1][y+2] = true;
                    }
                    // 6
                    if(x+1<=n-1 && y-2>=0 && !vis[x+1][y-2]){
                        q.push({x+1,y-2});
                        vis[x+1][y-2] = true;
                    }
                    // 7
                    if(x-1>=0 && y+2<=n-1 && !vis[x-1][y+2]) {
                        q.push({x-1,y+2});
                        vis[x-1][y+2] = true;
                    }
                    // 8
                    if(x-1>=0 && y-2>=0 && !vis[x-1][y-2]) {
                        q.push({x-1,y-2});
                        vis[x-1][y-2] = true;
                    }
                }
                lev++;
            }
            return -1;
        }

        int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
            return solve(knightPos, targetPos, n);
        }
};
