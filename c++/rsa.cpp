#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
#define rloop(i, a, b)  for(int i=b-1;i>=a;i--)
#define loopl(i, a, b)  for(long long i=a;i<b;i++)
#define rloopl(i, a, b)  for(long long i=b-1;i>=a;i--)
#define ll long long
using namespace std;
int gcd(int a, int b)           //recursive function to find GCD of two non-zero numbers
{
    return a%b==0?b:gcd(b, a%b);
}
int axbmodc(int a,int b,int c)  //recursive function to solve ax = b (mod c)
{
    return a?(axbmodc(c%a, (a-b % a)%a, a)*c + b)/a:0;
}
int modulo(int a,int b,int c)   //finds a^b mod c in O(lg(b)) time
{
    ll x=1,y=a;
    while(b>0)
    {
        if(b%2 == 1)
            x=(x*y)%c;
        y = (y*y)%c;
        b = b>>1;
    }
    return x%c;
}
int main()
{
    int p, q, e, ch, asc, me, d;
    string message, crypted;
    ll n;
    cout<<"This program assumes that n is a four digit number.\n";
    cout<<"Please choose p and q accordingly as the program won't be able to decrypt the cipher text otherwise\n";
    while(1)
    {
        cout<<"\nEnter 1 to encrypt, 2 to decrypt a message, 0 to exit: ";
        cin>>ch;
        if(ch==0)
            break;
        else if(ch==1)
        {
            crypted="";
            cout<<"Enter Plain Text: ";
            getline(cin, message);
            getline(cin, message);
            cout<<"Enter p, q and e separated by a space. Make sure p and q are primes and gcd((p-1)(q-1), e)=1: ";
            cin>>p>>q>>e;
            n = p*q;
            if(p&q&e==0 || modulo(2, p-1, p)!=1 || modulo(2, q-1, q)!=1 || gcd((p-1)*(q-1), e)!=1)
            {
                cout<<"Invalid combination of p, q, e. Please try again\n";
                continue;
            }
            cout<<"\nPublic Key: ("<<e<<", "<<n<<")";
            loop(i, 0, message.size())
            {
                asc = int(message[i]);
                me = modulo(asc, e, n);
                stringstream ss;
                ss<<me;
                string conc = ss.str();
                if(me==0)
                    crypted += "0000";
                else if(me!=0 && me/10==0)
                    crypted += "000" + conc;
                else if(me/10!=0 && me/100==0)
                    crypted += "00" + conc;
                else if(me/100!=0 && me/1000==0)
                    crypted += "0" + conc;
                else
                    crypted += conc;
            }
            cout<<"\nPlain Text:\t\t\t"<<message<<"\nEncrypted Cipher Text:\t\t"<<crypted<<endl;
        }
        else if(ch==2)
        {
            message = "";
            cout<<"Enter Cipher Text: ";
            getline(cin, crypted);
            getline(cin, crypted);
            cout<<"Enter known values of p, q and e separated by a space: ";
            cin>>p>>q>>e;
            n = p*q;
            if(p&q&e==0 || modulo(2, p-1, p)!=1 || modulo(2, q-1, q)!=1 || gcd((p-1)*(q-1), e)!=1)
            {
                cout<<"Invalid combination of p, q, e. Please try again\n";
                continue;
            }
            d = axbmodc(e, 1, (p-1)*(q-1));
            cout<<"\nPrivate Key: ("<<d<<", "<<n<<")";
            loop(i, 0, crypted.size()-3)
            {
                asc = int(crypted[i]-48)*1000 + int(crypted[i+1]-48)*100 + int(crypted[i+2]-48)*10 + int(crypted[i+3]-48);
                me = modulo(asc, d, n);
                message += char(me);
                i+=3;
            }
            cout<<"\nCipher Text:\t\t\t"<<crypted<<"\nDecrypted Plain Text:\t\t"<<message<<endl;
        }
    }
    return 0;
}
