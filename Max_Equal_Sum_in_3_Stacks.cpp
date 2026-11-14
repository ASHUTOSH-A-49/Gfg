class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        int i1 = 0,i2 = 0,i3 = 0;
        int n1 = s1.size(),n2 = s2.size(),n3 = s3.size();
        vector<int> suff1(n1),suff2(n2),suff3(n3);
        suff1[n1-1] = s1[n1-1];
        suff2[n2-1] = s2[n2-1];
        suff3[n3-1] = s3[n3-1];
        for(int i = n1-2;i>=0;i--){
            suff1[i]= s1[i]+suff1[i+1];
        }
        for(int i = n2-2;i>=0;i--){
            suff2[i]= s2[i]+suff2[i+1];
        }
        for(int i = n3-2;i>=0;i--){
            suff3[i]= s3[i]+suff3[i+1];
        }
        while(i1<n1 && i2<n2 && i3<n3){
            int t1 = suff1[i1],t2 = suff2[i2],t3 = suff3[i3];
            if(t1==t2 && t1==t3) return t1;
            else if(t1>=t2 && t1>=t3){
                i1++;
                continue;
            }else if(t2>=t1 && t2>=t3){
                i2++;
                continue;
            }else if(t3>=t1 && t3>=t2){
                i3++;
                continue;
            }
        }
        return 0;
    }
};
