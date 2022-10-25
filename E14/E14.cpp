#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> row_t;
typedef vector<row_t> matrix_t;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    matrix_t dist;
    for (int i = 0; i < n; i++)
    {
        row_t row(n, 1e18);
        row[i] = 0;
        dist.push_back(row);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, len;
        cin >> a >> b >> len;

        dist[a - 1][b - 1] = len;
        dist[b - 1][a - 1] = len;
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        long long query = dist[a - 1][b - 1];
        long long output = (query == 1e18) ? -1 : query;

        cout << output << endl;
    }
    
    return 0;
}