int modulo(int a,int b,int c){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%c;y=(y*y)%c;b=b>>1;}return x%c;}
