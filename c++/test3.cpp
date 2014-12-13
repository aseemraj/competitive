#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
string isDivisible(long long A, long long B, long long C, long long D)
	{
	    long long exponenta[100001];
        long long exponentb[100001];
	    long long b = max(A, C);
        for(long long i=0;i<=100001;i++)
        {
            exponenta[i]=0;
            exponentb[i]=0;
        }
        while (A%2 == 0)
        {
            exponenta[2]++;
            A = A/2;
        }
        while (C%2 == 0)
        {
            exponentb[2]++;
            C = C/2;
        }
        exponenta[2] = B*exponenta[2];
        exponentb[2] = D*exponentb[2];

        for (long long i = 3; i <= b; i = i+2)
        {
            while (A%i == 0)
            {
                exponenta[i]++;
                A = A/i;
            }
            while (C%i == 0)
            {
                exponentb[i]++;
                C = C/i;
            }
            exponenta[i] = B*exponenta[i];
            exponentb[i] = D*exponentb[i];
        }
        if (A > 2)
            exponenta[A]++;
        if (C > 2)
            exponentb[C]++;
        for(long long i=2;i<=b;i++)
        {
            cout<<endl<<exponenta[i]<<" "<<exponentb[i]<<endl;
            if(exponenta[i]<exponentb[i])
                return "not divisible";
        }
        return "divisible";
	}
int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<isDivisible(a, b, c, d)<<endl;
    return 0;
}
