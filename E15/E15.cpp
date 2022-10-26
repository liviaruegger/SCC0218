#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll INF = 1e18;

struct Edge
{
    int u, v;
    ll w;
};

bool bellman_ford(vector<Edge> edges, int n)
{
    vector<ll> d(n, INF);
    d[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (Edge e : edges)
        {   
            if (d[e.u] < INF && d[e.v] > d[e.u] + e.w)
                d[e.v] = max(-INF, d[e.u] + e.w);
        }
    }

    vector<bool> negative(n, false);

    for (int i = 0; i < n; i++)
    {
        for (Edge e : edges)
        {
            if (d[e.u] == INF)
                continue;

            if (d[e.v] > d[e.u] + e.w)
            {
                d[e.v] = d[e.u] + e.w;
                negative[e.v] = true;
            }

            if (negative[e.u])
                negative[e.v] = true;
        }
    }

    return negative[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge e = {a - 1, b - 1, c};
        edges.push_back(e);
    }

    cout << (bellman_ford(edges, n) ? "YES" : "NO") << endl;
    
    return 0;
}