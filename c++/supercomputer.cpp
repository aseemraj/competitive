#include <bits/stdc++.h>
using namespace std;
 
#define MAXM 100000+5
#define MOD 1000000007
 
typedef long long LL;
 
int M;
LL N, INV_9;
 
LL len[MAXM];
int d[MAXM];
LL clen[MAXM], sum[MAXM];
 
LL pwr(LL x, LL n) {
    if (!n) return 1;
    LL y = pwr(x, n>>1);
    (y = y * y) %= MOD;
    if (n & 1)  (y = x * y) %= MOD;
    return y;
}
 
// Returns (10^0 + 10^1 + 10^2 + ... + 10^n)
LL csum(LL n) {
    if (n < 0) return 0;
    return ((pwr(10, n+1) - 1) * INV_9) % MOD;
}
 
// Returns (0*10^0 + 1*10^1 + 2*10^2 + ... + n*10^n)
LL cpsum(LL n) {
    if (n <= 0) return 0;
    return ((((9*n - 1) % MOD * pwr(10, n+1) + 10)) % MOD * ((INV_9 * INV_9) % MOD)) % MOD;
}
 
int main() {
    INV_9 = pwr(9, MOD-2);
    int t;
    cin>>t;
    assert(t <= 25);
 
    while(t--) {
        cin >> M;
        assert(M <= 10000);
 
        for (int i = 0; i < M; i++) {
            cin >> len[i] >> d[i];
            assert(d[i] >= 0 && d[i] <= 9);
            assert(len[i] <= (LL)1e18);
 
            clen[i] = len[i] + (i > 0 ? clen[i-1] : 0);
            sum[i] = LL(len[i]) * d[i] + (i > 0 ? sum[i-1] : 0);
        }
 
        N = clen[M-1];
        assert(N <= (LL)1e18);
 
        LL ans = sum[M-1];
        for (int j = 0; j < M; j++) {
            LL tlen = (j > 0 ? clen[j-1] : 0);
            LL k1 = (45*(N % MOD)*d[j] - 45*(tlen%MOD)*d[j] + 10*d[j]*(sum[j-1] % MOD) - 5*d[j]*d[j] - 5*d[j] + (10*d[j]*d[j] - 45*d[j]) * (N % MOD)) % MOD;
            LL k2 = (10*d[j]*d[j] - 45*d[j]) % MOD;
 
            // Add [ 1 / 10^(clen[j-1]+1) ] * [ k1 * 10^(n-i) - k2 * (n-i) * 10^(n-i) ] to the answer, for i = 1 to len[j].
            // This can be calculated in O(1) for a given 'j'.
            LL cur = 0;
            (cur += k1 * (csum(N-1) - csum(N-len[j]-1))) %= MOD;
            (cur -= k2 * (cpsum(N-1) - cpsum(N-len[j]-1))) %= MOD;
            (cur *= pwr(pwr(10, tlen+1), MOD-2)) %= MOD;
            if (cur < 0)    cur += MOD;
            (ans += cur) %= MOD;
        }
        cout << ans << endl;
 
        // #ifdef DEBUG
        // LL x = 0, dig = 0;
        // for (int i = 0; i < M; i++) {
        //     for (int j = 0; j < len[i]; j++) {
        //         x = 10*x + d[i];
        //         dig++;
        //         if (dig > 8)    break;
        //     }
        //     if (dig > 8)    break;
        // }
 
        // if (dig > 8) {
        //     cout << "Too large for brute force!";
        // } else {
        //     LL ans = 0;
        //     for (int i = 0; i <= x; i++) {
        //         LL y = i;
        //         while (y)   ans += (y%10), y /= 10;
        //     }
        //     cout << ans << endl;
        // }
        // #endif
    }
    return 0;
}