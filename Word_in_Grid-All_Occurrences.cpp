class Solution {
  public:
  void solve(int &strti,int &strtj,int prev,int i,int j,int idx,vector<vector<char>> &mat,string& word,vector<vector<int>>& vis,set<pair<int,int>> & ans){
      if(idx>=word.size()) return;
      if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return;
      if(mat[i][j]!=word[idx]) return;
      if(vis[i][j]) return;
      if(idx==word.size()-1) ans.insert({strti,strtj});
      vis[i][j] = 1;
      //all 8 dir.n
      if(prev==0 || prev==1) solve(strti,strtj,1,i,j+1,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==2) solve(strti,strtj,2,i+1,j+1,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==3) solve(strti,strtj,3,i+1,j,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==4) solve(strti,strtj,4,i+1,j-1,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==5) solve(strti,strtj,5,i,j-1,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==6) solve(strti,strtj,6,i-1,j-1,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==7) solve(strti,strtj,7,i-1,j,idx+1,mat,word,vis,ans);
      if(prev==0 || prev==8) solve(strti,strtj,8,i-1,j+1,idx+1,mat,word,vis,ans);
  }
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size(),m = mat[0].size();
        set<pair<int,int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                vector<vector<int>> vis(n,vector<int> (m,0));
                solve(i,j,0,i,j,0,mat,word,vis,ans);
            }
        }
        vector<vector<int>> res;
        for(auto p:ans){
            vector<int> e = {p.first,p.second};
            res.push_back(e);
        }
        return res;
    }
};
