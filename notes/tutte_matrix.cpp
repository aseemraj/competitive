// USED IN QUESTION: http://www.codechef.com/problems/SEAGRP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
using namespace std;
#define ABS(x) (x < 0 ? -(x) : (x))
#define EPS 0.00001
#define TRUE  1
#define FALSE 0


int GSolve(double **a,int n,double *x)
{
    int i,j,k,maxrow;
    double tmp;

    for (i=0;i<n;i++) {
        maxrow = i;
        for (j=i+1;j<n;j++) {
            if (ABS(a[i][j]) > ABS(a[i][maxrow]))
                maxrow = j;
        }
        for (k=i;k<n+1;k++) {
            tmp = a[k][i];
            a[k][i] = a[k][maxrow];
            a[k][maxrow] = tmp;
        }
        if (ABS(a[i][i]) < EPS)
            return(FALSE);
        for (j=i+1;j<n;j++) {
            for (k=n;k>=i;k--) {
                a[k][j] -= a[k][i] * a[i][j] / a[i][i];
            }
        }
    }
    for (j=n-1;j>=0;j--) {
        tmp = 0;
        for (k=j+1;k<n;k++)
            tmp += a[k][j] * x[k];
        x[j] = (a[n][j] - tmp) / a[j][j];
    }
    return(TRUE);
}
int main(int argc,char **argv)
{
    int i,t,flag[109][109];
    scanf("%d",&t);
    while(t--)
    {
        int n,m,p,u,v,j;
        scanf("%d%d",&n,&m);
        memset(flag,0,sizeof(flag));
        double **a;
        double * x;
        x=(double *)malloc((n)*sizeof(double));
        a = (double **)malloc((n+1)*sizeof(double *));
        for(i=0; i<n+1; i++)
            a[i] = (double *)malloc(n*sizeof(double));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            u--,v--;
            p=rand()%100000;
            if(u>v)swap(u,v);
            a[u][v]=p;
            a[v][u]=-1*p;
        }
        bool check=GSolve(a,n,x);
        if(check)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
