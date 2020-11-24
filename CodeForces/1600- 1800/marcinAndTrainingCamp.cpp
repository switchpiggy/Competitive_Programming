#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
bool taken[7007];
pair<ll, ll> p[7007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> p[i].first;
    }

    for(ll i = 0; i < n; ++i) cin >> p[i].second;

    sort(p, p + n);
    bool ok = 0;
    for(ll i = 0; i < n - 1; ++i) {
        if(p[i].first == p[i + 1].first) {
            ok = 1;
            taken[i] = taken[i + 1] = 1; 
        }
    }

    if(!ok) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 0;
    for(ll i = n - 1; i >= 0; --i) {
        if(taken[i]) {
            ans += p[i].second;
            continue;
        }
        for(ll j = i + 1; j < n; ++j) {
            if(taken[j] && (p[j].first | p[i].first) == p[j].first) {
                taken[i] = 1;
                break;
            }
        }

        if(taken[i]) ans += p[i].second;
    }

    cout << ans << '\n';
    return 0;
}