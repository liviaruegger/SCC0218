#include <iostream>

#define DIV 131071

using namespace std;

int main()
{
    char bit;
    while (cin >> bit)
    {
        int remainder = 0;
        while (bit != '#')
        {
            if (bit == '1') remainder = (remainder * 2 + 1) % DIV;
            else if (bit == '0') remainder = (remainder * 2) % DIV;

            cin >> bit;
        }
        
        cout << (remainder % DIV == 0 ? "YES\n" : "NO\n");
    }

    return 0;
}