#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int seq[n];
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1;
    
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (seq[i] > seq[j] && (lis[j] + 1) > lis[i])
                lis[i] = lis[j] + 1;
        }
    }

    cout << *max_element(lis, lis + n); 

    return 0;
}