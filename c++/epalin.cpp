/*
Author: aseemraj
Problem: epalin
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll q1,q2;
ll base = 256;

char str[100005];
long long powMod(long long num,long long p,long long P)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return num % P;
    long long ans;
    ans = powMod(num,p>>1,P);
    ans = (ans * ans) % P;
    if(p % 2 == 1)
        ans = (ans * num) % P;
    return ans;
}


int main()
{
    // ios_base::sync_with_stdio(0);
    q1 = 89939;
    q2 = 118471;
    int n;
    ll num1,num2;
    ll m, m2;
    ll inv_m;
    bool ans = 0;
    while(scanf("%s", str) != EOF)
    {
        n = str.length();
        num1 = 0;
        num2 = 0;
        for(int i = 0;i < n;i++)
        {   
            num1 = (num1 * base + (ll)str[i])%q1;
        }
        for(int i = n-1;i >= 0;i--)
        {
            num2 = (num2 * base + (ll)str[i])%q1;
        }
        m = powMod(base, n - 1, q1);
        inv_m = powMod(base, q1 - 2, q1);
        m2 = 1;
        int i;
        // printf("%lld %lld\n", m,inv_m);
        for(i = 0;i < n;i++)
        {
            ans = 0;
            if(num1 == num2)
            {
                //check character by character
                ans = 1;
                int k = 0;
                for(int j = i;j < n;j++)
                {
                    if(str[j] != str[n - 1 - k])
                    {
                        ans = 0;
                        break;
                    }
                    k++;
                }
            }
            if(ans == 1)
                break;
            //printf("\t%d %lld %lld\n",i,num1,num2);
            num1 = num1 - (((ll)str[i] * m ) % q1);
            while(num1 < 0)
                num1 += q1;
            num2 = num2  - (((ll)str[i] ) % q1);
            while(num2 < 0)
                num2 += q1;
            num2 = num2*inv_m % q1;
            m2 = (m2 * base)%q1;
            m = m * inv_m;
        }
        //printf("%d\n",i);
        for(int I = 0;I < i;I++)
            cout<<str[I];
            // printf("%c",str[I]);
        for(int I = i;I < n;I++)    
            cout<<str[I];
            // printf("%c",str[I]);
        for(int I = i - 1;I >= 0;I--)
            cout<<str[I];
            // printf("%c",str[I]);
        cout<<"\n";
        // printf("\n");
    }
    return 0;
}
