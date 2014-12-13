#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
bool prime[100001];
vector<int> graph[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    loop(i, 0, 10000)
        prime[i] = true;
    int k;
    loop(i, 2, 100)
    {
        if(prime[i].second)
        {
            temp = prime[i].first;
            k = 2*temp;
            while(k<10000)
            {
                prime[k] = false;
                k += temp;
            }
        }
    }
    k = 1000;
    loop(i, 1000, 100000)
    {
        if(prime[i])
        {
            loop(j, 0, 4)
            {
                loop(m, 0, 9)
                {
                    if(m!=i/k)
                    {
                        if(prime[m*1000 + (i%1000)]);
                    }
                }
            }
            graph.push_back(i);
        }
    }
    int t, p1, p2;
    while(t--)
    {
        cin>>p1>>p2;

    }
    return 0;
}
