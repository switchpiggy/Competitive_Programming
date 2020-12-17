#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, l, r;
vector<ll> res;

void g(ll place, ll cnt, ll cur) {
    if(place == 18) {
        res.push_back(cur);
        return;
    }

    g(place + 1, cnt, cur * 10);

    if(cnt < 3) for(ll i = 1; i <= 9; ++i) g(place + 1, cnt + 1, cur * 10 + i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    g(0, 0, 0);
    sort(res.begin(), res.end());
    res.push_back(1000000000000000000);
    cin >> t;
    while(t--) {
        cin >> l >> r;
        cout << (upper_bound(res.begin(), res.end(), r) - res.begin()) - (lower_bound(res.begin(), res.end(), l) - res.begin()) << '\n';
    }

    return 0;
}