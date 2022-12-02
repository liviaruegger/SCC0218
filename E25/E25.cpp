#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

#define llu unsigned long long int

using namespace std;

struct Point
{
    llu x;
    llu y;
};

Point p0;
vector<Point> hull;

llu square_of_distance(Point a, Point b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int orientation(Point p, Point q, Point r)
{
    long long val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));

    if (val == 0) return 0; // são colineares
    return (val > 0) ? 1 : 2; // horário (1) ou anti-horário (2)
}

void swap(Point &a, Point &b)
{
    Point temp = a;
    a = b;
    b = temp;
}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);

    if (o == 0)
        return (square_of_distance(p0, *p2) >= square_of_distance(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

Point next_to_top(stack<Point> &s)
{
    Point p = s.top();
    s.pop();

    Point res = s.top();
    s.push(p);

    return res;
}

void convex_hull_graham_scan(Point points[], int n)
{
    llu ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        llu y = points[i].y;

        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);

    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    if (m < 3) return; // não existe

    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (s.size() > 1 && orientation(next_to_top(s), s.top(), points[i]) != 2)
            s.pop();
            
        s.push(points[i]);
    }

    while (!s.empty())
    {
        hull.push_back(s.top());
        s.pop();
    }
}

int main()
{
    int n_sheeps;
    cin >> n_sheeps;

    Point sheeps[n_sheeps];
    for (int i = 0; i < n_sheeps; i++)
    {
        cin >> sheeps[i].x;
        cin >> sheeps[i].y;
    }

    convex_hull_graham_scan(sheeps, n_sheeps);

    double perimeter = 0.0;
    for (int i = 0; i < (int)hull.size(); i++)
        perimeter += sqrt(square_of_distance(hull[i], hull[(i + 1) % hull.size()]));

    printf("%.6lf\n", perimeter);

    return 0;
}