/*
Author: aseemraj
Problem: problemname
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int auxgrid[1005][1005], auxgrid2[1005][1005];
int gridColouring(vector < string > grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == 'B' || grid[i][j] == 'G') auxgrid[i][j] = 1;
            if (grid[i][j] == 'R' || grid[i][j] == 'G') auxgrid2[i][j] = 1;
        }
    }
    int solution = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        bool f = false;
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (auxgrid2[i][j])
            {
                if (!f) solution++;
                f = true;
            }
            else f = false;
        }
    }
    for (int j = 0; j < m; j++)
    {
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            if (auxgrid[i][j])
            {
                if (!f) solution++;
                f = true;
            }
            else f = false;
        }
    }
    return solution;
}

int main()
{
    int n;
    cin >> n;
    vector < string > inp;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        inp.push_back(str);
    }
    cout << gridColouring(inp) << '\n';
    return 0;
}
