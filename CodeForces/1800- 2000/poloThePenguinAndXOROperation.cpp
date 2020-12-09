#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, res[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    iota(res, res + n + 1, 0);

    ll cur = n;
    while(cur > 0) {
        ll bit = 31 - __builtin_clz(cur);
        ll len = cur - (1 << bit) + 1;
        reverse(res + 1 + cur - 2 * len, res + cur + 1);
        cur -= 2 * len;
    }

    cout << (n * (n + 1)) << '\n';
    for(ll i = 0; i <= n; ++i) cout << res[i] << ' ';
    return 0;
}