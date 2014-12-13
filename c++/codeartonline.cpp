#include<iostream>
using namespace std;
int main()
{
    int i, j, t, r, c;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        if(r<5 || c<5)
            cout<<0<<endl;
        else
        {
            string row[r];
            for(i=0;i<r;i++)
            {
                cin>>row[i];
            }
            for(i=2;i<r-2;i++)
            {
                for(j=2;j<c-2;j++)
                {
                    row[i][j]
                }
            }

        }
    }
    return 0;
}
