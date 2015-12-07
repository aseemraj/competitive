#include <bits/stdc++.h>
using namespace std;

int ft(int n)
{
    int c = 0;
    for (int i = 1; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            c += max(j+i, n) - min(j-i, 1) + 1;
        }
    }
    return c;
}

int main()
{
    int n;
    while(1)
    {
        cin>>n;
        cout<<ft(n)<<"\n";
    }
    return 0;
}