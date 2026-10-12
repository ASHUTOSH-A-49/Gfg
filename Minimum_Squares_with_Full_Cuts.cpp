class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        if(n==0 || m==0) return 0;
        int ans = 0;
        if(n>m){
            int mul = n/m;
            n-=m*mul;
            ans+=mul + minSquares(n,m);
        }else{
            int mul = m/n;
            m-=n*mul;
            ans+=mul + minSquares(n,m); 
        }
        return ans;
    }
};
