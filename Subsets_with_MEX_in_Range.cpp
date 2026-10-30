class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        const long long M = 1000000007;
            int n = arr.size();
            unordered_map<int, int> mp;
            for (int num : arr)
            {
                mp[num]++;
            }
            vector<long long> power(n + 1, 1);
            for (int i = 1; i <= n; i++)
            {
                power[i] = (power[i - 1] * 2) % M;
            }

            long long res = 0;
            long long cur = 1;
            int seen = 0;
            for (int i = 0; i < l; i++)
            {
                int freq = mp[i];
                if (freq == 0)
                {
                    return 0;
                }
                seen += freq;
                cur = (cur * (power[freq] - 1 + M)) % M;
            }
            for (int i = l; i <= r; i++)
            {
                int freq = mp[i];

                long long here = (cur * power[n - seen - freq]) % M;
                res = (res + here) % M;
                if (freq == 0)
                {
                    return res;
                }
                seen += freq;
                cur = (cur * (power[freq] - 1 + M)) % M;
            }

            return (int)res;
    }
};
