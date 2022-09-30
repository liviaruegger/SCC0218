#include <iostream>

#define MAX_N 100000

using namespace std;

int mountains[MAX_N], opt[MAX_N];

int cost(int i, int j)
{
    return abs(mountains[i] - mountains[j]);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> mountains[i];

    opt[0] = 0;
    opt[1] = cost(0, 1);

    for (int i = 2; i < n; i++)
        opt[i] = min(opt[i - 1] + cost(i - 1, i), opt[i - 2] + cost(i - 2, i));
    
    cout << opt[n - 1] << endl;

    return 0;
}