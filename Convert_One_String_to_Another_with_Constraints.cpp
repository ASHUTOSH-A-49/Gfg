class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        int n1=s1.size(),n2=s2.size();
            int i=0,j=0;
            while(i<n1||j<n2){
                while(i<n1&&s1[i]=='#')i++;
                while(j<n2&&s2[j]=='#')j++;
                if((i==n1)!=(j==n2))return false;
                if(i==n1&&j==n2)break;
                if(s1[i]!=s2[j])return false;
                if(s1[i]=='A'&&i<j)return false;
                if(s1[i]=='B'&&i>j)return false;
                i++;j++;
            }
            return true;
    }
};
