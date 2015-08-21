/*
Author: aseemraj
Problem: rearrstr
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

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int sz = s.size();
        if(sz==1)
        {
            cout<<s<<"\n";
            continue;
        }

        VP balloon;
        loop(i, 0, 26)balloon.PB(PI(0, i));
        loop(i, 0, sz)balloon[s[i]-97].F++;

        sort(ALL(balloon), greater<PI>());
        
        string arr = "";
        arr += balloon[0].S+97;
        balloon[0].F--;
        int j = 0, f;
        while(j<sz)
        {
            f = 0;
            loop(i, 0, 26)
            {
                if(balloon[i].F==0)continue;
                if(arr[j] != balloon[i].S+97)
                {
                    arr += balloon[i].S+97;
                    balloon[i].F--;
                    sort(ALL(balloon), greater<PI>());
                    j++;
                    f = 1;
                    break;
                }
            }
            if(!f)break;
        }
        f = 1;
        loop(i, 1, sz)if(arr[i]==arr[i-1]){f=0;break;}
        if(!f || arr.size() != sz)cout<<"-1\n";
        else cout<<arr<<"\n";
    }
    return 0;
}
