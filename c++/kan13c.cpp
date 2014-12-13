#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k;
    string s;
    cin>>s;
    while(s!="End")
    {
        n = s.size();
        int rh[n];
        memset(rh, 0, sizeof(rh));
        for(i=1;i<n;i++)
        {
            if(s[i]==s[0] && rh[i]==0)
            {
                j = 0;
                k = i;
                while(k<n && s[j]==s[k])
                {
                    rh[k] += j+1;
                    j++;
                    k++;
                }
            }
        }
        for(i=0;i<n-1;i++)
            cout<<rh[i]<<' ';
        cout<<rh[n-1]<<endl;
        cin>>s;
    }
    return 0;
}
