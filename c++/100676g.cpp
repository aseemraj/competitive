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

struct Compare
{
    bool operator() (PI &a, PI &b)
    {
        if(a.F == b.F)
        {
            return minimum[a.S] > minimum[b.S];
        }
        return a.F > b.F;
    }
};
priority_queue< PI, VP, Compare > pq;

bool done[20];
bool visited[20];
int adj[20][20];
int adjt[20][20];
int w[20];
int minimum[20];


map<string, int> topicNumber;

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

void fillqueue()
{
    bool go;
    loop(i, 1, n + 1)
    {
        if(visited[i])continue;
        go = true;
        loop(j, 1, n + 1)
        {
            if(i == j)continue;
            if(adj[i][j] == 1 && !done[j])
            {
                go = false;
                break;
            }
        }
        if(go)
        {
            // cout<<"done?: "<<i<<' '<<done[i]<<"\n";
            pq.push(make_pair(w[i], i));
            visited[i] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        loop(i, 0, 20)
        {
            done[i] = 0;
            visited[i] = 0;
            loop(j, 0, 20)
            {
                adj[i][j] = 0;
            }
        }

        x = 1;
        cin>>n>>m;
        for(int i =0;i < n;i++)
        {
            input2();
            w[x] = num;
            topicNumber[name] = x++;
        }

        for(int i = 0;i < m;i++)
        {
            input3();
            // cout<<n2<<"*"<<n1;
            adj[topicNumber[n2]][topicNumber[n1]] = 1;
            adjt[topicNumber[n2]][topicNumber[n1]] = 1;
        }

        loop(i, 1, n+1)
        {
            minimum[i] = 1e9;
            loop(j, 1, n+1)
            {
                if(i==j)continue;
                minimum[i] = min(minimum[i], w[j]);
            }
        }

        // cout<<"adjmat:------\n";
        // loop(i, 1, n+1)
        // {
        //     loop(j, 1, n+1)
        //         cout<<adj[i][j]<<'\t';
        //     cout<<"\n";
        // }

        fillqueue();
        ll ans = 0;
        
        int i = 1;
        while(i <= n)
        {
            PI p;
            p = pq.top();
            // cout<<"pair: "<<p.F<<' '<<p.S<<"\n";
            pq.pop();
            done[p.S] = true;
            ans += i*(p.F);
            fillqueue();
            i++;
        }
        cout<<ans<<"\n";

    }
    return 0;
}
