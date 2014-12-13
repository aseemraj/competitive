//(c) Aseem Raj.
//(Code to find permutations of a string in dictionary sorted order)
#include<bits/stdc++.h>
using namespace std;

set <string> permute(string object)
{
    if(object.size()<=1)
    {
        set <string> res;
        res.insert(object);
        return res;
    }
    //get all permutations of length N-1
    set <string> perms = permute(object.substr(1));
    char ch = object[0];
    set <string> result;
    string perm = "";
    //iterate over all permutations of length N-1
    for(set<string>::iterator j=perms.begin(); j!=perms.end(); j++)
    {
        perm = *j;
        //insert the character into every possible location
        for(int i=0; i<=perm.size(); i++)
        {
            string addthis = perm.substr(0, i) + ch + perm.substr(i);
            result.insert(addthis);
        }
    }
    return result;
}

int main()
{
    string x;
    while(1)
    {
        cout<<"Enter the string to permute: ";
        cin>>x;
        if(x=="exit")
            break;
        set <string> ans = permute(x);
        int c = 0;
        for(set<string>::iterator i=ans.begin();i!=ans.end();i++)
        {
            if(c==12)
            {
                cout<<endl;
                c = 0;
            }
            cout<<*i<<"  ";
            c++;
        }
        cout<<"\nTotal permutations: "<<ans.size()<<endl<<endl;
    }
    return 0;
}
