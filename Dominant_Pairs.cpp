class Solution {
  public:
  int BSans(vector<int> & arr,int i){
      int n = arr.size();
      int l = n/2,h = n-1,ansidx = -1;
      while(l<=h){
          int mid = l+(h-l)/2;
          if(arr[i]>=5*arr[mid]){
              l = mid+1;
              ansidx = mid;
          }else{
              h = mid-1;
          }
      }
      return ansidx;
  }
    int dominantPairs(vector<int> &arr) {
        // Code here
        int p = 0;
        int n = arr.size();
        if(n/2>0){
            sort(arr.begin(),arr.begin()+n/2-1);
            reverse(arr.begin(),arr.begin()+n/2-1);
            sort(arr.begin()+n/2,arr.end());
        }
        
        for(int i = 0;i<n/2;i++){
            int ansidx = BSans(arr,i);
            if(ansidx!=-1) p+=ansidx-n/2+1;
        }
        return p;
    }
};
