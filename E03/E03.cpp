#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

float calculate_imbalance(float average_m, vector<vector<int>> chambers, int n)
{
    float imbalance = 0.0;

    for (int i = 0; i < n; i++)
    {
        int chamber_mass = 0.0;
        if (i < (int)chambers.size())
        {
            for (int j = 0; j < (int)chambers[i].size(); j++)
                chamber_mass += chambers[i][j];
        }
        
        imbalance += abs(chamber_mass - average_m);
    }

    return imbalance;   
}

void test_case(int x)
{
    int n_chambers, n_specimens;
    cin >> n_chambers >> n_specimens;

    if (feof(stdin)) return;

    deque<int> masses(n_specimens);
    for (int i = 0; i < n_specimens; i++)
        cin >> masses[i];
    sort(masses.begin(), masses.end());
    
    int total_mass = accumulate(masses.begin(), masses.end(), 0);
    float average_mass = (float)total_mass / (float)n_chambers;
    
    vector<vector<int>> chambers;

    int n;
    if (n_specimens < n_chambers) n = n_specimens;
    else if (n_specimens / n_chambers == 2) n = 0;
    else n = n_chambers - (n_specimens % n_chambers);

    for (int i = 0; i < n; i++)
    {
        vector<int> chamber;
        chamber.push_back(masses.back());
        masses.pop_back();

        chambers.push_back(chamber);
    }

    while (!masses.empty())
    {
        vector<int> chamber;
        chamber.push_back(masses.front());
        chamber.push_back(masses.back());
        masses.pop_front();
        masses.pop_back();

        chambers.push_back(chamber);
    }

    float imbalance = calculate_imbalance(average_mass, chambers, n_chambers);

    printf("Set #%d\n", x);
    for (int i = 0; i < n_chambers; i++)
    {
        printf(" %d:", i);
        if (i < (int)chambers.size())
        {
            for (int j = 0; j < (int)chambers[i].size(); j++)
                printf(" %d", chambers[i][j]);
        }
        printf("\n");
    }
    printf("IMBALANCE = %.5f\n\n", imbalance);
}

int main()
{
    int i = 1;
    do test_case(i++); while (!feof(stdin));
    
    return 0;
}