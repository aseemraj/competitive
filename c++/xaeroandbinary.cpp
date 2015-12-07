#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string a, b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    if(n != m)
        cout<<"-1\n";
    else
    {
        int ones[2] = {0}, dif = 0;
        for (int i = 0; i < n; ++i)
        {
            ones[0] += a[i]-48;
            ones[1] += b[i]-48;
            if(a[i] != b[i])
                dif++;
        }
        if(ones[0] != ones[1])
            cout<<"-1\n";
        else
        {
            cout<<dif/2<<"\n";
        }
    }
    return 0;
}