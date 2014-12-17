#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int c[10];
    c[0] = 2;
    c[1] = 7;
    c[2] = 2;
    c[3] = 3;
    c[4] = 3;
    c[5] = 4;
    c[6] = 2;
    c[7] = 5;
    c[8] = 1;
    c[9] = 2;
    string s;
    cin>>s;
    cout<<c[s[0]-48]*c[s[1]-48]<<endl;
    return 0;
}
