class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i<n){
            while(i<n && s[i]=='x'){
                st.push(s[i]);
                i++;
            }
            while(i<n && s[i]=='y'){
                if(st.empty()) return false;
                st.pop();
                i++;
            }
            if(!st.empty()) return false;
            
            
        }
        return true;
    }
};
