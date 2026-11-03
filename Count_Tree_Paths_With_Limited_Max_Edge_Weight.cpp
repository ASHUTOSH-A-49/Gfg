class Solution {
  public:
    int ans;
    int root(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = root(parent[x], parent);
    }
    void Union(int a, int b, vector<int> &parent, vector<int> &sz)
    {
        int ra = root(a, parent);
        int rb = root(b, parent);
        if (ra == rb)
            return;

        if (sz[ra] < sz[rb])
            swap(ra, rb);
        ans += sz[ra] * sz[rb];

        parent[rb] = ra;
        sz[ra] += sz[rb];
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int> &queries)
    {
        ans = 0;

        vector<int> parent(n + 1);
        vector<int> sz(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        vector<array<int, 3>> wt;

        for (auto &e : edges)
        {
            wt.push_back({e[2], e[0], e[1]});
        }

        sort(wt.begin(), wt.end());
        map<int, int> mp;

        int i = 0;

        while (i < (int)wt.size())
        {

            int weight = wt[i][0];

            while (i < (int)wt.size() && wt[i][0] == weight)
            {

                int u = wt[i][1];
                int v = wt[i][2];

                Union(u, v, parent, sz);

                i++;
            }
            mp[weight] = ans;
        }

        vector<int> res;
        res.reserve(queries.size());
        for (int x : queries)
        {
            auto it = mp.upper_bound(x);

            if (it == mp.begin())
            {
                res.push_back(0);
            }
            else
            {
                --it;
                res.push_back(it->second);
            }
        }

        return res;
    }
};
