#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
struct matrix{double data[26][26];};
matrix mul(matrix a,matrix b)
{
    matrix c;
    memset(c.data, 0, sizeof(double)*676);
    loop(i, 0, 26)
        loop(j, 0, 26)
            loop(k, 0, 26)
                c.data[i][j]+=(a.data[i][k]*b.data[k][j]);
    return c;
}
matrix power(matrix mat,ll p)
{
    if(p==1)return mat;
    matrix m = power(mat,p>>1);
    matrix a = mul(m,m);
    if(p&1)return mul(a,mat);
    else return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, m;
    ll k;
    string s, f;
    matrix prob;
    double ans, temp;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>k;
        cin>>s;
        loop(i, 0, 26)loop(j, 0, 26)cin>>prob.data[i][j];
        prob = power(prob, k);
        map<string, bool> done;
        while(n--)
        {
            cin>>f;
            if(done[f])continue;
            temp = 1;
            m = f.size();
            if(s.size()==m)
            {
                loop(i, 0, m)
                {
                    temp*=prob.data[s[i]-97][f[i]-97];
                }
                ans+=temp;
                done[f] = true;
            }
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
