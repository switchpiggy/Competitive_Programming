#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
double a[200007];

int main() {
    scanf("%lld %lld", &n, &k);
    double sum = 0;

    a[0] = 0;
    for(ll i = 1; i <= n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        a[i] = a[i - 1] + temp;
    }

    for(ll i = 1; i <= n - k + 1; ++i) {
        double cur = a[i + k - 1] - a[i - 1];
        sum += cur;
    }

    sum /= (double)(n - k + 1);

    printf("%.10lf\n", sum);

    return 0;
}