#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int steps[100005] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    sz = s.size();
    int minsteps[10];
    loop(i, 0, 10) minsteps[i] = 100005;
    loop(i, 0, sz) steps[i] = 100005;

    minsteps[s[0]-48] = 0;
    steps[0] = 0;

    loop(i, 1, sz)
    {
        steps[i] = min(minsteps[s[i]-48]+1, steps[i-1]+1);
        if(steps[i]<minsteps[s[i]-48]) minsteps[s[i]-48] = steps[i];
    }
    rloop(i, 0, sz-1)
    {
        steps[i] = min(steps[i], min(minsteps[s[i]-48]+1, steps[i+1]+1));
        if(steps[i]<minsteps[s[i]-48]) minsteps[s[i]-48] = steps[i];
    }
    loop(i, 1, sz)
    {
        steps[i] = min(steps[i], min(minsteps[s[i]-48]+1, steps[i-1]+1));
        if(steps[i]<minsteps[s[i]-48]) minsteps[s[i]-48] = steps[i];
    }
    cout<<steps[sz-1]<<endl;
    return 0;
}
