#include<iostream>
#include<algorithm>
using namespace std;
int triangle[100][100];
int result[100][100];
int main()
{
    int lines;
    int t;
    cin>>t;
    int finalresult[t];
    for(int k=0; k < t; k++)
    {
        cin>>lines;
        for(int i=0; i<lines; i++)
            for(int j=0; j<=i; j++)
                cin>>triangle[i][j];
        result[0][0] = triangle[0][0];
        for(int i=1; i< lines; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(i!=j and j!=0)
                    result[i][j] = max(result[i-1][j-1] + triangle[i][j] , result[i-1][j] + triangle[i][j]);
                else if (j == 0)
                    result[i][j] = triangle[i][j] + result[i-1][j];
                else
                    result[i][j] = triangle[i][j] + result[i-1][j-1];
            }
        }
        int max= 0;
        for(int i=0; i<lines;i++)
        {
            if(result[lines-1][i] > max )
                max = result[lines-1][i];
        }
        finalresult[k] = max;
    }
    cout<<endl;
    for(int i=0; i<t; i++)
        cout<<finalresult[i]<<endl;
}
