class Solution {
  public:
    int minSubarraySum(vector<int> &nums) {
        // code here
        int n = nums.size();
                int mini = 1e8;
                int sum = 0;
                for(int i = 0;i<n;i++){
                    sum+=nums[i];
                    mini = min(mini,sum);
                    if(sum>0){
                        sum = 0;
                    }
                }
                return mini;
    }
};
