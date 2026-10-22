class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        
        int n = s.size();
        if(n==1) return 0;
        int l = 0,r = n-1;
        bool pal = true;
        while(l<=r){
            if(s[l]=='?' || s[r]=='?'){
                l++;r--;
            }else{
                if(s[l]==s[r]){
                    l++;r--;
                }else{
                    pal = false;
                    break;
                }
            }
        }
        if(!pal) return -1;
        l = 0; r = n-1;
        while(l<=r){
            if(s[l]=='?' || s[r]=='?'){
                if(s[l]=='?' && s[r]=='?'){
                }else if(s[l]=='?') {
                    s[l] = s[r];
                }else {
                    s[r] = s[l];
                }
            }
            l++; r--; 
        }
        char last_known = '?';
        for(int i = 0; i <= (n - 1) / 2; i++) {
            if(s[i] != '?') {
                last_known = s[i];
                break;
            }
        }
        if(last_known == '?') return 0;
        for(int i = 0; i <= (n - 1) / 2; i++) {
            if(s[i] == '?') {
                s[i] = last_known;
            } else {
                last_known = s[i];
            }
        }
        for(int i = 0; i <= (n - 1) / 2; i++) {
            s[n - 1 - i] = s[i];
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans += abs(s[i] - s[i+1]);
        }

        return ans;
    }
};
