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

int main()
{
    int t, i;
    char top;
    map <char, int> pref;
    pref['+'] = 0;
    pref['-'] = 0;
    pref['*'] = 1;
    pref['/'] = 1;
    pref['^'] = 2;
    string input, output;
    cin>>t;
    while(t--)
    {
        cin>>input;
        output = "";
        stack <char> s;
        for(i=0;i<input.length();i++)
        {
            if(input[i]=='+' or input[i]=='-' or input[i]=='*' or input[i]=='/' or input[i]=='^')
            {
                if(!s.empty())
                {
                    while(pref[s.top()]>pref[input[i]])
                    {
                        top = s.top();
                        s.pop();
                        output += top;
                        if(s.empty())
                            break;
                    }
                }
                s.push(input[i]);
            }
            else
                output += input[i];
        }
        while(!s.empty())
        {
            output += s.top();
            s.pop();
        }
        cout<<output<<endl;
    }
    return 0;
}
