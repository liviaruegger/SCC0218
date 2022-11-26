#include <iostream>

using namespace std;

int main()
{
    int n_test_cases;
    cin >> n_test_cases;

    for (int t = 0; t < n_test_cases; t++)
    {
        string s;
        cin >> s;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (i % 2 == 0) // Alice's turn
            {
                if (s[i] != 'a') s[i] = 'a';
                else s[i] = 'b';
            }
            else // Bob's turn
            {
                if (s[i] != 'z') s[i] = 'z';
                else s[i] = 'y';
            }
        }

        cout << s << endl;
    }

    return 0;
}