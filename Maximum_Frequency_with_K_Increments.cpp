class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());

            int n = arr.size();
            vector<long long> prefix(n + 1, 0);

            for (int i = 0; i < n; ++i) {
                prefix[i + 1] = prefix[i] + arr[i];
            }

            int res = 1;

            for (int right = 0; right < n; ++right) {
                int low = 0;
                int high = right;

                while (low < high) {
                    int mid = low + (high - low) / 2;
                    long long sum = prefix[right + 1] - prefix[mid];
                    long long required = 1LL * arr[right] * (right - mid + 1) - sum;

                    if (required <= k) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }

                res = max(res, right - low + 1);
            }

            return res;
    }
};
