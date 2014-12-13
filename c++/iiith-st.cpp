#include <iostream>
#include <string.h>
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
#define ll long long
using namespace std;

int main()
{
    int i, j, m, c, val, k;
    string s="", code, dec, str;
    string ch;
    while(1)
    {
        getline(cin,ch);
        if(ch=="#")
        {
            s += ch;
            break;
        }
        s += ch;
    }
    i = 0;
    while(s[i]!='#')
    {
        code = "";
        dec = "";
        stack <string> ans;
        while(s[i]!='*')
            code += s[i++];
        m = code.size();
        for(j=0;j<m;j++)
        {
            if(code[j]==' ')
            {
                c = 0;
                while(code[j]==' ')
                {
                    j++;
                    c++;
                }
                if(c%2==0)
                    dec += '1';
                else
                    dec += '0';
            }
        }
        if(dec.size()%5!=0)
        {
            m = 5 - dec.size()%5;
            for(j=0;j<m;j++)
                dec += '0';
        }
        m = dec.size();
        for(j=m-1;j>=0;j-=5)
        {
            val=0;
            for(k=0;k<5;k++)
            {
                val += int(dec[j-k]-48)*(1<<k);
            }
            if(val==0 || val>26)
            {
                if(val==0)
                    ans.push(" ");
                else if(val==27)
                    ans.push("'");
                else if(val==28)
                    ans.push(",");
                else if(val==29)
                    ans.push("-");
                else if(val==30)
                    ans.push(".");
                else if(val==31)
                    ans.push("?");
            }
            else
            {
                str = "";
                str += char(val+64);
                ans.push(str);
            }
        }
        m = ans.size();
        for(j=0;j<m;j++)
        {
            cout<<ans.top();
            ans.pop();
        }
        cout<<endl;
        i++;
    }
    return 0;
}
