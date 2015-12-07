/*
Author: aseemraj
Problem: hackb
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool mark[1005][1005][2];
int gridColouring(vector < string > grid)
{
    int n = grid.size();
    int m = grid[0].length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mark[i][j][0] == 1 && mark[i][j][1] == 0)
                continue;
            if(grid[i][j] == '.')
                continue;

            if(grid[i][j] == 'R')
            {
                for(int k = j; k < m && (grid[i][k] == 'R' || grid[i][j] == 'G'); k++)
                {
                    mark[i][k][0] = true;
                }
                ans++;
            }
        }
    }
}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin>>t;
    	v.push_back(t);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++)
    {
    	cout<<v[i]<<endl;
    }
    return 0;
}