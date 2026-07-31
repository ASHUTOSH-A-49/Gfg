
class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int> arr(n+1,0);
        for(int i = 0;i<a.size();i++){
            arr[a[i]]+=k[i];
            arr[b[i]+1]-=k[i];
        }
        long long sum = 0,maxval = 0;
        for(int i:arr){
            sum+=i;
            maxval = max(maxval,sum);
        }
        
        return maxval;
        
    }
};
