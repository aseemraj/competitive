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

pair <int, int> inoutsc(vector < pair < pair <int, int> , char> > tvect, int elem)
{
    for(vector < pair < pair <int, int>, char> >::const_iterator i = tvect.begin();i<tvect.end();i++)
    {
        if(elem>=(*i).first.first && elem<=(*i).second.second)
            return (*i).first;
    }
}

int main()
{
    int sbeg, send, tc;
    char sc;
    string tname;
    getline(cin, tname);
    while(tname!="END")
    {
        cout<<tname<<endl;
        cin>>sbeg;
        while(sbeg!=0)
        {
            cin>>send>>sc>>tc;
            vector < pair < pair <int, int> , pair <char, int> > > tmap;
            for(vector < pair < pair <int, int>, pair <char, int> > >::const_iterator i = tvect.begin();i<tvect.end();i++)
            {
                if(sbeg>=(*i).first.first && sbeg<=(*i).first.second)
                    break;
            }

            cin>>sbeg;
        }
        getline(cin, tname);
    }
    return 0;
}
