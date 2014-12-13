#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define PI 3.14159265
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k;
    double score[n+1][m+1];
    int prereq[105] = {0};
    loop(i, 1, n+1)
        loop(j, 1, m+1)
            cin>>score[i][j];
    loop(i, 0, k)
    {
        cin>>a>>b;
        prereq[b] = a;
    }
    double maxscore[105][105];
    loop(i, 0, n+1)
        loop(j, 0, m+1)
            maxscore[i][j]=-1;
    loop(j, 1, m+1)
    {
        loop(i, 1, n+1)
        {
            if(prereq[i]==0)
                maxscore[i][j] = max(maxscore[i][j-1], score[i][j]);
            else
            {
                if(maxscore[prereq[i]][j-1]==-1)
                    maxscore[i][j] = -1;
                else
                {
                    if(score[i][j]==-1)
                        maxscore[i][j] = maxscore[i][j-1];
                    else
                        maxscore[i][j] = maxscore[prereq[i]][j-1] + score[i][j];
                }
            }
        }
    }
    return 0;
}
