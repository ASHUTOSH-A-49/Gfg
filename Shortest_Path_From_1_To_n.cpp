class Solution {
  public:
    int minimumStep(int n) {
        // code here
        if(n==1) return 0;
        int d=0;
        while(n>1){
            if(n%3==0){
                n/=3;
                d++;
            }else{
                n-=1;
                d++;
            }
        }
        return d;
        
        
    }
};
