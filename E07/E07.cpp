#include <iostream>
#include <vector>

using namespace std;

int bin_search(int moment, vector<int> playlist)
{
    int i = 1;
    int j = playlist.size() - 1;
    while (i <= j)
    {
        int m = (j + i) / 2;
        
        if (moment == playlist[m]) return m;
        else if (moment > playlist[m]) i = m + 1;
        else j = m - 1;
    }

    return max(i, j);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> playlist(n + 1);
    playlist[0] = 0;

    int c, t;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> c >> t;
        playlist[i] = playlist[i - 1] + (c * t);
    }

    int moment;
    for (int i = 0; i < m; i++)
    {
        cin >> moment;
        cout << bin_search(moment, playlist) << endl;
    }

    return 0;
}