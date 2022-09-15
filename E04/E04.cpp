#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> row_t;
typedef vector<row_t> matrix_t;

int n, m, k;
bool found_word;

matrix_t grid;
string word;

void read_grid()
{
    row_t row(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%c", &row[j]);
        grid.push_back(row);
        cin.ignore(5, '\n');
    }
}

matrix_t copy_grid(matrix_t grid)
{
    matrix_t copy;
    row_t row(m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            row[j] = grid[i][j];
        copy.push_back(row);
    }

    return copy;
}

void _search_grid(matrix_t copy, int index, int i, int j)
{
    char c;
    if (index < k && i >= 0 && i < n && j >= 0 && j < m) c = word[index];
    else return;

    if (c == '.') return;

    if (copy[i][j] == c)
    {
        if (index == k - 1)
        {
            found_word = true;
            return;
        }

        copy[i][j] = '.';

        _search_grid(copy_grid(copy), index + 1, i - 1, j);
        _search_grid(copy_grid(copy), index + 1, i + 1, j);
        _search_grid(copy_grid(copy), index + 1, i, j - 1);
        _search_grid(copy_grid(copy), index + 1, i, j + 1);
    }
}

void search_grid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            _search_grid(copy_grid(grid), 0, i, j);
    }
}

int main()
{
    cin >> n >> m;
    cin.ignore(5, '\n');
    read_grid();
    cin >> k >> word;

    found_word = false;
    search_grid();

    if (found_word) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}