#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
using namespace std;
set <vector<int> > permute(vector<int> object)
{
    if(object.size()<=1)
    {
        set <vector<int> > res;
        res.insert(object);
        return res;
    }
    vector<int> b (object.begin()+1, object.end());
    set <vector<int> > perms = permute(b);
    int ch = object[0];
    set <vector<int> > result;
    for(set<vector<int> >::iterator j=perms.begin(); j!=perms.end(); j++)
    {
        vector<int> perm = *j;
        loop(i, 0, perm.size()+1)
        {
            vector<int> addthis (perm.begin(), perm.begin()+i);
            addthis.push_back(ch);
            addthis.insert(addthis.end(), perm.begin()+i, perm.end());
            result.insert(addthis);
        }
    }
    return result;
}
int main()
{
    int x;
    cout<<"This program lists all permutations of [1,2,3,4,...n] for a given input n.\n";
    cout<<"Provide n as input and see all permutations in lexicographical order\nInput any number less than 1 to exit\n\n";
    while(1)
    {
        cout<<"Input: ";
        cin>>x;
        vector<int> a;
        if(x<1)
            break;
        loop(i, 0, x)
            a.push_back(i+1);
        set <vector<int> > ans = permute(a);
        int c = 0;
        for(set<vector<int> >::iterator i=ans.begin();i!=ans.end();i++)
        {
            vector<int> v = *i;
            cout<<'['<<v[0];
            loop(j, 1, x)
                cout<<','<<v[j];
            cout<<"]  ";
            c++;
            if((c%13==0 && x<5) || (c%11==0 && x==5) || (c%10==0 && x==6) || (c%9==0 && x==7) || (c%5==0 && x>7))
                cout<<endl;
        }
        cout<<"\nTotal permutations: "<<ans.size()<<endl<<endl;
    }
    return 0;
}
