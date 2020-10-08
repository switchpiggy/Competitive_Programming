#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string t;

const ll maxn = 1ll << 32;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    stack<ll> s;
    ll ans = 0;
    s.push(1);

    for(ll i = 0; i < n; ++i) {
        cin >> t;
        if(t == "end") {
            s.pop();
        } else if(t == "add") {
            ans += s.top();
        } else {
            cin >> k;
            s.push(min(k * s.top(), maxn));
        }
        //cout << ans << '\n';
    }

    if(ans >= maxn) {
        cout << "OVERFLOW!!!" << '\n';
        return 0;
    }

    cout << ans << '\n';
    return 0;
}