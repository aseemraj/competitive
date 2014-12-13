#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int numt[100002];
int numb[100002];

int main()
{
    int n;
    cin>>n;
    int top[n], bot[n];
    vector <int> arr;
    loop(i, 0, n)
    {
        cin>>top[i]>>bot[i];
        numt[top[i]]++;
        numb[bot[i]]++;
        arr.push_back(top[i]);
        if(top[i]!=bot[i])
            arr.push_back(bot[i]);
    }
    sort(numt, numt+n);
    sort(numb, numb+n);
//    sort(arr.begin(), arr.end());
//    int number = arr[0];
//    int mode = number;
//    int cunt = 1;
//    int countMode = 1;
//    int sz = arr.size();
//    loop(i, 1, sz)
//    {
//        if(arr[i]==number)
//            cunt++;
//        else
//        {
//            if (cunt>countMode)
//            {
//                countMode = cunt;
//                mode = number;
//            }
//            cunt = 1;
//            number = arr[i];
//        }
//    }
    if(countMode*2<n)
        cout<<"Impossible\n";
    else
    {
        loop(i, 0, n)
        {
            if(top[i])
        }
    }
    return 0;
}
