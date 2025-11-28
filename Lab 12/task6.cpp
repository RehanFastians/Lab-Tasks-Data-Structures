#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<pair<int, int>> adj[nodes + 1];
    f(i, 0, edges)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    function<int(int, int)> shortestPath = [&](int start, int end) -> int
    {
        int dp[nodes + 1];
        f(i, 1, nodes + 1) dp[i] = -1000;
        priority_queue<pair<int, int>> pq;
        pq.push({0, start});
        while (!pq.empty())
        {
            auto [d1, u] = pq.top();
            pq.pop();
            for (auto &[d2, v] : adj[u])
            {
                if (d1 - d2 > dp[v])
                {
                    dp[v] = d1 - d2;
                    pq.push({dp[v], v});
                }
            }
        }
        return -dp[end];
    };

    cout << shortestPath(1, 2) << endl;
    cout << shortestPath(1, 4) << endl;
    return 0;
}