class Solution {
  public:
    bool isSubsequence(const string &word, const vector<vector<int>> &pos)
    {

        int prevIndex = -1;

        for (char ch : word)
        {
            const vector<int> &indices = pos[ch - 'a'];
            auto it = upper_bound(indices.begin(), indices.end(), prevIndex);
            if (it == indices.end())
            {
                return false;
            }
            prevIndex = *it;
        }

        return true;
    }

    string findLongestWord(string &s, vector<string> &d)
    {
        vector<vector<int>> pos(26);

        for (int i = 0; i < s.size(); i++)
        {
            pos[s[i] - 'a'].push_back(i);
        }

        string res = "";

        for (const string &word : d)
        {
            if (word.size() < res.size())
            {
                continue;
            }
            if (isSubsequence(word, pos))
            {
                if (word.size() > res.size() || (word.size() == res.size() && word < res))
                {
                    res = word;
                }
            }
        }

        return res;
    }

};
