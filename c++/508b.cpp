/*
Author: aseemraj
Problem: Codeforces 508 B
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int odd;
    bool f = false;
    string n;
    cin>>n;
    int sz = n.size();
    int ans = -1;
    odd = n[sz-1];
    loop(i, 2, sz+1)
    {
        if(n[sz-i]%2==0)
        {
            if(f)
            {
                if(odd > n[sz-i])
                    ans = sz-i;
            }
            else
                ans = sz-i, f = true;
        }
    }
    swap(n[ans], n[sz-1]);
    if(ans!=-1)
        cout<<n<<endl;
    else cout<<-1<<endl;
    return 0;
}
