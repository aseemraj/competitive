#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll unsigned long long int
using namespace std;
int n, m, k;
bool danger[1002][1002]={{false}};
int maxa[1002][1002] = {{0}};
int main()
{
    cin>>n>>m>>k;
    int i, j, x, y, s;
    loop(i, 0, k)
    {
        cin>>x>>y;
        danger[x][y] = true;
    }
    loop(i, 1, n+1)
    {
        maxa[i][i] = 0;
        s = 0;
        loop(j, 1, m+1)
        {
            if(!danger[i][j])
                s++;
            else
            {
                maxa[i][i] = max(maxa[i][i], s);
                s = 0;
            }
        }
    }

    cin>>q;
    while(q--)
    {

    }
    return 0;
}
