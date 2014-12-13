#include<iostream>
using namespace std;
int main()
{
    int n, i, j, fx=0, fy=0;
    cin>>n;
    long p[n][2], x, y;
    for(i=0;i<n;i++)
    {
        cin>>p[i][0]>>p[i][1];
    }
    for(i=0;i<n;i++)
    {
        x = p[i][0];
        y = p[i][1];
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(p[i][0] = p[j][0])
            {
                fx = 1;
                break;
            }
        }
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(p[i][1] = p[j][1])
            {
                fy = 1;
                break;
            }
        }
    }

    return 0;
}
