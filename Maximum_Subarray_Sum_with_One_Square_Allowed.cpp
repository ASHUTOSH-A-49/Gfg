class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
            int res = 0;
            int n = arr.size();
            vector<int> left(n + 1, 0);
            vector<int> right(n + 2, 0);

            int maxEnd = 0;
            for (int i = 0; i < n; i++)
            {
                maxEnd += arr[i];
                if (maxEnd < 0)
                    maxEnd = 0;

                left[i + 1] = maxEnd;
            }
            maxEnd = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                maxEnd += arr[i];
                if (maxEnd < 0)
                    maxEnd = 0;

                right[i + 1] = maxEnd;
            }
            for (int i = 1; i <= n; i++)
            {
                res = max(res, arr[i - 1] * arr[i - 1] + left[i - 1] + right[i + 1]);
            }

            return res;
    }
};
