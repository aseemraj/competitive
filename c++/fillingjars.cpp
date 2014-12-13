#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m;
    double a, b, k, aver=0, n;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>k;
        aver += (k/n)*(b-a+1);
    }
    cout<<int(aver)<<endl;
    return 0;
}
