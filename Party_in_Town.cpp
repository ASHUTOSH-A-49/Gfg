class Solution {
  public:
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
               if (n <= 1) return 0;

               // --- FIRST BFS PASS ---
               vector<int> d1(n, 0);
               vector<int> vis1(n, 0);
               queue<int> q;

               q.push(0);
               vis1[0] = 1;

               int furthest_node = 0;
               int max_d1 = 0; // Explicitly track the maximum distance

               while (!q.empty()) {
                   int idx = q.front();
                   q.pop();

                   // FIX: Explicitly find the node at the absolute maximum distance
                   if (d1[idx] > max_d1) {
                       max_d1 = d1[idx];
                       furthest_node = idx;
                   }

                   for (int i : adj[idx]) {
                       if (!vis1[i - 1]) {
                           vis1[i - 1] = 1;
                           d1[i - 1] = d1[idx] + 1;
                           q.push(i - 1);
                       }
                   }
               }

               // --- SECOND BFS PASS ---
               vector<int> d2(n, 0);
               vector<int> vis2(n, 0);

               q.push(furthest_node);
               vis2[furthest_node] = 1;
               int diameter = 0;

               while (!q.empty()) {
                   int idx = q.front();
                   q.pop();

                   // FIX: Explicitly update the absolute largest diameter found
                   if (d2[idx] > diameter) {
                       diameter = d2[idx];
                   }

                   for (int i : adj[idx]) {
                       if (!vis2[i - 1]) {
                           vis2[i - 1] = 1;
                           d2[i - 1] = d2[idx] + 1;
                           q.push(i - 1);
                       }
                   }
               }

               return (diameter + 1) / 2;
    }
};
