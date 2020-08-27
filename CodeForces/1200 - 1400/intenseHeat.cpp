#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
double n, k, a[5005], pr[5005];

int main() {
    scanf("%lf %lf", &n, &k);
    a[0] = 0;
    for(ll i = 1; i <= n; ++i) scanf("%lf", &a[i]);

    pr[0] = 0;
    for(ll i = 1; i <= n; ++i) pr[i] = pr[i - 1] + a[i];

    double maxn = 0;

    for(ll i = k; i <= n; ++i) {
        for(ll j = 1; j <= n - i + 1; ++j) {
            maxn = max(maxn, (double)(pr[j + i - 1] - pr[j - 1])/i);
        }
    }

    printf("%.8lf", maxn);
}