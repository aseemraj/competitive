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

using namespace std;

int prec(char x);
int main()
{
    string exp;
    int to_out;
    vector <char> out;
    vector <char> op_stack;

    cout<<"Enter something to calculate: ";
    cin>>exp;

    for(int i=0;i<exp.size();i++)
    {
        to_out = 0;
        for(int j=i;exp[j]>='0' && exp[j]<='9';j++)
        {
            to_out += (int)
        }
    }

    return 0;
}

int prec(char x)
{
    if(x=='+' or x=='-')
        return 0;
    else if(x=='*' or x=='/' or x=='%')
        return 1;
    else if(x=='^')
        return 2;
    else
        return -1;
}
