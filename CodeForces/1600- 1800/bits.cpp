#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r;

ll solve(ll x, ll y) {
    if(x == y) return x;
    ll cur = 1;
    while(cur * 2 <= y) cur *= 2;
    if(cur <= x) return solve(x - cur, y - cur) + cur;
    if(2 * cur - 1 <= y) return 2 * cur - 1;
    return cur - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }

    return 0;
}