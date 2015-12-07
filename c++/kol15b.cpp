#include <bits/stdc++.h>

using namespace std;

int mat[1010][1010];
int up[1010][1010];
int down[1010][1010];
int LEFT[1010][1010];
int RIGHT[1010][1010];
int ans;

int n,m;

void input()
{
	scanf("%d %d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}


void memoize()
{
	for(int i = 0;i < m;i++)
		up[0][i] = mat[0][i];
	for(int i = 1;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			up[i][j] = min(up[i-1][j] + mat[i][j], mat[i][j]);
		}

	}

	int i,j;
	i = n-1;
	for(j = 0;j < m;j++)
		down[i][j] = mat[i][j];
	for(i = n-2;i >= 0;i--)
	{
		for(j = 0;j < m;j++)
			down[i][j] = min(down[i+1][j] + mat[i][j], mat[i][j]);
	}

	j = 0;
	for(i = 0; i < n;i++)
		LEFT[i][j] = mat[i][j];
	for(j = 1;j < m;j++)
	{
		for(i = 0;i < n;i++)
			LEFT[i][j] = min(LEFT[i][j-1] + mat[i][j], mat[i][j]);
	}

	j = m-1;
	for(i = 0;i < n;i++)
		RIGHT[i][j] = mat[i][j];

	for(j = m-2; j>= 0;j--)
	{
		for(i = 0;i < n;i++)
			RIGHT[i][j] = min(RIGHT[i][j + 1] + mat[i][j], mat[i][j]);
	}

	ans = mat[0][0];
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
		{
			mat[i][j] = up[i][j] + down[i][j] + LEFT[i][j] + RIGHT[i][j] - (3 * mat[i][j] ) ;
			ans = min(ans,mat[i][j]);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		memoize();
	}
	return 0;
}