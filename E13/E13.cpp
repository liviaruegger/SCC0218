#include <iostream>

#define MAX_LEN 2000

using namespace std;

int memo[MAX_LEN][MAX_LEN];
string str1, str2;

int min_value(int a, int b, int c)
{
    return min(min(a, b), c);
}

int edit_distance(int i, int j)
{
    if (i == -1) return j;
    if (j == -1) return i;
    
    if (memo[i][j] != -1) return memo[i][j];

    int dist;
    if (str1[i] == str2[j])
    {
        dist = edit_distance(i - 1, j - 1);
    }
    else
    {
        dist = 1 + min_value(
            edit_distance(i - 1, j - 1),    // REPLACE
            edit_distance(i, j - 1),        // INSERT
            edit_distance(i - 1, j)         // REMOVE
        );
    }
    
    memo[i][j] = dist;

    return dist;
}

void test_case()
{
    cin >> str1 >> str2;

    int n = str1.length();
    int m = str2.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            memo[i][j] = -1;        
    }

    edit_distance(n - 1, m - 1);

    cout << memo[n - 1][m - 1] + 1 << endl; 
}

int main()
{
    int n_test_cases;
    cin >> n_test_cases;

    for (int i = 0; i < n_test_cases; i++) test_case();
    
    return 0;
}