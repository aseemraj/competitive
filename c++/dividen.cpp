#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define PI 3.14159265
typedef long long ll;
using namespace std;
struct point
{
    double x;
    double y;
};
double dist2(point p1, point p2){return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);}
int main()
{
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(12);
    point v, r1, r2, temp;
    int n;
    cin>>v.x>>v.y>>r1.x>>r1.y>>r2.x>>r2.y;
    cin>>n;
    cout<<"YES\n";
    if(dist2(v, r2)<dist2(v, r1))
        temp = r1, r1 = r2, r2 = temp;
    if(n==1)
    {
        cout<<"Line "<<v.x<<' '<<v.y<<' '<<r1.x<<' '<<r1.y<<endl;
        cout<<"Line "<<v.x<<' '<<v.y<<' '<<r2.x<<' '<<r2.y<<endl;
    }
    else if(n==2)
    {
        cout<<"Line "<<v.x<<' '<<v.y<<' '<<r1.x<<' '<<r1.y<<endl;
        cout<<"Line "<<v.x<<' '<<v.y<<' '<<r2.x<<' '<<r2.y<<endl;
        cout<<"Circle "<<v.x<<' '<<v.y<<' 'v.x<<' '<<v.y<<' '<<r1.x<<' '<<r1.y<<endl;

        cout<<"Line "<<r1.x<<' '<<r1.y<<' '<<;
        cout<<"Circle "<<v.x<<' '<<v.y;
        cout<<"Circle "<<v.x<<' '<<v.y;
        cout<<"Line "<<v.x<<' '<<v.y;
        cout<<"Answer\n";
    }
    return 0;
}
