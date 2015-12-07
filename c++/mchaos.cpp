/*
Author: aseemraj
Problem: mchaos
*/

#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=b-1; i>=a; i--)
#define loopinc(i, a, b, inc) for(int i=a; i<b; i+=inc)
#define rloopdec(i, a, b, dec) for(int i=b-1; i>=a; i-=dec)
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

const int NMAX = 100005;
ll BIT[NMAX];
int LIM = 0;
unordered_map<ll, int> dict, d2;
string vs[NMAX], sq[NMAX];
ll vecs[NMAX], seq[NMAX];

ll read (int v)
{
    ll sum = 0;
    while(v)
    {
        sum += BIT[v];
        v -= (v &-v);
    }
    return sum;
}

void update (int v, int val)
{
    while (v <= LIM)
    {
        BIT[v] += val;
        v += (v & -v);
    }
}

void rev(string &s)
{
    char c;
    int l = s.length();
    for (int i=0; i <= l/2-1; i++)
    {
        c = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = c;
    }
}

ll hashf(string s)
{
    ll hashfValue = 0;
    int l = s.length();
    loop(i, 0, l)
        hashfValue = hashfValue * 31 + s[i] - 'a' + 1;
    for (int i = s.length(); i < 10; i++) hashfValue *= 31;
    return hashfValue;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    int N;
    memset(BIT, 0, sizeof(BIT));
    memset(vecs, 0, sizeof(vecs));
    memset(seq, 0, sizeof(seq));

    cin >> N;
    string s;

    loop(i, 0, N)
        cin>>vs[i];
    loop(i, 0, N)
    {
        vecs[i] = hashf(vs[i]);
        d2[vecs[i]] = i;
    }
    sort(vecs, vecs+N);

    loop(i, 0, N)
    {
        sq[i] = vs[d2[vecs[i]]];
        rev(sq[i]);
        seq[i] = hashf(sq[i]);
    }
    sort(seq, seq+N);

    loop(i, 0, N)
        dict[seq[i]] = i+1;
    LIM = N+1;
    ll bad_pairs = 0;
    for (int i = N-1; i >= 0; i--)
    {
        bad_pairs += read(dict[hashf(sq[i])]);
        update(dict[hashf(sq[i])], 1);
    }
    cout << bad_pairs << "\n";
    return 0;
}
