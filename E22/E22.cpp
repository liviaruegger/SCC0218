#include <iostream>

using namespace std;

int main()
{
    int n_test_cases;
    cin >> n_test_cases;

    for (int t = 0; t < n_test_cases; t++)
    {
        int n_piles;
        cin >> n_piles;

        int piles[n_piles];
        for (int i = 0; i < n_piles; i++)
            cin >> piles[i];

        int X = 0;
        for (int i = 0; i < n_piles; i++)
            X ^= piles[i];

        // X has to be != 0 for the first player to win
        // solution: if X == 0, take 1 stone; else, take 0
        
        cout << (X == 0 ? 1 : 0) << endl;
    }

    return 0;
}