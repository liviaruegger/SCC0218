#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<pair<ll, ll>> factor(ll n)
{
    vector<pair<ll, ll>> factors;

    ll q = n;
    for (ll i = 2; i * i <= n; i++)
    {
        ll count = 0;
        while (q % i == 0)
        {
            q /= i;
            count++;
        }

        if (count) factors.push_back(make_pair(i, count));

        if (q == 1) break;
    }

    if (q != 1) factors.push_back(make_pair(q, 1));

    return factors;
}

bool divides_factorial(ll n, ll m)
{
    vector<pair<ll, ll>> m_factors = factor(m);

    ll i;
    for (auto p : m_factors)
    {
        i = p.first;
        while (p.second > 0)
        {
            if (i > n) return false;
            
            p.second -= n / i;
            i *= p.first;
        }
    }

    return true;
}

int main()
{
    ll n, m;
    while (cin >> n >> m)
    {
        if (m && divides_factorial(n, m)) printf("%lld divides %lld!\n", m, n);
        else printf("%lld does not divide %lld!\n", m, n);
    }

    return 0;
}