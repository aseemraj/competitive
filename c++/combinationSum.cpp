/*
Author: aseemraj
Problem: 
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

class Solution {
public:
    int n;
    void solve(vector<int> &v, vector<vector<int> > &ans, vector<int> &cur, int idx, int t)
    {
        int i;
        for(i=idx; i<n; i++)
        {
            if(v[i] == t)
            {
                cur.push_back(t);
                ans.push_back(cur);
                cur.pop_back();
                break;
            }
            else if(v[i] < t)
            {
                cur.push_back(v[i]);
                solve(v, ans, cur, i, t-v[i]);
                cur.pop_back();
            }
            else break;
        }
    }

    vector<vector<int> > combinationSum(vector<int>& c, int t) {
        n = c.size();
        sort(c.begin(), c.end());
        vector<vector<int> > ans;
        vector<int> cur;
        solve(c, ans, cur, 0, t);
        return ans;
    }
};

int main()
{
    Solution x;
    vector<int> v(4,0);
    v[0] = 2;
    v[1] = 3;
    v[2] = 6;
    v[3] = 7;
    vector<vector<int> > k = x.combinationSum(v, 7);
    for(int i=0; i<k.size(); i++)
    {
        for(int j = 0; j<k[i].size(); j++)
            cout<<k[i][j]<<' ';
        cout<<"\n";
    }
    return 0;
}