#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define init(a, b) memset(a, b, sizeof(a))
using namespace std;

int main()
{
    int t, tim1, tim2;
    float dist, dif;
    string t1, t2;
    cin>>t;
    while(t--)
    {
        cin>>t1>>t2>>dist;
        tim1 = ((t1[0]-48)*10 + t1[1]-48)*60 + (t1[3]-48)*10 + t1[4]-48;
        tim2 = ((t2[0]-48)*10 + t2[1]-48)*60 + (t2[3]-48)*10 + t2[4]-48;
        dif = tim1 - tim2;
        printf("%.1f ", dif + dist);
        if(dif>=2*dist)
            printf("%.1f \n", dif);
        else
            printf("%.1f \n", dif + (2*dist - dif)/2.0);
    }
    return 0;
}
