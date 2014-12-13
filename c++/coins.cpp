#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopl(i, a, b) for(long long i=a; i<b; i++)
#define init(a, b) memset(a, b, sizeof(a))
#define ll int long long
unsigned int dol[32][19];
using namespace std;
unsigned int dollars(unsigned int n, int i, int j)
{
    if(n<12)
        return n;
    if(dol[i][j]==0)
        dol[i][j] = dollars(n/2, i+1, j) + dollars(n/3, i, j+1) + dollars(n/4, i+2, j);
    return dol[i][j];
}
int main()
{
    unsigned int n;
    while((scanf("%u",&n))!=EOF)
    {
        init(dol, 0);
        cout<<dollars(n, 0, 0)<<endl;
    }
    return 0;
}
