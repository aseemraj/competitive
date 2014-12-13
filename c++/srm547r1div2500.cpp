#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define init(a, b) memset(a, b, sizeof(a))
using namespace std;
int gcd(int x, int y)
{
    int c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
bool relp(int x, int y)
{
    return gcd(x, y)==1;
}
int main()
{
    int n;
    cin>>n;
    int S[n];
    loop(i, 0, n)
        cin>>S[n];
    bool mat[70][70];
    loop(i, 0, n)
        loop(j, 0, n)
            mat[i][j] = relp(S[i], S[j]);
    return 0;
}
