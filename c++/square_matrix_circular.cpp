#include <iostream>
#include <cstdlib>
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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define all(c) c.begin(), c.end()
#define range(i, n) for(i=0;i<n;i++)
using namespace std;

int main()
{
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;
    cout<<"Enter the matrix:\n";
    int m[n][n];
    int i, j, a=n;
    int b=n;
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>m[i][j];
    while(a>0 and b>0)
    {
    	i=n-a;
    	for(j=n-b;j<b;j++)
			cout<<m[i][j]<<' ';
		j--;
		b--;
		for(i=n-a+1;i<a;i++)
			cout<<m[i][j]<<' ';
		i--;
		a--;
		for(j=b-1;j>=n-b-1;j--)
			cout<<m[i][j]<<' ';
		j++;
		for(i=a-1;i>=n-a;i--)
			cout<<m[i][j]<<' ';
    }
    return 0;
}
