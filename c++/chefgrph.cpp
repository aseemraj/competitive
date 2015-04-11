/*
Author: aseemraj
Problem: CHEFGRPH
*/

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define V(x) vector< x >
#define P(x, y) pair< x, y >
#define PI P(int, int)
#define PLL P(ll, ll)
#define VI V(int)
#define VLL V(ll)
#define VP V(PI)
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

const int MOD = 1000000007;
ll power(ll a,ll b){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%MOD;y=(y*y)%MOD;b=b>>1;}return x%MOD;}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k, sn, sm, en, em, ans=0;
    cin>>n>>m>>k;

    if(k==0)
    {
        cout<<power(m, n)<<"\n";
        return 0;
    }

    V(P(PLL, P(PLL, bool))) edge;
    P(PLL, P(PLL, bool)) E;

    loop(i, 0, k)
    {
        cin>>sn>>sm>>en>>em;
        // first element is ending layer index, second is starting layer index of the edge
        E.F.F = sn, E.F.S = sm, E.S.F.F = en, E.S.F.S = em, E.S.S = false;
        edge.PB(E);
        E.F.F = en, E.F.S = em, E.S.F.F = sn, E.S.F.S = sm, E.S.S = true;
        edge.PB(E);
    }

    int sz = edge.size();

    // sort with priority to source of layer
    sort(edge.begin(), edge.end());

    ll curl, nxtl, srcl, curn, srcn, ways, dif, val;
    // current, next, src layer; current, src node

    map<ll, ll> layer;          // answer for given layer
    map<ll, ll> node;           // answer for given node for a layer
    map<PLL, ll> layernode;     // answer for given layer and given node

    loop(i, 0, sz)      // sz = 2*k
    {
        curl = edge[i].F.F;
        curn = edge[i].F.S;
        
        // if curn is a source node
        if(edge[i].S.S == false)
        {
            // if ans for this layer exists
            if(layer.find(curl) != layer.end())
                layernode.insert(P(PLL, ll)(PLL(curl, curn), node[curl]));
            else
            {   
                if(curl == 0)
                {
                    layer.insert(PLL(curl, 1LL));
                    node.insert(PLL(curl, 1LL));
                }
                else
                {
                    val = power(m, curl-1);
                    node.insert(PLL(curl, val));
                    val = val*m % MOD;
                    layer.insert(PLL(curl, val));
                }
                layernode.insert(P(PLL, ll)(PLL(curl, curn), node[curl]));
            }
        }

        // if curn is a destination node, its layer is already computed
        else
        {
            layernode.insert(P(PLL, ll)(PLL(curl, curn), node[curl]));
 
            srcl = edge[i].S.F.F, srcn = edge[i].S.F.S;
            val = layernode[PLL(srcl,srcn)];
 
            layernode[PLL(curl, curn)] = (layernode[PLL(curl, curn)] + val) % MOD;
            layer[curl] = (layer[curl] + val) % MOD;
        }

        // now we compute ans for next tentative level
        if(i != sz-1)
        {
            nxtl = edge[i+1].F.F;
 
            if(nxtl!=curl)
            {
                // ways to reach current layer
                ways = layer[curl];
 
                if(nxtl == n+1)
                {
                    val = power(m, n-curl);
                    val = val*ways % MOD;
                    node.insert(PLL(nxtl, val));
                    layer.insert(PLL(nxtl, val));
                }
                else
                {
                    val  = power(m, nxtl-curl-1);

                    // ways to reach each node in next layer
                    val  = val*ways % MOD;
                    node.insert(PLL(nxtl, val));
 
                    val = val*m % MOD;
                    layer.insert(PLL(nxtl, val));
                }
            }
        }
    }

    // compute for last layer if not already done
    if(layer.find(n+1) == layer.end())
    {
        curl = edge[sz-1].F.F;
        ways = layer[curl];
        val = power(m, n-curl);
        val = val*ways % MOD;
        node.insert(PLL(n+1, val));
        layer.insert(PLL(n+1, val));
    }
    cout<<layer[n+1]<<"\n";
    return 0;
}