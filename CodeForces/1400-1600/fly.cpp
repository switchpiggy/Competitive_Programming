#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
ll a[1005], b[1005];

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        if(a[i] <= 1) {
            printf("-1\n");
            return 0;
        }
    }
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &b[i]);
        if(b[i] <= 1) {
            printf("-1\n");
            return 0;
        }
    }

    double s = m;
    s += s/(a[0] - 1);
    
    for(ll i = n - 1; i >= 1; i--) {
        s += s/(a[i] - 1);
        s += s/(b[i] - 1);
    }
    
    s += s/(b[0] - 1);

    printf("%.10lf", s - m);
}