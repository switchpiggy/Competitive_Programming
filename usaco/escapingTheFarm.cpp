#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[25];

ll ans = 0;

bool valid(ll a, ll b) {
    for(; a > 0 && b > 0; a /= 10, b /= 10) {
        if(a%10 + b%10 >= 10) return false;
    }

    return true;
}

void backtrack(ll x, ll sum, ll num) {
    ans = max(ans, num);
    if(x >= n || num + n - x <= ans) return;

    if(valid(sum, a[x])) backtrack(x + 1, sum + a[x], num + 1);

    backtrack(x + 1, sum, num);

    return;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    backtrack(0, 0, 0);

    printf("%lld\n", ans);

    return 0;
}