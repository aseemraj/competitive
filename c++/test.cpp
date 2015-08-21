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
const int MAX = 100;
const int MX = 1000000000;
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n<=1)return n;
    int i = 0, j = 0;
    while(i<n)
    {
        nums[i] = nums[j];
        j = i+1;
        while(j<n && nums[j]==nums[i])j++;
        if(j==n)break;
        i++;
    }
    int k = 0;
    while(k<n-1 && nums[k]<nums[k+1])k++;
    nums.resize(k+1);
    return k+1;
}
int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    removeDuplicates(v);
    loop(i, 0, v.size())cout<<v[i]<<' ';
    return 0;
}
