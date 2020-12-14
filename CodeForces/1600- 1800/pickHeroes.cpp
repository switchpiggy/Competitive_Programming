#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[2007];
vector<pair<ll, ll>> v;
bool paired[2007];
ll t;

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= 2 * n; ++i) cin >> p[i];
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        paired[a] = paired[b] = 1;
    }
    cin >> t;

    if(t == 1) {
        ll usedPair = 0;
        for(ll turn = 1; turn <= n; ++turn) {
            if(usedPair == (ll)v.size()) {
                ll cur = 1;
                for(ll i = 1; i <= 2 * n; ++i) if(p[i] > p[cur]) cur = i;
                cout << cur << endl;
                ll q;
                cin >> q;
                p[cur] = p[q] = -1;
            } else {
                cout << (p[v[usedPair].first] >= p[v[usedPair].second] ? v[usedPair].first : v[usedPair].second) << endl;
                ll q;
                cin >> q;
                p[v[usedPair].first] = p[v[usedPair].second] = -1;
                usedPair++;
            }
        }
    } else {
        ll pairs = 0;
        for(ll turn = 1; turn <= n; ++turn) {
            ll q;
            cin >> q;
            if(paired[q] && p[q] != -1) {
                pairs++;
                ll cur = 1;
                for(ll i = 0; i < (ll)v.size(); ++i) {
                    if(v[i].first == q) {
                        cur = v[i].second;
                        break;
                    } else if(v[i].second == q) {
                        cur = v[i].first;
                        break;
                    }
                }

                p[q] = p[cur] = -1;
                cout << cur << endl;
            } else {
                p[q] = -1;
                if(pairs == (ll)v.size()) {
                    ll cur = 1;
                    for(ll i = 1; i <= 2 * n; ++i) if(p[i] > p[cur] && p[i] != -1) cur = i;
                    cout << cur << endl;
                    p[cur] = -1;
                } else {
                    pairs++;
                    for(ll i = 0; i < (ll)v.size(); ++i) {
                        if(p[v[i].first] != -1 && p[v[i].second] != -1) {
                            cout << (p[v[i].first] >= p[v[i].second] ? v[i].first : v[i].second) << endl;
                            p[v[i].second] = p[v[i].first] = -1;
                            break;
                        }
                    }
                }
            }

        }
    }

    return 0;
}