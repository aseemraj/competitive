/*
Author: aseemraj
Problem: 100676g
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define ALL(c) c.begin(), c.end()
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

vector<PI> adj[20];
VP wtnode;
bool visited[20];
map<string, int> topicNumber;
int w[20];
int num, t, n, m, x;
string name;
string n1,n2;

void input2()
{
    string temp;
    name = "";
    while(1)
    {
        cin >> temp;
        if(temp[0] >= '0' && temp[0] <= '9' )
            break;
        //cout << temp << " ";
        name += temp;
        name += " ";
    }
    num = 0;
    for(int i = 0;i < temp.length();i++)
    {
        num = num*10 + (int)(temp[i]-'0');
    }
    name.resize(name.length() -1);
    // cout << name << " " <<  num << " done " << endl;
}

void input3()
{
    string temp;
    n1 = "";
    n2 = "";
    while(1)
    {
        cin >> temp;
        if(temp[0] == '-')
        {
            break;
        }
        n1 += temp;
        n1 += " ";
    }
    n1.resize(n1.length() -1);
    getline(cin,n2);
    n2 = n2.substr(1, n2.length()-1);
    // cout << n1 << "  * * " << n2 << endl;
}

void toposort(int v, list<int> &s)
{
    visited[v] = true;
    for(VP::iterator i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[(*i).S])
            toposort((*i).S, s);
    s.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        loop(i, 0, 20)
        {
            adj[i].clear();
            visited[i] = 0;
        }

        x = 1;
        cin>>n>>m;
        loop(i, 0, n)
        {
            input2();
            wtnode.PB(make_pair(num, x));
            w[x] = num;
            topicNumber[name] = x++;
        }

        loop(i, 0, m)
        {
            input3();
            adj[topicNumber[n1]].PB(make_pair(w[topicNumber[n2]], topicNumber[n2]));

        }

        sort(ALL(wtnode));
        loop(i, 1, n+1)sort(ALL(adj[i]), greater<PI>());

        list<int> s;
        loop(i, 0, n)
        {
            int u = wtnode[i].S;
            if(!visited[u])
                toposort(u, s);
        }

        ll ans = 0;
        int i = 1;
        cout<<"\n---------------- testing ----------------\n";
        while(!s.empty())
        {
            cout<<"v: "<<s.back()<<"\n";
            ans += w[s.back()] * i;
            s.pop_back();
            i++;
        }
        cout<<"---------------- testing ----------------\n\n";
        cout<<ans<<"\n";
    }
    
    return 0;
}
