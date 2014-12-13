#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
using namespace std;
int a[100], n=1, c=0;
void display()
{
    c++; loop(i, 0, n) cout<<a[i]<<' ';
    cout<<"    ";
    if(c%4==0) cout<<endl;
}
bool permute()
{
    display();
    int k=n-2;
    while(a[k]>=a[k+1] && k>=0) k--;
    if(k==-1) return false;
    int l=n-1;
    while(a[k]>=a[l] && l>=0) l--;
    swap(a[k], a[l]);
    reverse(a+k+1, a+n);
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout<<"This program lists all permutations of [1,2,3,4,...n] for a given input n.\n";
    cout<<"Provide n as input and see all permutations in lexicographical order\nInput any number less than 1 to exit\n\n";
    while(n)
    {
        cout<<"Input: ";
        cin>>n;
        if(n<1)break;
        c = 0;
        loop(i, 0, n)
            a[i] = i+1;
        while(permute()){}
        cout<<"\nTotal Permutations: "<<c<<endl;
    }
    return 0;
}
