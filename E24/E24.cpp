#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    long long x;
    long long y;
};

long long cross_product(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

long long area_times_2(Point vertices[], int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += cross_product(vertices[i], vertices[(i + 1) % n]);
    
    return abs(sum);
}

int main()
{
    int n_vertices;
    cin >> n_vertices;

    Point vertices[n_vertices];
    for (int i = 0; i < n_vertices; i++)
    {
        cin >> vertices[i].x;
        cin >> vertices[i].y;
    }

    cout << area_times_2(vertices, n_vertices) << endl;

    return 0;
}