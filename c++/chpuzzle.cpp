/*
Author: aseemraj
Problem: CHPUZZLE
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
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int w, h;
int fig[1005][1005];
bool taken[1000005];
int mxx[1000005] = {0};
int myy[1000005] = {0};

PI check(V(PI)::iterator vs, V(PI)::iterator ve);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int k, p, x, y, ans=0, mx=0, my=0;
    cin>>h>>w>>k;
    P(PI, V(PI)) piece[k];
    loop(i, 0, k)
    {
        cin>>p;
        V(PI) v;
        loop(j, 0, p)
        {
            cin>>x>>y;
            v.PB(PI(x, y));
            mxx[i] = max(mxx[i], x);
            myy[i] = max(myy[i], y);
        }
        sort(v.begin(), v.end());
        piece[i] = P(PI, V(PI))(PI(p, i+1), v);
    }

    if(k<4000)
    {
        sort(piece, piece+k);
        rloop(i, 0, k)
        {
            V(PI) v = piece[i].S;
            int sz = piece[i].F.F;
            PI pos = check(v.begin(), v.end());
            if(pos.F !=-1)
            {
                loop(j, 0, sz)
                {
                    fig[pos.F+v[j].F][pos.S+v[j].S] = piece[i].F.S;
                }
            }
        }
    }
    else
    {
        loop(i, 0, k)
        {
            V(PI) v = piece[i].S;
            int sz = v.size();
            if(mx + mxx[i] > h)continue;
            taken[i] = 1;
            loop(j, 0, sz)
            {
                fig[v[j].F+mx][v[j].S] = piece[i].F.S;
                my = max(my, v[j].S);
            }
            mx += mxx[i];
        }
        
        loop(i, 0, k)
        {
            if(taken[i]){continue;}
            V(PI) v = piece[i].S;
            int sz = v.size();
            if(my + myy[i] > w)continue;
            taken[i] = 1;
            loop(j, 0, sz)
            {
                fig[v[j].F][v[j].S+my] = piece[i].F.S;
            }
            my += myy[i];
        }
    }

    loop(i, 1, h+1)
    {
        loop(j, 1, w+1)
            cout<<fig[i][j]<<' ';
        cout<<"\n";
    }
    return 0;
}


PI check(V(PI)::iterator vs, V(PI)::iterator ve)
{
    bool f = 1;
    rloop(i, 0, h)
    {
        rloop(j, 0, w)
        {
            for(V(PI)::iterator l = vs; l!= ve; l++)
            {
                if(i+(*l).F>h || j+(*l).S>w){f=0;break;}
                if(fig[i+(*l).F][j+(*l).S]){f=0;break;}
            }
            if(f)
                return PI(i, j);
            f = 1;
        }
    }
    return PI(-1, -1);
}