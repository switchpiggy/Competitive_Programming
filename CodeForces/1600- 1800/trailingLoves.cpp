#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, b;
vector<pair<ll, ll>> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    ll bb = b;
    for(ll i = 2; i * i <= bb; ++i) {
        if(bb%i == 0) {
            ll cur = 0;
            while(bb%i == 0) {
                cur++;
                bb /= i;
            }

            p.push_back({i, cur});
        }
    }

    if(bb > 1) p.push_back({bb, 1});

    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < (ll)p.size(); ++i) {
        ll nn = n, res = 0;
        while(nn) {
            res += nn/p[i].first;
            nn /= p[i].first;
        }

        ans = min(ans, res/p[i].second);
    }

    cout << ans << '\n';
    return 0;
}