class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
    int totalHeight = 0;

    for (int i = 0; i < n; i++)
        totalHeight += arr[i];

    if (n <= 2)
        return totalHeight - 1;

    vector<int> left(n), right(n);

    left[0] = 1;
    for (int i = 1; i < n; i++)
        left[i] = min(left[i - 1] + 1, arr[i]);

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        right[i] = min(right[i + 1] + 1, arr[i]);

    int minCost = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        int peakHeight = min(left[i], right[i]);
        int pyramidSum = peakHeight * peakHeight;
        minCost = min(minCost, totalHeight - pyramidSum);
    }

    return minCost;
    }
};
