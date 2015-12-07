#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "w", stdout);
    for(int a = 0; a < 1024; a++)
    {
        bitset<32> x(a);
        for(int i = 9; i >= 0; i--)
            cout<<x[i];
        cout<<"\n";
    }
}
