#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define all(c) c.begin(), c.end()
#define ll long long
using namespace std;
ll MAX = 100000000;
int smoke[100][100];
int csum[100][100];

void compute(int i, int j)
{
    smoke[i][j] = MAX;
    for(int k=i;k<j;k++)
        smoke[i][j] = min(smoke[i][j], smoke[i][k] + smoke[k+1][j] + csum[i][k]*csum[k+1][j]);
}

int main()
{
    int n, i, j, k, l;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            cin>>csum[i][i];
            smoke[i][i] = 0;
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                csum[i][j] = (csum[i][j-1]+csum[j][j])%100;
        }
        for(i=1;i<n;i++)
            smoke[i-1][i] = csum[i-1][i-1]*csum[i][i];

        for(i=2;i<n;i++)
        {
            for(j=i;j<n;j++)
                compute(j-i, j);
        }
        cout<<smoke[0][n-1]<<endl;
    }
    return 0;
}
