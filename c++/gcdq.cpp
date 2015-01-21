#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int a[100005];
int lgcd[100005], rgcd[100005];
int gcd(int a, int b){if(a==0||b==0)return max(a,b);int c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, q, l, r;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        loop(i, 0, n)cin>>a[i];
        lgcd[0] = rgcd[n] = 0;
        loop(i, 0, n)
        {
            lgcd[i+1] = gcd(lgcd[i], a[i]);
            rgcd[n-1-i] = gcd(rgcd[n-i], a[n-1-i]);
        }
        while(q--)
        {
            cin>>l>>r;
            cout<<gcd(lgcd[l-1], rgcd[r])<<endl;
        }
    }
    return 0;
}
