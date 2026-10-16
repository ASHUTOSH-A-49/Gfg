class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 0)
            return 0;
        vector<int> prefMax(n);
        vector<int> sufMin(n);
        prefMax[0] = arr[0];
    
        for (int i = 1; i < n; i++)
            prefMax[i] = max(prefMax[i - 1], arr[i]);
        sufMin[n - 1] = arr[n - 1];
    
        for (int i = n - 2; i >= 0; i--)
            sufMin[i] = min(sufMin[i + 1], arr[i]);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == prefMax[i] && arr[i] == sufMin[i])
                count++;
        }
    
        return count;
    }
};
