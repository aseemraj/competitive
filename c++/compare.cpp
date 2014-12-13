#include <iostream>
#include<string.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#define SIZE 2
using namespace std;
int main()
{
    vector <string> pages1;
    vector <string> pages2;
    FILE *fp1;
    FILE *fp2;
    int i=0, j=0, counter=0;
    char* k[SIZE] = {"1", "2"};
    for(int z1=0;z1<SIZE;z1++)
    {
        for(int z2=z1+1;z2<SIZE;z2++)
        {
            pages1.erase(pages1.begin(), pages1.end());
            pages1.erase(pages2.begin(), pages2.end());
            char filename1[256]="";
            strcat(filename1,k[z1]);
            strcat(filename1,".txt");
            fp1=fopen(filename1,"r");
            char filename2[256]="";
            strcat(filename2,k[z2]);
            strcat(filename2,".txt");
            fp2=fopen(filename2,"r");
            char c1[10240];
            char c2[10240];
            fgets(c1,10240,fp1);
            fgets(c2,10240,fp2);
            i = 0;
            string name;
            i=0;
            while(c1[i]!='$')
            {
                name = "";
                while(c1[i]!='*' and c1[i]!='$')
                {
                    name += c1[i];
                    i++;
                }
                pages1.push_back(name);
                if(c1[i]=='$')
                    break;
                else
                    i++;
            }
        //    for(i=0;i<pages1.size();i++)
        //        cout<<pages1[i];


            cout<<endl<<endl;


            i = 0;
            i=0;
            while(c2[i]!='$')
            {
                name = "";
                while(c2[i]!='*' and c2[i]!='$')
                {
                    name += c2[i];
                    i++;
                }
                pages2.push_back(name);
                if(c2[i]=='$')
                    break;
                else
                    i++;
            }
        //    for(i=0;i<pages2.size();i++)
        //        cout<<pages2[i];

            counter=0;
            for(i=0;i<pages1.size();i++)
            {
                for(j=0;j<pages2.size();j++)
                {
                    if(pages1[i]==pages2[j])
                    {
                        pages2.erase(pages2.begin()+j);
                        counter++;
                        j--;
                    }
                }
            }
            cout<<k[z1]<<" intersection "<<k[z2]<<" = "<<counter<<endl;
        }
    }
    return 0;
}
