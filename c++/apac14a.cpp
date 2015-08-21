/*
Author: aseemraj
Problem: apac14a
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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
string glow[10] = {
    "1111110",
    "0110000",
    "1101101",
    "1111001",
    "0110011",
    "1011011",
    "1001111",
    "1110000",
    "1111111",
    "1111011"
};

vector<int> diff(string a, string b)
{
    int n = a.size();
    vector<int> v;
    loop(i, 0, n)
        if(a[i] != b[i])
            v.push_back(i);
}

string stringor(string a, string b)
{
    int n = a.size();
    string ret = a;
    loop(i, 0, n)
    {
        ret[i] = ((int)(a[i]-'0') | (int)(b[i] - '0')) + '0';
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, k, ans, cnt;
    bool f;
    cin>>t;
    loop(tt, 1, t+1)
    {
        cin>>n;
        string state[n];
        cnt = 0;
        loop(i, 0, n)cin>>state[i];
        loop(i, 0, 10)
        {
            k = i;
            f = 1;
            loop(j, 0, n)
            {
                // cout<<stringor(state[j], glow[k])<<"\n";
                
                stringor(state[j], glow[k]);
                if(stringor(state[j], glow[k]) == glow[k])
                {
                    k--;
                    if(k<0)k=9;
                }
                else
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                cnt++;
                ans = i;
            }
        }
        cout<<"Case #"<<tt<<": ";
        if(cnt!=1)cout<<"ERROR!\n";
        else
        {
            k = ans;
            vector<int> result, v;
            loop(i, 0, n)
            {
                v = diff(glow[k], state[i]);
                result.insert(result.end(), v.begin(), v.end());
                k--;
                if(k<0)k=9;
            }
            sort(result.begin(), result.end());
            string nextDisplay = glow[k];
            loop(i, 0, result.size())
            {
                if(glow[k][result[i]] == '1')
                {
                    nextDisplay[result[i]] = '0';
                }
            }
            cout<<nextDisplay<<"\n";
        }
    }
    
    return 0;
}
