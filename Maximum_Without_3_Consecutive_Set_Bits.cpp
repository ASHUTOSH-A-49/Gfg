class Solution {
  public:
    string inttoBin(int n){
        string s = "";
        while(n>0){
            int d = n%2;
            s+=(d==1)?'1':'0';
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int BintoInt(string &s){
        int n = s.size();
        // cout<<n<<endl;
        int ans = 0,k = 1;
        for(int i = 0;i<n;i++){
            ans+=k*(s[i]-'0');
            // cout<<ans<<endl;
            k = k<<1;
        }
        return ans;
    }
    int maxValue(int n) {
        // code here
        string s = inttoBin(n);
        // cout<<s<<endl;
        int siz = s.size();
        int cnt = 0;
        for(int i = 0;i<siz;i++){
            char c = s[i];
            if(c=='1') cnt++;
            else cnt = 0;
            if(cnt==3){
                s[i] = '0';
                cnt = 0;
            }
        }
        // cout<<s<<endl;
        reverse(s.begin(),s.end());
        // cout<<s<<endl;
        int res = BintoInt(s);
        return res;
    }
};
