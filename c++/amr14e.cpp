/*
Author: noobsforever
Problem: amr14e
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool nprime[100005];

void printkiwi(int a, int b)
{
    for(int i = a; i <= b; i++)
    {
        int facs = 0;
        for(int j = 1; j*j <= i; j++)
        {
            if(i%j == 0)
            {
                facs++;
                if(j != i/j)
                    facs++;
            }
        }
        if(!nprime[facs])
            cout<<i<<' ';
    }
}

void fillprimes()
{
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i < 100005; i++)
        if(!nprime[i])
            for(int j = i*2; j < 100005; j += i)
                nprime[j] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    fillprimes();
    int t, a, b, sa, sb;
    cin>>t;
    while(t--)
    {
        bool ntprime[200005]={0};
        cin>>a>>b;

        int sr = sqrt(b);
        for(int i = 2; i <= sr; i++)
        {
            if(!nprime[i])
            {
                int j = i*(a/i);
                while(j < a) j += i;
                if(j == i) j += i;
                while(j <= b)
                {
                    ntprime[j-a] = 1;
                    j += i;
                }
            }
        }

        int cnt = 0;
        for(int i = a; i <= b; i++)
        {
            if(!ntprime[i-a])
            {
                // cout<<i<<' ';
                cnt++;
            }
        }

        sa = sqrt(a);
        while(sa*sa >= a)sa--;
        sa++;
        sb = sqrt(b);
        while(sb*sb <= b)sb++;
        sb--;
        int num, pf, c;
        for(int i = sa; i <= sb; i++)
        {
            if(!ntprime[i*i - a])
            {
                continue;
            }
            pf = 0;
            num = i*i;
            for(int j = 2; j*j <= num; j++)
            {
                if(num%j == 0)
                {
                    c = 0;
                    while(num%j == 0)
                    {
                        num/=j;
                        c++;
                    }
                    pf++;
                }
                if(pf > 1)
                    break;
            }
            if(num > 1)pf++;
            // cout<<i*i<<"c: "<<c<<"\n";
            if(pf == 1 && !nprime[c+1])
            {
                // cout<<i*i<<' ';
                cnt++;
            }
        }
        // printkiwi(a, b);

        cout<<cnt<<"\n";
    }
    return 0;
}
