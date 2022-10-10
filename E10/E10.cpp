#include <iostream>
#include <string>
#include <vector>

#define MAX_H 1000
#define MAX_W 1000

#define MOD 1000000007

using namespace std;

vector<string> grid;
int memo[MAX_H][MAX_W];
int h, w;

void init()
{
    for (int i = 0; i < h; i++)
    {   
        string row;
        cin >> row;
        grid.push_back(row);
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            memo[i][j] = 0;
    }
}

int solve()
{
    memo[0][0] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                if (i != 0 && grid[i - 1][j] == '.')
                    memo[i][j] = memo[i - 1][j];
                if (j != 0 && grid[i][j - 1] == '.')
                    memo[i][j] = (memo[i][j] + memo[i][j - 1]) % MOD;    
            }
        }
    }

    return memo[h - 1][w - 1];
}

int main()
{
    cin >> h >> w;
    init();
    
    cout << solve() << endl;

    return 0;
}