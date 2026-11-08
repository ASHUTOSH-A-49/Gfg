class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        // code here
            if (s1 > s2)
                swap(s1, s2);

            int low = 0;
            int high = n;
            int minTime = s2 * n;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int time1 = mid * s1;
                int time2 = (n - mid) * s2;
                minTime = min(minTime, max(time1, time2));
                if (time1 <= time2)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            return minTime;
        
    }
};
