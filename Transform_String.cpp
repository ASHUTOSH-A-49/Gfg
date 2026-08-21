class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        if (s1.length() != s2.length()) {
            return -1;
        }
        unordered_map<char, int> m;
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            if (m.count(s1[i])) 
                m[s1[i]]++;
            else
                m[s1[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (m.count(s2[i]))
                m[s2[i]]--;
        }
        for (auto it : m) {
            if (it.second != 0) 
                return -1;
        }
        int i = n - 1, j = n - 1;
        int res = 0;
        while (i >= 0 && j >= 0) {
            while (i >= 0 && s1[i] != s2[j]) {
                res++;
                i--;
            }
            i--;
            j--;
        }

        return res;
    }
};
