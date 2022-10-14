#include <iostream>

#define MAX_N 2000
#define MAX_M 2000

using namespace std;

int n, m;
int values[26];
string str1, str2;

int memo[MAX_N][MAX_M];

int most_expensive_subseq(int i, int j)
{
    if (i >= n || j >= m) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    int current_value;
    if (str1[i] == str2[j])
        current_value = values[str1[i] - 'a'] + most_expensive_subseq(i + 1, j + 1);
    else
        current_value = max(most_expensive_subseq(i, j + 1), most_expensive_subseq(i + 1, j));

    memo[i][j] = current_value;

    return current_value;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < 26; i++)
        cin >> values[i];
    cin >> str1 >> str2;

    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_M; j++)
            memo[i][j] = -1;

    cout << most_expensive_subseq(0, 0);

    return 0;
}