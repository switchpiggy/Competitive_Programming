#include <bits/stdc++.h>
using namespace std;

#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w",stdout)
#define fst first
#define snd second

typedef __int64 LL;
//typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 3000 + 5;

int N, M, K;
char buf[MAXN][15];
PII ele[MAXN];
vector<PII> res;

int main() {
#ifndef ONLINE_JUDGE
    FIN;
#endif // ONLINE_JUDGE
    while (~scanf ("%d", &N) ) {
        for (int i = 1; i <= N; i++) {
            scanf ("%s %d", buf[i], &ele[i].fst);
            ele[i].snd = i;
        }
        sort (ele + 1, ele + N + 1);
        bool suc = true;
        for (int i = 1; i <= N; i++) {
            if (ele[i].fst >= i) suc = false;
        }
        if (!suc) {
            printf ("-1\n");
            continue;
        }
        res.clear();
        for (int i = 1, k = N; i <= N; i++, k--) {
            res.insert (res.begin() + ele[i].fst, make_pair (ele[i].snd, k) );
        }
        for (int i = 0; i < N; i++) {
            PII& e = res[i];
            printf ("%s %d\n",  buf[e.fst], e.snd);
        }
    }
    return 0;
}