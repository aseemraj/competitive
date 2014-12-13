#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define rloop(i, a, b) for(int i=b-1;i>=a;i--)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t, c, len, ans;
    cin>>t;
    string s;
    while(t--)
    {
        ans = 0;
        c = 0;
        cin>>s;
        len = s.size();
        loop(i, 0, len)
        {
            if(s[i]=='<')
                c++;
            else
            {
                c--;
                if(c==0)
                    ans = max(ans, i+1);
                else if(c<0) break;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
