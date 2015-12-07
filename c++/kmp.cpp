#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 100005;
const int ALPHA = 256;

int dfa[MAXM][ALPHA];

bool kmpmatch(char* pat)
{
	bool f = 0;
	int m = strlen(pat);
	memset(dfa, -1, sizeof dfa);

	// fill transitions for all matches
	for(int i = 0; i < m; i++)
		dfa[i][pat[i]] = i+1;
	
	// fill non-matches for first step
	for(int i = 0; i < ALPHA; i++)
		if(dfa[0][i] == -1)
			dfa[0][i] = 0;

	int x = 0;
	// fill the rest of the non-matches
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < ALPHA; j++)
			if(dfa[i][j] == -1)
				dfa[i][j] = dfa[x][j];
		
		x = dfa[x][pat[i]];
	}
	int state = 0, i = 0;
	char c;
	getchar();
	while(1)
	{
		c = getchar();
		if(c == '\n')
			break;
		// printf("Init State: %d\t\t", state);
		// printf("New Char: %c\t\t", c);
		state = dfa[state][c];
		// printf("Final State: %d\n", state);
		if(state == m)
		{
			f = 1;
			printf("%d\n", i-m+1);
		}
		i++;
	}
	return f;
}

int main()
{
	int m;
	while(1)
	{
		// printf("Input m: ");
		if(scanf("%d", &m) == EOF)
			break;
		char pat[m+1];
		// printf("Input pattern: ");
		scanf("%s", pat);
		// printf("Now the text: ");
		if(!kmpmatch(pat))
			printf("\n");
	}
	return 0;
}