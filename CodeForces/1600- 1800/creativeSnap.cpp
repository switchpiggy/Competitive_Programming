#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, b;
vector<ll> h;

ll getans(ll l, ll r) {
    ll lx = lower_bound(h.begin(), h.end(), l) - h.begin(), rx = upper_bound(h.begin(), h.end(), r) - h.begin();
    ll res;
    rx--;
    if(rx - lx + 1 == 0) res = a;
    else res = b * (rx - lx + 1) * (r - l + 1);

    if(l == r || !(rx - lx + 1)) return res;
    return min(res, getans(l, (l + r)/2) + getans((l + r)/2 + 1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> a >> b;
    for(ll i = 0; i < k; ++i) {
        ll q;
        cin >> q;
        h.push_back(q);
    }

    sort(h.begin(), h.end());
    cout << getans(1, (1 << n));
    return 0;
}