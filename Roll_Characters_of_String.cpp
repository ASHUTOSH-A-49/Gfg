class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n=s.size();
        vector<int>ip(n),diff(n+1,0);
        for(int i=0;i<n;i++){
            ip[i] = s[i]-'a';
        }
        for(int i:roll){
            diff[0]++;
            diff[i]--;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            ip[i]+=sum;
            s[i]= 'a'+ (ip[i]%26);
        }
        return s;

    }
};
