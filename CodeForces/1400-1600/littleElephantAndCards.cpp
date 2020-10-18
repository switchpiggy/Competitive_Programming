#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<ll, ll> front;
map<ll, ll> back;
map<ll, bool> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;

        front[a]++;
        if(a != b) back[b]++;
        occ[a] = occ[b] = 1;
    }

    ll ans = INT_MAX;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        if(front[i->first] + back[i->first] >= (n + 1)/2) {
            ans = min(ans, max(0ll, (n + 1)/2 - front[i->first]));
        }
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans << '\n';

    return 0;
}