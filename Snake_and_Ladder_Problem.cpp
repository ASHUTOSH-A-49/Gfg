class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        vector<int> moves(n * n + 1, -1);
        vector<bool> vis(n * n + 1, false);
        for (int i = 0; i < (int)lad.size(); i += 2)
        {
            moves[lad[i]] = lad[i + 1];
        }
        for (int i = 0; i < (int)sn.size(); i += 2)
        {
            moves[sn[i]] = sn[i + 1];
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;

        pair<int, int> cur;

        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            int pos = cur.first;
            int dist = cur.second;
            if (pos == n * n)
            {
                return dist;
            }
            for (int nxt = pos + 1; nxt <= pos + 6 && nxt <= n * n; nxt++)
            {
                if (!vis[nxt])
                {
                    vis[nxt] = true;

                    int dest = (moves[nxt] == -1) ? nxt : moves[nxt];
                    q.push({dest, dist + 1});
                }
            }
        }

        return -1;int m = n * n;
    }
};
