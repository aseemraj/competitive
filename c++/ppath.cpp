#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 10005;

bool prime[MAXN];
int digit[4], dist[MAXN], parent[MAXN];

void sieve()
{
    for(int i = 2; i < MAXN; i++)
        prime[i] = true;
    for(int i=2; i < MAXN; i++)
    {
        if(prime[i])
            for(int j = i*i; j <= MAXN; j += i)
                prime[j] = false;
    }
}

int arrtonum(int a[])
{
    int ans = 0, k = 0;
    while(k<4)
        ans = ans*10 + a[k++];
    return ans;
}

void numtoarr(int a[], int num)
{
    int w=3;
    while(num)
    {
        a[w--] = num % 10;
        num /= 10;
    }
}

int main()
{
    int t, a, b;
    scanf("%d",&t);
    sieve();
    while(t--)
    {
        scanf("%d %d",&a, &b);
        memset(dist, -1, sizeof(dist));
        memset(parent,-1,sizeof(parent));
        queue<int> q;
        dist[a] = 0;
        q.push(a);
        parent[a]=0;

        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            for(int k=3; k>=0; k--)
            {
                numtoarr(digit, num);
                for(int i = 0; i <= 9; i++)
                {
                    digit[k] = i;
                    int newnum = arrtonum(digit);
                    if(prime[newnum] && dist[newnum] == -1 && newnum >= 1000)
                    {
                        dist[newnum] = dist[num] + 1;
                        parent[newnum] = num;
                        q.push(newnum);
                    }
                }
            }
        }
        if(dist[b] == -1)
            printf("Impossible\n");
        else
            printf("%d\n", dist[b]);
    }
    return 0;
}