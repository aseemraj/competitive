/*
Author: aseemraj
Problem: kol15c
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 100005;
const int SQN = 320;

int X[MAXN][SQN];
int arr[MAXN];
int par[SQN];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, u, a, b;
    cin>>n>>u;
    while(u--)
    {
        cin>>a>>b;
        if(a >= SQN)
            for(int i = b; i <= n; i += a)
                arr[i]++;
        else
            X[b][a]++;
    }

    for(int i = 1; i < SQN; i++)
    {
        for(int j = 0; j < i; j++)
            par[j] = 0;
        for(int k = 1; k <= n; k++)
        {
            par[k%i] += X[k][i];
            arr[k] += par[k%i];
        }
    }

    for(int i = 1; i <= n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
