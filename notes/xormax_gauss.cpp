int xormax(int *a, int n)
{
    sort(a.begin(), a.end(), greater<int>());
    int sig = 1;
    while(sig<=a[0])sig<<=1;
    sig>>=1;
    for(int t=0;sig>=1;sig>>=1)
    {
        int i=t;
        while(i<n && (a[i]&sig)==0)i++;
        if(i>=n)continue;
        swap(a[t],a[i]);
        loop(j, 0, n)
            if(j!=t && (a[j]&sig)!=0)
                a[j]=a[j]^a[t];
        t++;
    }

    int res = 0;
    loop(j, 0, n)res=res^a[j];
    return res;
}
