#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> read_preferences(int n)
{
    vector<int> person(n + 1);
    vector<vector<int>> table_of_preferences;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cin >> person[j];
        person[0] = 0;
        table_of_preferences.push_back(person);
    }

    return table_of_preferences;
}

bool w_prefers_m_to_fiance(int w, int m, int fiance, vector<int> pref)
{
    for (int i = 1; i < (int)pref.size(); i++)
    {
        if (pref[i] == m) return true;
        if (pref[i] == fiance) return false;
    }

    return false;
}

void sort_and_print(vector<int> engagements)
{
    vector<int> engagements_by_man(engagements.size());
    for (int i = 0; i < (int)engagements.size(); i++)
        engagements_by_man[engagements[i] - 1] = i + 1;

    for (int i = 0; i < (int)engagements.size(); i++)
        cout << (i + 1) << " " << engagements_by_man[i] << endl;
}

void test_case()
{
    int n;
    cin >> n;

    vector<vector<int>> women = read_preferences(n);
    vector<vector<int>> men = read_preferences(n);

    vector<int> engagements(n, 0);
    vector<int> single_men;

    for (int i = 1; i < n + 1; i++) single_men.push_back(i);
    
    while (!single_men.empty())
    {
        int man = single_men.back();
        int propose_to = ++men[man - 1][0]; // index of the last proposition
        
        int woman = men[man - 1][propose_to];
        int fiance = engagements[woman - 1];

        if (fiance == 0) // woman is single
        {
            engagements[woman - 1] = man;
            single_men.pop_back();
        }
        else // woman is engaged 
        {
            if (w_prefers_m_to_fiance(woman, man, fiance, women[woman - 1]))
            {
                engagements[woman - 1] = man;
                single_men.pop_back();
                single_men.push_back(fiance);
            }
        }
    }

    sort_and_print(engagements);
}

int main()
{
    int n_test_cases;
    cin >> n_test_cases;

    for (int i = 0; i < n_test_cases; i++)
        test_case();

    return 0;
}