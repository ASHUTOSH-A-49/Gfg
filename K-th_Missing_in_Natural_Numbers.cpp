class Solution {
  public:
    int BSFind(vector<int> & arr,int i){
        int l = 0,h = arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid]<i){
                l = mid+1;
            }else if(arr[mid]>i){
                h = mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = 1;
        int cnt = 0;
        while(true){
            int idx = BSFind(arr,i);
            if(idx!=-1){
                if(idx==n-1){
                    int diff = k-cnt;
                    return i+diff;
                }
                i++;
                continue;
            }
            
            cnt++;
            if(cnt==k) return i;    
            i++;
        }
        return -1;
    }
};
