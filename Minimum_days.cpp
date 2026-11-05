class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
    int n = s.size();
    unordered_set<int> st;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            st.insert(i);
    }
    if (st.empty())
        return 0;
    for (int day = 0; day < n; day++)
    {
        int in = p[day];
        if (in - 1 >= 0)
            st.erase(in - 1);
        if (in < n - 1)
            st.erase(in);
        s[in] = '?';
        if (st.empty())
            return day + 1;
    }

    return n;
    }
};
