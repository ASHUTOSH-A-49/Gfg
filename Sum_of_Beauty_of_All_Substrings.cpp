class Solution {
  public:
    int beautySum(string &s) {
        // code here
            int ans=0;
            int n=s.size();
            for(int i=0;i<n;i++){
                vector<int> mp(26,0);
                for(int j=i;j<n;j++){
                    mp[s[j]-'a']++;
                    int minf=500,maxf=0;
                    for(int freq:mp){
                        if(freq>0){
                            minf=min(minf,freq);
                            maxf=max(maxf,freq);
                        }
                    }
                    ans+=maxf-minf;
                }
            }
            return ans;
    }
};
