#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, x;
    cin>>n>>x;
    pair<int, int> dur[n];
    loop(i, 0, n)
        cin>>dur[i].first>>dur[i].second;
    int cur = 1, j = 0, time = 0;
    while(cur<=dur[n-1].second)
    {
        if(cur+x<=dur[j].first)
            cur+=x;
        else
        {
            time += dur[j].second - cur + 1;
            cur = dur[j].second + 1;
            j++;
        }
    }
    cout<<time<<endl;
    return 0;
}
