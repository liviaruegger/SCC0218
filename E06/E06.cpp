#include <iostream>
#include <algorithm>

#define MAX_LEN 200000
#define ll long long

using namespace std;

ll merge_and_count_inversions(int *arr, int *aux, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = left;

    ll count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
            count += (mid - i);
        }
    }

    while (i <= mid - 1)
        aux[k++] = arr[i++];

    while (j <= right)
        aux[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = aux[i];

    return count;
}

ll mergesort_and_count_inversions(int *arr, int *aux, int left, int right)
{
    ll count = 0;

    if (right > left)
    {
        int mid = (left + right) / 2;

        count += mergesort_and_count_inversions(arr, aux, left, mid);
        count += mergesort_and_count_inversions(arr, aux, mid + 1, right);
        count += merge_and_count_inversions(arr, aux, left, mid + 1, right);
    }

    return count;
}

void test_case()
{
    int array_len;
    cin >> array_len;

    int array[MAX_LEN];;
    for (int i = 0; i < array_len; i++)
        cin >> array[i];

    int aux[array_len];
    ll res = mergesort_and_count_inversions(array, aux, 0, array_len - 1);
    
    int curr = 1;
    for (int i = 1; i < array_len; i++)
    {
        if (array[i] != array[i - 1])
        {
            res += (curr * (curr - 1)) / 2;
            curr = 1;
        }
        else
        {
            curr++;
        }
    }
    res += (curr * (curr - 1)) / 2;

    cout << res << endl;
}

int main()
{
    int n_tests;
    cin >> n_tests;

    for (int i = 0; i < n_tests; i++)
        test_case();
    
    return 0;
}