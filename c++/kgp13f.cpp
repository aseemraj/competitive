#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, ((a % b) + b) % b);
}

int main()
{
    int n;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int area, i, b;
    cin>>n;
    for (int it = 1; it <= n; it++) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        area = abs((x1 - x3) * (y2 - y4) - (x2 - x4) * (y1 - y3));
        b = gcd(abs(x1 - x2), abs(y1 - y2)) + gcd(abs(x2 - x3), abs(y2 - y3)) + gcd(abs(x3 - x4), abs(y3 - y4)) + gcd(abs(x4 - x1), abs(y4 - y1));
        i = area + 1 - b;
        i /= 2;
        cout<<"Case "<<it<<": "<<i+b+1<<"\n";
    }

    return 0;

}
