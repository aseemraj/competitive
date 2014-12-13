#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)


typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }


char s[4000005];
int p[4000005];

int main(){
        scanf("%s", s);
        while ((strcmp(s,"End"))){

                        p[0] = 0;
                        int n = strlen(s);

                        int j = 0;
                        for (int i = 1; i < (int)n; i++) {
                                if (s[i] == s[j]) {
                                        p[i] = ++j;
                                }
                                else {
                                        while (j && s[i] != s[j])
                                                j = p[j-1];
                                        if (s[i] == s[j]) p[i] = ++j;
                                        else p[i] = j;
                                }
                        }




                        for(int i = 0; i < n; i++)
                                if (i)
                                        printf(" %d", p[i]);
                                else printf("%d", p[i]);
                        printf("\n");
                        scanf("%s", s);
                }
}
