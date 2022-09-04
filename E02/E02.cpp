#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<double,double> coverage_t;

coverage_t calculate_sprinkler_coverage(int h, int center, int radius)
{
    double a = (double)(h / 2);
    if (radius < a) return make_pair((double)center, (double)center);

    // Pythagorean theorem
    double b_square = pow(radius, 2) - pow(a, 2); // b^2 = radius^2 - a^2
    double b = sqrt(b_square);

    coverage_t coverage(center - b, center + b);

    return coverage;
}

int min_n_of_intervals(coverage_t interval, vector<coverage_t> coverage)
{
    sort(coverage.begin(), coverage.end());

    if (coverage[0].first >= interval.first) return -1;

    double start = interval.first;
    double end = coverage[0].second;

    int count = 1;
    for (int i = 1; i < (int)coverage.size(); i++)
    {
        if (coverage[i].first > end)
        {
            break;
        }
        else if (coverage[i].first <= start) 
        {
            end = max(coverage[i].second, end);
            if (end >= interval.second) break;
        }
        else if (coverage[i].second >= end)
        {
            start = end;
            end = coverage[i].second;
            count++;

            if (end >= interval.second) break;
        }
    }

    if (end < interval.second) return -1;
    return count;
}

void test_case()
{
    int n, l, w;
    cin >> n >> l >> w;

    if (feof(stdin)) return;

    vector<coverage_t> sprinklers;

    int c, r;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> r;
        sprinklers.push_back(calculate_sprinkler_coverage(w, c, r));
    } 

    cout << min_n_of_intervals(make_pair(0.0, (double)l), sprinklers) << endl;
}

int main()
{
    do test_case(); while (!feof(stdin));
    
    return 0;
}