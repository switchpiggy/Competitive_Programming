#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<long long int ,long long int> ii;

ll n, m, v[1005];

int main() {

    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i) scanf("%d", &v[i]);

    ll ans = 0;

    for(ll i = 1; i <= m; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ans += min(v[a], v[b]);
    }

    printf("%lld", ans);

}
