#include<bits/stdc++.h>
#define loop(i, a, b)  for(i=a;i<b;i++)
#define rloop(i, a, b)  for(i=b-1;i>=a;i--)
#define ll unsigned long long int
using namespace std;

int mat[102][102];
int pfaffian(int mat[][102], int x1, int x2, int n)
{
    if(n == 0)
        return 1;
    int sum = 0, i, j, temp;
    loop(i, x1+1, x2+1)
    {
        temp = i&1?-1:1;
        if(mat[x1][i]!=0)
            sum += temp*mat[x1][i]*pfaffian(mat, x1+1, x2-1, n-2);
    }
    return sum;
}

int det(int n, int mat[102][102])
{
    int temp, subi, subj, c, i, j, d=0;
    int submat[102][102];
    if(n==2)
        return mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1];
    else
    {
        for(c=0;c<n;c++)
        {
            subi=0;   //submatrix's i value
            for(i=1;i<n;i++)
            {
                subj=0;
                for(j=0;j<n;j++)
                {if(j==c)
                continue;
                submat[subi][subj]=mat[i][j];
                subj++;
                }
                subi++;
            }
            temp = c&1?-1:1;
            if(mat[0][c]!=0)
                d += temp*mat[0][c]*det(n-1 ,submat);
        }
    }
    return d;
}

int main()
{
    int n, i, j;
    cin>>n;
    cout<<"Enter the matrix:\n";
    loop(i, 0, n)
    {
        loop(j, 0, n)
            cin>>mat[i][j];
    }
    if(n&1)
        cout<<"Pfaffian is = 0"<<endl;
    else
    {
        cout<<"Pfaffian is = "<<det(n, mat)<<endl;
    }
}
int det(int n, int mat[102][102])
{
    int temp, subi, subj, c, i, j, d=0;
    int submat[102][102];
    if(n==2)
        return mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1];
    else
    {
        loop(c, 0, n)
        {
            subi=0;   //submatrix's i value
            loop(i, 1, n)
            {
                subj=0;
                loop(j, 0, n)
                {
                    if(j==c)
                        continue;
                    submat[subi][subj]=mat[i][j];
                    subj++;
                }
                subi++;
            }
            temp = c&1?-1:1;
            if(mat[0][c]!=0)
                d += temp*mat[0][c]*det(n-1 ,submat);
        }
    }
    return d;
}
