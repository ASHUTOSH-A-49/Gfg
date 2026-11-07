class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        vector<string> ans;
        map<string,int> mp;
        for(string s:arr){
            mp[s]++;
        }
        map<string,int> mp2;
        for(string s:arr){
            string s2 = s;
            if (mp2.count(s)) {
                int cnt = 1;
                while (mp.count(s + std::to_string(cnt)) > 0) cnt++;
                s2 = s + std::to_string(cnt);
            }
            mp2[s2]++;
            mp[s2]++;
            ans.push_back(s2);
        }
        return ans;
    }
};
