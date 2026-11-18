class Solution {
  public:
  int getXor(int n){
      int div4 = n%4;
        if(div4==0) return n;
        if(div4==1) return 1;
        if(div4==2) return n+1;
        return 0;
  }
    int findXOR(int l, int r) {
        // code here
        return getXor(r) ^ getXor(l-1);
    }
};
