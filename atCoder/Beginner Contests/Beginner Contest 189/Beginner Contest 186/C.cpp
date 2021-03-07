#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

bool ok(ll x) {
    string s = to_string(x);
    for(char i : s) if(i == '7') return 0;

    while(x) {
        if(x%8 == 7) return 0;
        x /= 8;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans += ok(i);
    }

    cout << ans << '\n';
    return 0;
}