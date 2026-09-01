class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_map<char,int> cnt,drop;
        int res = 0;
        for(char c:s){
            if(cnt.count(c)){
                cnt.erase(c);
            }else{
                if(drop.count(c)) drop.erase(c);
                else if(cnt.size()==n) {
                    drop[c]++;
                    // cout<<c<<" ";
                    res++;
                }
                else cnt[c]++;
            }
            
            
            
        }
        return res;
    }
};
