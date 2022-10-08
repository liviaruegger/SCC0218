#include <iostream>
#include <vector>

#define MAX_N 300

using namespace std;

int main()
{
    int n, p1, p7, p30;
    cin >> n >> p1 >> p7 >> p30;
    
    bool trips[MAX_N + 1] = {false};
    int min_cost[MAX_N + 1];

    int day;
    for (int i = 0; i < n; i++)
    {
        cin >> day;
        trips[day] = true;
    }

    min_cost[0] = 0;
    for (int i = 1; i <= day; i++)
    {
        if (!trips[i])
        {
            min_cost[i] = min_cost[i - 1];
        }
        else
        {
            min_cost[i] = min_cost[i - 1] + p1;
            if (day >= 7) min_cost[i] = min(min_cost[i], min_cost[i - 7] + p7);
            if (day >= 30) min_cost[i] = min(min_cost[i], min_cost[i - 30] + p30);
        }
    }

    cout << min_cost[day];
    
    return 0;
}