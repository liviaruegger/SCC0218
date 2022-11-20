#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (!a) return b;
    if (!b) return a;

    int temp;
    while (a % b != 0)
    {
        temp = a;
        a = b;
        b = temp % b;
    }

    return b;
}

void test_case(int n)
{
    vector<int> nums;

    while (n)
    {
        nums.push_back(n);
        cin >> n;
    }

    int ans = abs(nums[1] - nums[0]);
    for (int i = 2; i < (int)nums.size(); i++)
        ans = gcd(ans, abs(nums[i] - nums[i - 1]));
        
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        test_case(n);
        cin >> n;
    }

    return 0;
}