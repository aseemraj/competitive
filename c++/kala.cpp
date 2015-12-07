#include <bits/stdc++.h>

using namespace std;

int n,k;
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
    {


        cin >> n >> k;
        if(k > (n/2))
            cout << "-1\n";
        else
        {
            for(int i = 1+k;i <= n;i++)
                cout << i << " ";
            for(int i = 1;i < 1+k;i++)
                cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}
