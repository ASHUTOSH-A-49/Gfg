class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        if(k==n-1) return 0;
        int mind = INT_MAX;
        map<int,int> mp;
        for(int i:arr) mp[i]++;
        if(k==0){
            int low = mp.begin()->first,high = mp.rbegin()->first;
            return high-low;
        }
        int l = 0,r = 0;
        while(r<k-1){
            mp[arr[r]]--;
            if(mp[arr[r]]==0) mp.erase(arr[r]);
            r++;
        }
        
        while(r<n){
            mp[arr[r]]--;
            if(mp[arr[r]]==0) mp.erase(arr[r]);
            r++;
            
            int h = mp.rbegin()->first;
            int low = mp.begin()->first;
            mind = min(mind,h-low);
            
            mp[arr[l]]++;
            l++;
            
            
        }
        return mind;
        
    }
};
