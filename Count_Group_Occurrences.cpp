class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        map<char,int> mp;
        int n = s.size();
        for(int i = 0;i<n;i++){
            while(i+1<n && s[i]==s[i+1]) {
                i++;
            }
            if(i>=n) mp[s[n-1]]++;
            else mp[s[i]]++;
        }
        int cnt = 0;
        for(auto & p:mp){
            // cout<<p.first<<" "<<p.second<<endl;
            if(p.second==k) cnt++;
        }
        return cnt;
    }
};
