#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

char str[200001],cur[200001],ans[200001];
char m[4]="RGB";
ll n, maxn = 2147483647;

int main() {
    scanf("%lld %s", &n, str);

    for(ll i = 0; i < 6; ++i) {
        ll c = 0;

        for(ll j = 0; j < n; ++j) {
            cur[j] = m[j%3];
            if(cur[j] != str[j]) c++;
        }

        if(c < maxn) {
            maxn = c;
            strcpy(ans, cur);
        }

        next_permutation(m, m + 3);
    }

    printf("%lld %s\n", maxn, ans);
}