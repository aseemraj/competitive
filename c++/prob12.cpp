#include<iostream>
#include<math.h>
using namespace std;
int no_of_divisors(int num)
    {
            int counter=0;
            int i=1;
            while(i<sqrt(num))
            {

                if(num%i==0)
                {

                    counter+=2;
                }
                i++;
            }
            if(i*i==num)
                counter+=1;
            return counter;
    }
int main()
{

    int j=800000000;
    while(1)
    {
        cout<<"trial "<<j-800000000<<" running \n";
        if (no_of_divisors(j)>=500)
        {
            cout<<j;
            break;
        }
        j++;
    }

    return 0;


}
