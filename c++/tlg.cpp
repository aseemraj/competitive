#include<iostream>
int abs(int x, int y);
using namespace std;
int winner = 0;

int abs(int x, int y)
{
    if(x>=y)
        return x-y;
    else
        return y-x;
}

int main()
{
    int n, i, c = 0, d = 0, _max=0;
    cin>>n;
    int a[n][2], b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        c += a[i][0];
        d += a[i][1];
        b[i] = abs(c, d);
        if(b[i]>_max)
        {
            if(c>d)
                winner = 1;
            else
                winner = 2;
            _max = b[i];
        }
    }

    cout<<winner<<" "<<_max<<endl;
    return 0;
}
