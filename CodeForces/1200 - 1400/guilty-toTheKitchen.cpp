#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
double n, v, b[27], a[27];

int main() {
    scanf("%lf %lf", &n, &v);
    for(ll i = 0; i < n; ++i) scanf("%lf", &a[i]);
    for(ll i = 0; i < n; ++i) scanf("%lf", &b[i]);

    double maxn = INT_MAX, sum = 0;

    for(ll i = 0; i < n; ++i) {
        sum += a[i];
        maxn = min(maxn, b[i]/a[i]);
    }

    sum *= maxn;

    printf("%lf\n", min(sum, v));

    return 0;
}