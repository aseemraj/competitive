#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define init(a, b) memset(a, b, sizeof(a))
using namespace std;

int main()
{
    int t, n, moves;
    string order;
    cin>>t;
    while(t--)
    {
        order = "";
        moves = 0;
        cin>>n;
        int l[n+1], r[n+1];
        l[0] = 0;
        r[0] = 0;
        cin>>l[1]>>r[1];
        loop(i, 2, n+1)
        {
            cin>>l[i]>>r[i];
            moves += abs(l[i] - l[i-1]) + abs(r[i] - r[i-1]);
            while(r[i]!=r[i-1] || l[i]!=l[i-1])
            {
                if(l[i]>l[i-1] && r[i]>r[i-1])
                {
                    if(l[i-1]+1 == r[i-1])
                    {
                        order += "R+";
                        r[i-1]++;
                        loop(j, 0, min(l[i] - l[i-1], r[i] - r[i-1]))
                        {
                            order += "L+R+";
                            l[i-1]++;
                            r[i-1]++;
                        }
                    }
                }
                else if(l[i]>l[i-1] && r[i]<r[i-1])
                {
                    if(l[i-1]+1 == r[i-1])
                    {
                        order += "R-";
                        r[i-1]--;
                    }
                }
                else if(l[i]<l[i-1] && r[i]>r[i-1])
                {
                    if(l[i-1]+1 == r[i-1])
                    {
                        order += "R-";
                    }
                }
                else if(l[i]<l[i-1] && r[i]<r[i-1])
                {
                    if(l[i-1]+1 == r[i-1])
                    {
                        order += "R-";
                    }
                }
                else
                {
                    if(r[i] == r[i-1] && l[i]>l[i-1])
                        loop(j, 0, abs(l[i] - l[i-1]))
                            order += "L+";
                    else if(r[i] == r[i-1] && l[i]<l[i-1])
                        loop(j, 0, abs(l[i] - l[i-1]))
                            order += "L-";
                    else if(r[i] > r[i-1] && l[i] == l[i-1])
                        loop(j, 0, abs(r[i] - r[i-1]))
                            order += "R+";
                    else if(r[i] < r[i-1] && l[i] == l[i-1])
                        loop(j, 0, abs(r[i] - r[i-1]))
                            order += "R-";
                }
            }
        }
        cout<<moves<<endl;
    }
    return 0;
}
