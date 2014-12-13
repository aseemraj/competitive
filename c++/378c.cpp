#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
char cell[600][600];
int n, m, k;
int visited[600][600];
void dfs(int a, int b, int& rem)
{
    visited[a][b] = 1;
    if(a-1 >= 0 && cell[a-1][b] == '.' && visited[a-1][b] == 0) dfs(a-1, b, rem);
    if(a+1 < n && cell[a+1][b] == '.' && visited[a+1][b] == 0) dfs(a+1, b, rem);
    if(b-1 >= 0 && cell[a][b-1] == '.' && visited[a][b-1] == 0) dfs(a, b-1, rem);
    if(b+1 < m && cell[a][b+1] == '.' && visited[a][b+1] == 0) dfs(a, b+1, rem);
    if (rem>0)
    {
        rem--;
        cell[a][b] = 'X';
    }
}
int main()
{
    cin>>n>>m>>k;
    loop(i, 0, n)
        scanf("%s", cell[i]);
    memset(visited, 0, sizeof visited);
    bool flag = true;
    loop(i, 0, n&&flag)
    {
        loop(j, 0, m)
        {
            if(cell[i][j]=='.')
            {
                dfs(i, j, k);
                flag = false;
                break;
            }
        }
    }
    loop(i, 0, n)
        cout<<cell[i]<<endl;
    return 0;
}
