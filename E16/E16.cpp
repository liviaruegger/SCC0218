#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;

int capacity[MAX_N][MAX_N];
int residual[MAX_N][MAX_N];
int parent[MAX_N];
int n_nodes;

bool bfs(int s, int t)
{
    queue<int> q;

    q.push(s);
    parent[s] = -1;

    bool visited[n_nodes];
    memset(visited, false, n_nodes);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n_nodes; ++v) // for each v adjacent to u
        {
            if (residual[u][v] > 0 && !visited[v])
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int edmonds_karp(int source, int sink)
{
    for (int i = 0; i < n_nodes; ++i)
        for (int j = 0; j < n_nodes; ++j)
            residual[i][j] = capacity[i][j];

    int u, v;
    int max_flow = 0;
    while (bfs(source, sink))
    {
        int bottleneck = INT32_MAX;
        
        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            bottleneck = min(bottleneck, residual[u][v]);
        }

        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            residual[u][v] -= bottleneck;
        }

        max_flow += bottleneck;
    }

    return max_flow;
}

void test_case(int network)
{
    int source, sink, n_connections;
    cin >> source >> sink >> n_connections;

    memset(capacity, 0, sizeof(capacity));

    for (int i = 0; i < n_connections; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        capacity[--u][--v] += w;
        capacity[v][u] += w;
    }

    int bandwidth = edmonds_karp(--source, --sink);

    printf("Network %d\nThe bandwidth is %d.\n", network, bandwidth);
}

int main()
{
    int network_count = 1;
    
    cin >> n_nodes;
    while (n_nodes)
    {
        test_case(network_count++);
        cin >> n_nodes;
        if (n_nodes) printf("\n");
    }

    return 0;
}